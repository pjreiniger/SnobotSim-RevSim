from __future__ import print_function
import os
import re
import collections


class CciFunctionDef:
    def __init__(self, rettype, func_name, args):
        self.rettype = rettype
        self.func_name = func_name
        self.args = args

class JniFunctionDef:
    def __init__(self, comment, rettype, func_name, args):
        self.comment = comment
        self.rettype = rettype
        self.func_name = func_name
        self.args = args


def parse_cci_args(function_text):
    rettype, func_name, arg_str = re.findall(r"(.*?) (.*)\((.*)\)", function_text)[0]
    
#     print("Parsing '" + function_text + "'")
    arg_parts = arg_str.split(",")
    args = []
    for arg_pair in arg_parts:
        arg_pair = arg_pair.strip()
        if arg_pair == "c_SparkMax_handle":
            t, n = "c_SparkMax_handle", "handle"
        else:
            t, n = arg_pair.strip().split(" ")
        args.append((t, n))
        
    return CciFunctionDef(rettype, func_name, args)


def parse_jni_args(function_text, comments):
    ret_code, func_name, arg_str = re.findall(r"JNIEXPORT (.*?) JNICALL (.*)\((.*)\)", function_text)[0]
    ret_code, func_name, arg_str = ret_code.strip(), func_name.strip(), arg_str.strip()
    
    arg_parts = arg_str.split(",")
    args = []
    for arg_pair in arg_parts:
        arg_pair = arg_pair.strip()
        args.append(arg_pair)
        
    return JniFunctionDef(comments, ret_code, func_name, args)


def parse_cci_file(cci_file):
    output = collections.OrderedDict()
    with open(cci_file, 'r') as f:
        lines_iter = iter(f.readlines())
        try:
            while True:
                line = next(lines_iter).strip()
                if not (line.startswith("c_SparkMax_handle") or line.startswith("c_SparkMax_ErrorCode")):
                    continue
                function_text = line
                while not line.endswith(");"):
                    line = next(lines_iter).strip()
                    function_text += " " + line
                cci_def = parse_cci_args(function_text)
                output[cci_def.func_name] = cci_def
        except StopIteration:
            pass
    
    return output


def parse_jni_file(jni_file):
    output = []
    with open(jni_file, 'r') as f:
        lines_iter = iter(f.readlines())
        try:
            while True:
                line = next(lines_iter).strip()
                comment_text = ""
                if line == "/*":
                    comment_text += line + "\n"
                    comment_text += next(lines_iter)
                    comment_text += next(lines_iter)
                    comment_text += next(lines_iter)
                    comment_text += next(lines_iter)
                    
#                     function_text = "XXXX"
                    function_text = next(lines_iter).strip()
                    function_text += next(lines_iter).strip()
                    jni_def = parse_jni_args(function_text, comment_text)
                    
                    output.append(jni_def)
                    
        except StopIteration:
            pass
        print("After")
    
    return output


def dump_known_function(jni_def, cci_function):
    
    if len(jni_def.args) - 2 != len(cci_function.args):
#         print("UH OH", len(jni_def.args), len(cci_function.args))
        return dump_unknown_function(jni_def)
    
#     print("Good")
    
    arg_text = ""
    arg_text += "  ("
    arg_text += ", ".join(str(argg) for argg in jni_def.args[:2])
    
    ret_def = cci_function.rettype
    func_args = ""
    
    for i in range(len(jni_def.args[2:])):
        if cci_function.args[i][0] == "c_SparkMax_handle":
            func_args += "ConvertToMotorControllerWrapper(handle), "
        else:
            cci_type = ""
            if cci_function.args[i][0] not in ["int", "float", "uint8_t", "uint16_t", "uint32_t"]:
                print("Not listed '%s'" % cci_function.args[i][0])
                cci_type = "(%s) " % cci_function.args[i][0]
            func_args += "%s%s, " % (cci_type, cci_function.args[i][1])
        
        arg_text += ", " + jni_def.args[i + 2] + " " + cci_function.args[i][1]
        
    func_args = func_args[:-2]
#         print(arg)
    
    
    arg_text += ")"
    
    output = arg_text
    output += "\n{\n"
    output += '   %s output = %s(%s);\n' % (ret_def, cci_function.func_name, func_args)
    if jni_def.rettype.strip() != "void":
        output += '   return (%s) output;\n' % jni_def.rettype
    output += "}\n"
    
    return output


def dump_unknown_function(jni_def):
    
    output = "  ("
    output += ", ".join(str(argg) for argg in jni_def.args)
    output += ")"
    output += "\n{\n"
    output += '   LOG_UNSUPPORTED_CAN_FUNC("");\n'
    if jni_def.rettype.strip() != "void":
        output += '   return 0;\n'
    output += "}\n"
    
    return output


