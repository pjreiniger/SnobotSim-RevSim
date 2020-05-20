import CppHeaderParser
from jinja2 import Environment, Template, PackageLoader, select_autoescape
import os
import copy
from .cci_helpers import cci_sanitize_rettype, cci_sanitize_func_name, cci_get_output_arguments, cci_seperate_arguments
from .utils import realign_pointer_position

WRAPPER_SETTER_TEMPLATE = """{
    RECEIVE_HELPER("{{ callback_name }}", {% for arg in args if should_include_arg(arg) %}sizeof({{ get_sizeof_buffer_arg(arg) }}){{ " + " if not loop.last }}{% endfor %});{% for arg in args if should_include_arg(arg) %}
    PoplateReceiveResults(buffer, {{ get_recv_buffer_arg(arg) }}, buffer_pos);{% endfor %}
{% for arg in slotted_things %}
    *{{arg.variable_name}} = {{get_getter_cast(arg, known_enums)}}m_slotted_variables[slotID].m_{{arg.get_name_as_sim_device()}}.Get(){{getter_end_cast(arg, known_enums)}};{% endfor %}{% for arg in normal_things %}
    *{{arg.variable_name}} = {{get_getter_cast(arg, known_enums)}}m_{{arg.get_name_as_sim_device()}}.Get(){{getter_end_cast(arg, known_enums)}};{% endfor %}
}"""

WRAPPER_GETTER_TEMPLATE = """{% raw %}{{% endraw %}{% for arg in normal_things %}
    m_{{arg.get_name_as_sim_device()}}.Set({{arg.variable_name}});{% endfor %}{% for arg in slotted_things %}
    m_slotted_variables[slotID].m_{{arg.get_name_as_sim_device()}}.Set({{arg.variable_name}});{% endfor %}

    Send("{{ callback_name }}"{% for arg in args if arg.name != "handle" and arg.name != "timeoutMs" %}, {{arg.name}}{% endfor %});
}"""


def get_recv_buffer_arg(arg):
    output = "&" if "*" not in arg['type'] else ""
    output += arg['name']

    return output

def __get_cast(arg, known_enums):
    variable_type = arg.variable_type
    if variable_type.endswith(" *"):
        variable_type = variable_type[:-2]

    print("  ", variable_type)
    if variable_type in known_enums:
        return variable_type
    elif variable_type == "uint8_t":
        return variable_type
    return None


def get_getter_cast(arg, known_enums):
    # print("GETTER CAST", arg.variable_type, known_enums)
    cast_type = __get_cast(arg, known_enums)
    if cast_type:
        print("GGXX", cast_type)
        return "static_cast<{}>(static_cast<int>(".format(cast_type)

    return ""


def getter_end_cast(arg, known_enums):
    # print("GETTER  END", arg.variable_type, known_enums)
    cast_type = __get_cast(arg, known_enums)
    if cast_type:
        print("GEXX", cast_type)
        return "))"

    return ""

def get_sizeof_buffer_arg(arg):
    output = "*" if "*" in arg['type'] else ""
    output += arg['name']

    return output


def should_include_arg(arg):
    return arg['name'] != "handle" and arg['name'] != "timeoutMs"


def is_ignored_variable_name(variable_name):
    return variable_name == 'handle' or variable_name == "timeoutMs" or variable_name == "timoutMs"


def get_sim_type(variable_type):
    if variable_type.endswith(" *"):
        variable_type = variable_type[:-2]
    return "Double"


class SimDeviceVariable():
    def __init__(self, owning_function, var_dict, array_index=None):
        self.owning_function = owning_function
        self.variable_name = var_dict['name']
        self.variable_type = var_dict['type']

        if array_index:
            self.variable_name += "_" + array_index
