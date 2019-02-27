import subprocess
import os
import re
import collections

JAVA_PATH = r'C:\Program Files\Java\jdk1.8.0_191'
LIB_VERSION = "1.1.9"
LIB_HASH = "e7b118e6fd873ea74e7ccbce278e0979a323c30e"
ARTIFACT_PACKAGE = "com.revrobotics.frc"
ARTIFACT_NAME = "SparkMax-java"
M2_DIRECTORY = r'C:\Users\PJ\.gradle\caches\modules-2\files-2.1'


def create_tests(jar_path):
    output_dir = "build/tempCreateTests"
    if not os.path.exists(output_dir):
        os.makedirs(output_dir)
    os.chdir(output_dir)

    classes = collections.defaultdict(list)
    classes["digitalInput"].append("com/revrobotics/CANDigitalInput.class")
    classes["encoder"].append("com/revrobotics/CANEncoder.class")
    classes["spark"].append("com/revrobotics/CANSparkMax.class")
    classes["spark"].append("com/revrobotics/CANSparkMaxLowLevel.class")

    unzip_args = []
    unzip_args.append(JAVA_PATH + r'\bin\jar')
    unzip_args.append("xf")
    unzip_args.append(jar_path)

    for class_list in classes.values():
        for clazz in class_list:
            unzip_args.append(clazz)

    print(" ".join(unzip_args))
    print(subprocess.call(unzip_args))

    for key in classes:
        for clazz in classes[key]:
            run_javap(key, clazz)


def prepare_variable_name(in_name):

    outname = in_name.replace("LED", "led")
    outname = outname.replace("CAN", "can")

    lower_first_char = lambda s: s[:1].lower() + s[1:] if s else ''
    outname = lower_first_char(outname)

    return outname


def run_javap(objName, class_file):

    print("File %s ---------------------" % class_file)

    javap_args = []
    javap_args.append(JAVA_PATH + r'\bin\javap')
    javap_args.append(class_file)
    p = subprocess.Popen(
        javap_args, stdout=subprocess.PIPE, stderr=subprocess.PIPE)

    stdout, _ = p.communicate()

    tests = ""

    for line in stdout.split("\n"):
        matches = re.findall("  public .* (.*)\((.*)\)", line)
        if len(matches) != 0:
            matches = matches[0]
            func = matches[0]
            args = matches[1].split(",")
            arg_replacement = []

            enumerations = []

            if type(args) == list:
                for a in args:
                    a = a.strip()
                    if a == "int" or a == "double":
                        arg_replacement.append("0")
                    elif a == "boolean":
                        arg_replacement.append("false")
                    elif a != "":
                        stripped_name = a[a.rfind(".") + 1:]
                        if "$" in stripped_name:
                            stripped_name = stripped_name[
                                stripped_name.rfind("$") + 1:]

                        enumerations.append(stripped_name)
                        arg_replacement.append(
                            prepare_variable_name(stripped_name))

            if len(enumerations) == 0:
                tests += "    %s.%s(%s);\n" % (objName, func,
                                               ", ".join(arg_replacement))
            else:
                tests += "    for({0} {1} : {0}.values())".format(
                    enumerations[0],
                    prepare_variable_name(enumerations[0])) + "\n    {\n"
                tests += "        %s.%s(%s);\n" % (objName, func,
                                                   ", ".join(arg_replacement))
                tests += "    }\n"

    print(tests)


create_tests(
    r'{m2_dir}\{artifact_package}\{artifact_name}\{lib_version}\{lib_hash}/{artifact_name}-{lib_version}.jar'.
    format(
        lib_hash=LIB_HASH,
        lib_version=LIB_VERSION,
        m2_dir=M2_DIRECTORY,
        artifact_package=ARTIFACT_PACKAGE,
        artifact_name=ARTIFACT_NAME))
