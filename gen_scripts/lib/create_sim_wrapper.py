import CppHeaderParser
from jinja2 import Environment, Template, PackageLoader, select_autoescape
import os
import copy
from cci_helpers import cci_sanitize_rettype, cci_sanitize_func_name, cci_get_output_arguments, cci_seperate_arguments



WRAPPER_GETTER_TEMPLATE = """{% raw %}{{% endraw %}{% for arg in args if arg.name != "handle" and arg.name != "timeoutMs" %}
    m{{variable_lookup.sim_name}}_{{arg.name}}.Set({{arg.name}});{% endfor %}
    Send("REFRESH");
}"""

WRAPPER_SETTER_TEMPLATE = """{
    Send("WRITE");{% for arg in args if arg.name != "handle" and arg.name != "timeoutMs" %}
    *{{arg.name}} = m{{variable_lookup.sim_name}}_{{arg.name}}.Get();{% endfor %}
}"""


class SimWrapperGenerator():
    
    def __init__(self, definition):
        self.stripped_cci_class_name = definition.cci_class_name[:-4]
        self.wrapper_class_name = "Ctre" + self.stripped_cci_class_name + "Wrapper"
        self.cci_prefix = definition.cci_prefix
        self.getter_overrides = definition.cci_getter_overrides
        self.overriden_function_bodies = definition.cci_overriden_function_bodies
        self.has_device_id = self.wrapper_class_name != "CtreBuffTrajPointStreamWrapper"
#         self.setter_template = definition.cci_setter_template
#         self.getter_template = definition.cci_getter_template

        self.setter_template = WRAPPER_GETTER_TEMPLATE
        self.getter_template = WRAPPER_SETTER_TEMPLATE
        
        self.setter_keys = ['Config', 'Set']
        self.getter_keys = ['Get']
        
        
        type_lookup = {}
        type_lookup['int'] = "Double"
        type_lookup['double'] = "Double"
        type_lookup['bool'] = "Boolean"
        type_lookup['char'] = "Double"
        type_lookup['short'] = "Double"
        type_lookup['size_t'] = "Double"
        type_lookup['uint8_t'] = "Double"
        type_lookup['int32_t'] = "Double"
        type_lookup['uint32_t'] = "Double"
        type_lookup['ctre::phoenix::motorcontrol::MotorCommutation'] = "Double"
        type_lookup['ctre::phoenix::sensors::AbsoluteSensorRange'] = "Double"
        type_lookup['ctre::phoenix::sensors::SensorInitializationStrategy'] = "Double"
        type_lookup['ctre::phoenix::sensors::MagnetFieldStrength'] = "Double"
        type_lookup["ctre::phoenix::sensors::SensorTimeBase"] = "Double"
        type_lookup["ctre::phoenix::sensors::SensorVelocityMeasPeriod"] = "Double"
        
        self.sim_type_lookup = type_lookup
        

    def __explode_arrays(self, args):
        new_args = []
        
        for arg in args:
            if "array_size" in arg:
                for i in range(int(arg['array_size'])):
                    array_arg = {}
                    array_arg['name'] = arg['name'] + '[%s]' % i
                    array_arg['type'] = arg['type']
                    new_args.append(array_arg)
            else:
                new_args.append(arg)
        
        return new_args
        
    def __dump_func_contents(self, func, variable_lookup):
        getter_arguments = cci_get_output_arguments(func, self.getter_overrides)
        template = self.getter_template if getter_arguments else self.setter_template
        
        return Template(template).render(callback_name=cci_sanitize_func_name(self.cci_prefix, func['name']), 
                                         return_type=cci_sanitize_rettype(func['rtnType']),
                                         stripped_cci_class_name=self.stripped_cci_class_name,
                                         wrapper_class_name=self.wrapper_class_name,
#                                          wrapper_type=self.wrapper_type,
                                         args=self.__explode_arrays(func['parameters']),
                                         variable_lookup=variable_lookup.get(func['name'], {'sim_name': "UNKNOWN"}))
    
    def __gen_function_header(self, func, include_class_name):
        output = ""
        output += "void "
        if include_class_name:
            output += "SnobotSim::%s::" % self.wrapper_class_name
        output += func['name'][len(self.cci_prefix):] + "("
        output += ", ".join(arg["type"] + ("" if arg["type"].endswith("*") else " ") + arg["name"] + ("[%s]" % arg['array_size'] if "array_size" in arg else "") for arg in func["parameters"] if arg['name'] != "handle" and arg['name'] != "timeoutMs")
         
        output += ")"
        return output
    
    def __load_variable_mapping(self, functions):
        
        class VariableInfo:
            def __init__(self, sim_name, func, explode_arrays):
                self.sim_name = sim_name
                
                self.args = []
                for arg in explode_arrays(func['parameters']):
                    if arg['type'] != "void *" and arg['name'] != "timeoutMs":
                        self.args.append(arg)
                
        
        variables = {}
        
        for func in functions:
            setter_arguments, getter_arguments = cci_seperate_arguments(func, self.getter_overrides)