#         self.variable_type = variable_type
#         self.variable_name = variable_name

    def __str__(self):
        return "Variable: {}".format(self.variable_name)
    
    def __gt__(self, other):
        return self.variable_name < other.variable_name
    
    def get_name_as_sim_device(self):
        return "{}_{}".format(self.owning_function, self.variable_name)
        

class FunctionVariables():
    
    SLOTTED_NAMES = ['slotID']
    
    def __init__(self, original_function_name, stripped_function_name, variables):
        self.original_function_name = original_function_name
        self.sanitized_function_name = self.__get_sanitized_function_name(stripped_function_name)
        self.is_slotted = False
        
        self.sanitized_variables = set()
        for var in variables:
            # print("****", var)
            if not is_ignored_variable_name(var['name']):
                if var['name'] in self.SLOTTED_NAMES:
                    self.is_slotted = True
                    continue

                if 'array_size' in var:
                    for i in range(int(var['array_size'])):
                        self.sanitized_variables.add(SimDeviceVariable(self.sanitized_function_name, var, str(i)))
                else:
                    self.sanitized_variables.add(SimDeviceVariable(self.sanitized_function_name, var, var.get('array_size', None)))
        pass
#         self.stripped_function = stripped_function

    def __get_sanitized_function_name(self, stripped_function_name):
        for pattern in ["Get", "Set", "Is"]:
            if stripped_function_name.startswith(pattern):
                output = stripped_function_name[len(pattern):]
                return output
        
        return stripped_function_name


    def __str__(self):
        return "FunctionVariables: {}: ({}) {}".format(self.original_function_name, self.sanitized_function_name, ",".join(str(x) for x in self.sanitized_variables))


class SimWrapperGenerator():

    def __init__(self, definition):
        self.stripped_cci_class_name = definition.get_stripped_cci_class_name()
        self.wrapper_class_name = definition.get_wrapper_class_name()
        self.cci_prefix = definition.cci_prefix
        self.cci_class_name = definition.cci_class_name
        self.getter_overrides = definition.cci_getter_overrides
        self.overriden_function_bodies = definition.cci_overriden_function_bodies
        self.has_device_id = True
        #         self.setter_template = definition.cci_setter_template
        #         self.getter_template = definition.cci_getter_template

        self.setter_template = WRAPPER_GETTER_TEMPLATE
        self.getter_template = WRAPPER_SETTER_TEMPLATE

        self.setter_keys = ['Config', 'Set']
        self.getter_keys = ['Get']

        self.known_cpp_enums = []
        self.known_cpp_enums.append('c_SparkMax_LimitDirection')
        self.known_cpp_enums.append('c_SparkMax_LimitPolarity')
        self.known_cpp_enums.append('c_SparkMax_MotorType')
        self.known_cpp_enums.append('c_SparkMax_ConfigParameter')
        self.known_cpp_enums.append('c_SparkMax_IdleMode')
        self.known_cpp_enums.append('c_SparkMax_FaultID')
        self.known_cpp_enums.append('c_SparkMax_EncoderType')
        self.known_cpp_enums.append('c_SparkMax_AnalogMode')
        self.known_cpp_enums.append('c_SparkMax_AccelStrategy')

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
        

    def __create_function_variable_lookup(self, functions, ignored_functions):
        
        function_to_variable_lookup = {}
        full_name_to_stripped_name = {}
        
        for func in functions:
            func_name = func['name']
            if func_name in ignored_functions:
                continue
            
            setter_arguments, getter_arguments = cci_seperate_arguments(func, [])
            
            stripped_name = func_name[len(self.cci_prefix):]
            function_to_variable_lookup[func_name] = FunctionVariables(func_name, stripped_name, setter_arguments + getter_arguments)
            full_name_to_stripped_name[func_name] = stripped_name
            
            stripped_variables = []
            
        normal_sim_device_variables = set()
        slotted_sim_device_variables = set()
        
            
        normal_sim_device_variables2222 = {}
        slotted_sim_device_variables2222 = {}
        
        for key in function_to_variable_lookup:
            function_def = function_to_variable_lookup[key]
            
            function_variables = []
            for variable in function_def.sanitized_variables:
                sim_device_name = variable.get_name_as_sim_device()
                sim_device_type = get_sim_type(variable.variable_type)
            
                if function_def.is_slotted:
                    slotted_sim_device_variables2222[key] = function_def
                    slotted_sim_device_variables.add((sim_device_name, sim_device_type))
                else:
                    normal_sim_device_variables2222[key] = function_def
                    normal_sim_device_variables.add((sim_device_name, sim_device_type))
                
        normal_sim_device_variables = sorted(list(normal_sim_device_variables))
        slotted_sim_device_variables = sorted(list(slotted_sim_device_variables))
            