def guess_jni_function(package_name, jni_def, cci_functions):
    
    stripped_func_name = "c_SparkMax_" + jni_def.func_name[len(package_name + "JNI_c_1_1SparkMax_1"):]
#     print("XXXXXXXXXXXXX", stripped_func_name)
    
    if stripped_func_name in cci_functions:
        output = dump_known_function(jni_def, cci_functions[stripped_func_name])
    else:  
        output = dump_unknown_function(jni_def)
    
    return output


def dump_updated_jni(jni_output_file, package_name, cci_functions, jni_functions):
    with open(jni_output_file, 'w') as f:
        f.write("""
#include <jni.h>

#include <cassert>

#include "com_revrobotics_jni_CANSparkMaxJNI.h"
#include "RevSimMocks/RevMockUtilities.h"
#include "rev/CANSParkMaxDriver.h"
#include "RevSimMocks/RevDeviceWrapper.h"

extern "C" {


c_SparkMax_handle ConvertToMotorControllerWrapper(jlong aHandle)
{
    return (c_SparkMax_handle) reinterpret_cast<SnobotSim::RevSimulator*>(aHandle);
}


""")
        
        for jni_def in jni_functions:
            f.write(jni_def.comment)
            f.write("JNIEXPORT %s JNICALL %s\n" % (jni_def.rettype, jni_def.func_name))
            f.write(guess_jni_function(package_name, jni_def, cci_functions))

def dump_updated_cci(cci_output_file, cci_functions):
    with open(cci_output_file, 'w') as f:
        f.write("""
#include <iostream>
#include <vector>

#include "rev/CANSParkMaxDriver.h"
#include "RevSimMocks/RevMockUtilities.h"
#include "RevSimMocks/RevDeviceWrapper.h"


#define RECEIVE_HELPER(paramName, size)                                        \\
    SnobotSim::RevSimulator* wrapper = (SnobotSim::RevSimulator*) handle;      \\
    uint8_t buffer[size]; /* NOLINT */                                         \\
    std::memset(&buffer[0], 0, size);                                          \\
    wrapper->Receive(paramName, buffer, size);                                 \\
    uint32_t buffer_pos = 0;

""")
#         tmemp_funcs = []
#         tmemp_funcs.append("c_SparkMax_SetFollow")
#         tmemp_funcs.append("c_SparkMax_SetpointCommand")
#         tmemp_funcs.append("c_SparkMax_SetFollow")
#         
#         other_temp = []
#         other_temp.append("c_SparkMax_GetAppliedOutput")
        
        for cci_def in cci_functions.values():
            f.write("%s %s(" % (cci_def.rettype, cci_def.func_name))
            f.write(", ".join("%s %s" % x for x in cci_def.args))
            f.write(")")
            call_name = cci_def.func_name[len("c_SparkMax_"):]
            
            is_setter = True
            for arg_type, _ in cci_def.args:
                if "*" in arg_type:
                    is_setter = False
                    break
            
            if is_setter:
                
                f.write("\n{\n")
                f.write('    ((SnobotSim::RevSimulator*)handle)->Send("%s"' % call_name);
                for _, arg_name in cci_def.args:
                    if arg_name != "handle":
                        f.write(", %s" % arg_name)
                f.write(");\n    return (c_SparkMax_ErrorCode) 0;\n")
                f.write("}\n")
            elif False: # cci_def.func_name in other_temp:
                f.write("\n{\n")
                rcv_helper = ""
                pop_stuff = ""
                for _, arg_name in cci_def.args:
                    if arg_name != "handle":
                        rcv_helper += (", sizeof(*%s)" % arg_name)
                        pop_stuff += ", %s" % arg_name
                f.write('    RECEIVE_HELPER("%s"%s);\n' % (call_name, rcv_helper))
                f.write('    PoplateReceiveResults(buffer%s, buffer_pos);\n' % (pop_stuff))
#                 f.write(rcv_helper + ");\n")
                f.write("    return (c_SparkMax_ErrorCode) 0;\n")
                f.write("}\n")
            else:
                f.write(";\n")

def main():
    print("Hello")
    base_dir = r'C:\Users\PJ\Documents\GitHub\SnobotSim\SnobotSim-RevSim'
    cci_functions = parse_cci_file(os.path.join(base_dir, 'rev_source/native/include/rev/CANSparkMaxDriver.h'))
    jni_functions = parse_jni_file(os.path.join(base_dir, 'rev_source/native/jni/com_revrobotics_jni_CANSparkMaxJNI.h'))
    
#     dump_updated_jni(os.path.join(base_dir, 'com_revrobotics_jni_CANSparkMaxJNI.h'), "com_revrobotics_jni_CANSparkMaxJNI", cci_functions, jni_functions)
    dump_updated_cci(os.path.join(base_dir, 'com_revrobotics_jni_CANSparkMaxJNI.h'), cci_functions)


if __name__ == "__main__":
    main()