#             print(func['name'])
#             print("  ", ','.join(arg['name'] for arg in setter_arguments))
#             print("  ", ','.join(arg['name'] for arg in getter_arguments))
            sanitized_func_name = func['name'][len(self.cci_prefix):]
            sim_name = None
            for setter_pattern in self.setter_keys:
                if sanitized_func_name.startswith(setter_pattern):
                    sim_name = sanitized_func_name[len(setter_pattern):]
                    break
                
            for getter_pattern in self.getter_keys:
                if sanitized_func_name.startswith(getter_pattern):
                    sim_name = sanitized_func_name[len(getter_pattern):]
                    break
            
            if sim_name:
                variables[func['name']] = VariableInfo(sim_name, func, self.__explode_arrays)
                
                
        return variables
            
    
    def format_variables_for_header(self, variables_lookup):
        
        
        output = ""
        for variable_info in variables_lookup.values():
            for arg in variable_info.args:
                type = arg['type']
                type = type.replace('*', '').replace("const", "").strip()
                default_value = "__%s__" % type
                output += "    hal::Sim{:10} m{}_{};\n".format(self.sim_type_lookup[type], variable_info.sim_name, arg['name'])
            output += "\n"
        
        
        
        return output
    
    
    def __get_constructor_body(self, variables_lookup):
        
        variables = set()
        
        for variable_info in variables_lookup.values():
            for arg in variable_info.args:
                type = arg['type']
                type = type.replace('*', '').replace("const", "").strip()
                default_value = "__%s__" % type
                variables.add((self.sim_type_lookup[type], "m{}_{}".format(variable_info.sim_name, arg['name']), arg['name']))
        
        
        template = """
    if(m_simDevice)
    {
    {% for arg in variables %}
        {{arg[1]}} = m_simDevice.Create{{arg[0]}}("{{arg[1]}}", false, 0);{% endfor %}
    }
    else
    {
        std::cout << "UH OH" << std::endl;
    }
    
    Send("Create");
"""

        return Template(template).render(variables=sorted(variables, key=lambda x: x[1]))
        
    
    def generate(self, cci_header_file, cpp_output_file, header_output_file, cpp_template_file, header_template_file):
        
        
        parsed_header = CppHeaderParser.CppHeader(cci_header_file)
        
        cpp_output = ""
        header_output = ""
        member_variables = []
        
        variable_lookup = self.__load_variable_mapping(parsed_header.functions)
        
        for func in parsed_header.functions:
#             print(func['name'], self.cci_prefix + "Create")
            if str(func['name']) in self.overriden_function_bodies:
                continue
            elif self.cci_prefix + "Create" in str(func['name']):
                continue
            elif self.cci_prefix + "Destroy" in str(func['name']):
                continue
            else:
                header_output += "    " + self.__gen_function_header(func, False) + ";\n"
                cpp_output += self.__gen_function_header(func, True) + "\n"
                cpp_output += self.__dump_func_contents(func, variable_lookup)
                
            cpp_output += "\n\n"
            
        with open(cpp_template_file) as f:
            cpp_template_text = f.read()
            
        with open(header_template_file) as f:
            header_template_text = f.read()
            
        with open(cpp_output_file, 'w') as f:
            f.write(Template(cpp_template_text).render(cpp_functions=cpp_output, 
                                                       wrapper_class_name=self.wrapper_class_name, 
                                                       stripped_cci_class_name=self.stripped_cci_class_name,
                                                       has_device_id=self.has_device_id,
                                                       constructor_body=self.__get_constructor_body(variable_lookup)))
            
        with open(header_output_file, 'w') as f:
            f.write(Template(header_template_text).render(header_functions=header_output,
                                                           wrapper_class_name=self.wrapper_class_name,
                                                           has_device_id=self.has_device_id,
                                                           member_variables=self.format_variables_for_header(variable_lookup)))
        
    
            
            
def main():
    
    project_dir = r'F:\git\FIRST\SnobotSim\CtreSimulator'
    cci_header_dir = os.path.join(project_dir, r'ctre_source\cci\native\include\ctre\phoenix\cci')
    src_dump_dir = os.path.join(project_dir, r'src\main\native\cpp\CtreSimMocks')
    inc_dump_dir = os.path.join(project_dir, r'src\main\native\include/CtreSimMocks')
    
    if not os.path.exists(src_dump_dir):
        os.makedirs(src_dump_dir)
    
    if not os.path.exists(inc_dump_dir):
        os.makedirs(inc_dump_dir)
    
    from generator_config_factory import generator_config_factory
    definitions = generator_config_factory()

    for definition in definitions:
    
        generator = SimWrapperGenerator(definition)
        print("XXX", definition.cci_class_name[:-4])
        generator.generate(
            os.path.join(cci_header_dir, r'%s.h' % definition.cci_class_name), 
            os.path.join(src_dump_dir, r'Ctre%sWrapper.cpp' % definition.cci_class_name[:-4]),
            os.path.join(inc_dump_dir, r'Ctre%sWrapper.h' % definition.cci_class_name[:-4]),
            os.path.join(project_dir, "gen_scripts/wrapper_templates/_cpp_template.txt"),
            os.path.join(project_dir, "gen_scripts/wrapper_templates/_header_template.txt"))
        
if __name__ == "__main__":
    main()