#         print("Function Lookup")
#         print("\n".join("{:50} -> {}".format(key, function_to_variable_lookup[key]) for key in function_to_variable_lookup))
#             
#         print("Normal Variables")
#         print("  " + "\n  ".join(str(x) for x in normal_sim_device_variables))
#               
#         print("Normal Variables")
#         print("  " + "\n  ".join(str(x) for x in slotted_sim_device_variables))

        # print(function_to_variable_lookup)
        
        return full_name_to_stripped_name, function_to_variable_lookup, normal_sim_device_variables, slotted_sim_device_variables, normal_sim_device_variables2222, slotted_sim_device_variables2222 
    #         print(setter_arguments, getter_arguments)

    def __dump_func_contents(self, func, function_variable, function_to_variable_lookup, normal_sim_device_variables, slotted_sim_device_variables, normal_sim_device_variables2222, slotted_sim_device_variables2222):
        getter_arguments = cci_get_output_arguments(func, self.getter_overrides)
        template = self.getter_template if getter_arguments else self.setter_template
        
#         print(normal_sim_device_variables2222)
        normal_things = set()
        if function_variable:
            for var in function_variable.sanitized_variables:
#                 print(var.owning_function)
                for xxx in normal_sim_device_variables2222:
#                     print("--", var.owning_function, normal_sim_device_variables2222[xxx].sanitized_function_name, type(var.owning_function), type(xxx))
                    if var.owning_function == normal_sim_device_variables2222[xxx].sanitized_function_name:
                        normal_things.add(var)
#                         print("  ", xxx)
#                         print(var)
        normal_things = sorted(list(normal_things))
        
        slotted_things = set()
        if function_variable:
            for var in function_variable.sanitized_variables:
#                 print(var.owning_function)
                for xxx in slotted_sim_device_variables2222:
