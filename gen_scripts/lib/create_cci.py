import CppHeaderParser
from jinja2 import Environment, Template, PackageLoader, select_autoescape
import os
import copy
from .cci_helpers import cci_sanitize_rettype, cci_sanitize_func_name, cci_get_output_arguments


class CciGenerator():
    
    def __init__(self, definition):
        self.stripped_cci_class_name = definition.cci_class_name[:-4]
        self.wrapper_class_name = "Ctre" + self.stripped_cci_class_name + "Wrapper"
        self.cci_prefix = definition.cci_prefix
        self.cci_class_name = definition.cci_class_name
        self.getter_overrides = definition.cci_getter_overrides
        self.overriden_function_bodies = definition.cci_overriden_function_bodies
        self.wrapper_type = definition.cci_wrapper_type
        self.conversion_function = definition.cci_conversion_function
    
    def __dump_func_contents(self, func):
        is_getter = cci_get_output_arguments(func, self.getter_overrides)
        template = """{
    {{ conversion_function }}(handle)->{{ callback_name }}({% for arg in args if arg.name != "handle" and arg.name != "timeoutMs" %}{{arg.name}}{{ ", " if not loop.last }}{% endfor %});{% if return_type == "ctre::phoenix::ErrorCode" %}
    return (ctre::phoenix::ErrorCode)0;{% endif %}
}"""
        
        return Template(template).render(callback_name=cci_sanitize_func_name(self.cci_prefix, func['name']), 
                                         return_type=cci_sanitize_rettype(func['rtnType']),
                                         conversion_function=self.conversion_function,
                                         stripped_cci_class_name=self.stripped_cci_class_name,
                                         wrapper_class_name=self.wrapper_class_name,
                                         wrapper_type=self.wrapper_type,
                                         args=func['parameters'])
    
    
    def generate(self, cci_header_file, output_file, template_file):
        
        with open(template_file) as f:
            template_text = f.read()
        
        parsed_header = CppHeaderParser.CppHeader(cci_header_file)
        
        output = ""
        
        jni_functions = []
        for func in parsed_header.functions:
            output += cci_sanitize_rettype(func['rtnType']) + " " + func["name"] + "("
            output += ", ".join(arg["type"] + ("" if arg["type"].endswith("*") else " ") + arg["name"] + ("[%s]" % arg['array_size'] if "array_size" in arg else "") for arg in func["parameters"])
            
            output += ")\n"
#             print(func['name'], self.overriden_function_bodies)
            if str(func['name']) in self.overriden_function_bodies:
                print("Dumping override for ", str(func['name']))
                output += Template(self.overriden_function_bodies[str(func['name'])]).render(
                    wrapper_type=self.wrapper_type,
                    conversion_function=self.conversion_function)
            else:
                output += self.__dump_func_contents(func)
            output += "\n\n"
            
        with open(output_file, 'w') as f:
            print("Writing to {}".format(output_file))
            f.write(Template(template_text).render(functions=output,
                                         stripped_cci_class_name=self.stripped_cci_class_name,
                                         wrapper_class_name=self.wrapper_class_name,
                                         cci_class_name=self.cci_class_name,
                                         conversion_function=self.conversion_function))
        
    
            
            
def main():
    
    project_dir = r'F:\git\FIRST\SnobotSim\CtreSimulator'
    cci_header_dir = os.path.join(project_dir, r'ctre_source\cci\native\include\ctre\phoenix\cci')
    cci_dump_dir = os.path.join(project_dir, r'src\main\native\cpp\ctre_cci_mocks')
    
    if not os.path.exists(cci_dump_dir):
        os.makedirs(cci_dump_dir)
    
    from generator_config_factory import generator_config_factory
    definitions = generator_config_factory()

    for definition in definitions:
    
        generator = CciGenerator(definition)
        
        generator.generate(
            os.path.join(cci_header_dir, r'%s.h' % definition.cci_class_name), 
            os.path.join(cci_dump_dir, r'%s.cpp' % definition.cci_class_name),
            os.path.join(project_dir, "gen_scripts/cci_templates/_template.txt"))
        
if __name__ == "__main__":
    main()