#                     print("--", var.owning_function, normal_sim_device_variables2222[xxx].sanitized_function_name, type(var.owning_function), type(xxx))
                    if var.owning_function == slotted_sim_device_variables2222[xxx].sanitized_function_name:
                        slotted_things.add(var)
                        # print("  SLOTEED", xxx)
                        # print(var)
        slotted_things = sorted(list(slotted_things))

        template = Template(template)
        template.globals['get_recv_buffer_arg'] = get_recv_buffer_arg
        template.globals['get_sizeof_buffer_arg'] = get_sizeof_buffer_arg
        template.globals['should_include_arg'] = should_include_arg
        template.globals['is_ignored_variable_name'] = is_ignored_variable_name
        template.globals['get_sim_type'] = get_sim_type
        template.globals['get_getter_cast'] = get_getter_cast
        template.globals['getter_end_cast'] = getter_end_cast


        return template.render(
            callback_name=cci_sanitize_func_name(self.cci_prefix, func['name']),
            return_type=cci_sanitize_rettype(func['rtnType']),
            stripped_cci_class_name=self.stripped_cci_class_name,
            wrapper_class_name=self.wrapper_class_name,
            known_enums=self.known_cpp_enums,
            args=self.__explode_arrays(func['parameters']),
                                       variable_lookup=function_variable,
                                       normal_sim_device_variables=normal_sim_device_variables,
                                       slotted_sim_device_variables=slotted_sim_device_variables,
                                       normal_things=normal_things,
                                       slotted_things=slotted_things)

    def __gen_function_header(self, func, include_class_name):
        output = ""
        output += "void "
        if include_class_name:
            output += "SnobotSim::%s::" % self.wrapper_class_name
        output += func['name'][len(self.cci_prefix):] + "("
        output += ", ".join(
            realign_pointer_position(arg) + 
            arg["name"] + ("[%s]" % arg['array_size'] if "array_size" in arg else "") for arg in func["parameters"] if arg['name'] != "handle" and arg['name'] != "timeoutMs" and arg['name'] != "timoutMs")

        output += ")"
        return output

    def __get_constructor_body(self, variables_lookup):

        template = """
    Send("Create");
"""

        return Template(template).render()

    def generate(self, cci_header_file, cpp_output_file, header_output_file,
                 cpp_template_file, header_template_file):
        
        num_slots = 6
        
        ignored_functions = []
        ignored_functions.append("c_SparkMax_Create")
        ignored_functions.append("c_SparkMax_Create_Inplace")
        ignored_functions.append("c_SparkMax_Destroy")
        ignored_functions.append("c_SparkMax_GetFirmwareVersion")
        ignored_functions.append("c_SparkMax_SafeFloat")

        parsed_header = CppHeaderParser.CppHeader(cci_header_file)

        cpp_output = ""
        header_output = ""
        member_variables = []

        full_name_to_stripped_name, function_to_variable_lookup, normal_sim_device_variables, slotted_sim_device_variables, normal_sim_device_variables2222, slotted_sim_device_variables2222 = self.__create_function_variable_lookup(parsed_header.functions, ignored_functions)
#         print(normal_sim_device_variables)
#         print("***************")
#         print(slotted_sim_device_variables)

        # print("****!!!!**")
        # print(function_to_variable_lookup)
        # print("****33333******")

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
                xxxx = None
#                     
#                 function_to_variable_lookup[func['name']]
#                 stuffff = None
                if func['name'] in full_name_to_stripped_name:

                    xxxx = function_to_variable_lookup[func['name']]
#                     
#                     print("&&&&&&&&&&&&&&", func['name'])
#                     print(xxxx)
#                     yyyy = function_to_variable_lookup[xxxx]
                cpp_output += self.__gen_function_header(func, True) + "\n"
                cpp_output += self.__dump_func_contents(func, xxxx, function_to_variable_lookup, normal_sim_device_variables, slotted_sim_device_variables, normal_sim_device_variables2222, slotted_sim_device_variables2222)

            cpp_output += "\n\n"


#         print(cpp_template_file)
#         print(header_template_file)
#         print(cpp_output_file)
#         print(header_output_file)
#         raise

        with open(cpp_template_file) as f:
            cpp_template_text = f.read()

        with open(header_template_file) as f:
            header_template_text = f.read()

        with open(cpp_output_file, 'w') as f:
            f.write(
                Template(cpp_template_text).render(
                    cpp_functions=cpp_output,
                    wrapper_class_name=self.wrapper_class_name,
                    stripped_cci_class_name=self.stripped_cci_class_name,
                    has_device_id=self.has_device_id,
                    normal_sim_device_variables=normal_sim_device_variables,
                    slotted_sim_device_variables=slotted_sim_device_variables,
                    num_slots=num_slots,
                ))

        with open(header_output_file, 'w') as f:
            f.write(
                Template(header_template_text).render(
                    header_functions=header_output,
                    wrapper_class_name=self.wrapper_class_name,
                    has_device_id=self.has_device_id,
                    cci_class_name=self.cci_class_name,
                    normal_sim_device_variables=normal_sim_device_variables,
                    slotted_sim_device_variables=slotted_sim_device_variables,
                    num_slots=num_slots
                ))
