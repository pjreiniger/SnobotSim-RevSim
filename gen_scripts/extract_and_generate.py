import shutil
import os
from extract_source_files import extract_source_files
import re
import subprocess

PROJECT_DIR = r'F:\git\FIRST\SnobotSim\SparkMaxSim'
ORIGINAL_SOURCE_DIR = os.path.join(PROJECT_DIR, r"rev_source")
CCI_HEADER_DIR = os.path.join(PROJECT_DIR, r"rev_source\native\include\rev")
CCI_SOURCE_DIR = os.path.join(PROJECT_DIR, r'src\main\native\cpp\rev_driver_mocks')
JNI_SOURCE_DIR = os.path.join(PROJECT_DIR, r'src\main\native\cpp\rev_jni_mocks')
JAVA_TEST_DIR = os.path.join(PROJECT_DIR, r'src\test\java/com/snobot/simulator/rev')
SNOBOT_CCI_HEADER_DIR = os.path.join(PROJECT_DIR, r"src/main/native/include/RevSimMocks")
SNOBOT_CCI_SOURCE_DIR = os.path.join(PROJECT_DIR, r"src/main/native/cpp/RevSimMocks")

    

def __delete_sources():

    def delete_if_exists(path):
        if os.path.exists(path):
            shutil.rmtree(path)

    delete_if_exists(ORIGINAL_SOURCE_DIR)
    delete_if_exists(CCI_SOURCE_DIR)
    delete_if_exists(JNI_SOURCE_DIR)
    delete_if_exists(JAVA_TEST_DIR)


def generate_cci(definitions):
    from lib.create_cci import CciGenerator

    for definition in definitions:

        generator = CciGenerator(definition)

        generator.generate(
            os.path.join(CCI_HEADER_DIR, r'%s.h' % definition.cci_class_name),
            os.path.join(CCI_SOURCE_DIR, r'%s.cpp' % definition.cci_class_name),
            os.path.join(PROJECT_DIR, "gen_scripts/cci_templates/template.txt"))


def generate_jni(definitions):

    from lib.create_jni import JniGenerator

    jni_dir = os.path.join(PROJECT_DIR, r"build\jniinclude\compileJava")

    for definition in definitions:
        generator = JniGenerator(definition)

        generator.generate(
            os.path.join(jni_dir, '%s.h' % definition.jni_package),
            os.path.join(CCI_HEADER_DIR, '%s.h' % definition.cci_class_name),
            os.path.join(PROJECT_DIR, "gen_scripts/jni_templates/template.txt"),
            os.path.join(JNI_SOURCE_DIR, definition.jni_class_name),
        )


def generate_wrapper(definitions):

    from lib.create_sim_wrapper import SimWrapperGenerator


    for definition in definitions:
        generator = SimWrapperGenerator(definition)
    
        generator.generate(
            os.path.join(CCI_HEADER_DIR, '%s.h' % definition.cci_class_name),
            os.path.join(SNOBOT_CCI_SOURCE_DIR, definition.get_wrapper_class_name() + ".cpp"),
            os.path.join(SNOBOT_CCI_HEADER_DIR, definition.get_wrapper_class_name() + ".h"),
            os.path.join(PROJECT_DIR, "gen_scripts/wrapper_templates/_cpp_template.txt"),
            os.path.join(PROJECT_DIR, "gen_scripts/wrapper_templates/_header_template.txt"),
        )


def generate_unit_tests():

    known_enums = [
        "EncoderType", "AlternateEncoderType", "AnalogMode",
        "LimitSwitchPolarity", "IdleMode", "FaultID", "SoftLimitDirection",
        "ControlType", 'AccelStrategy', 'ArbFFUnits', 'MotorType',
        'PeriodicFrame'
    ]
    known_classes = []

    class UnitTestGenConfig:

        def __init__(self, java_class_name, package_name, actuator_name):
            self.java_class_name = java_class_name
            self.package_name = package_name
            self.actuator_name = actuator_name

    definitions = []
    definitions.append(UnitTestGenConfig("CANAnalog", "com/revrobotics", "analog"))
    definitions.append(UnitTestGenConfig("CANDigitalInput", "com/revrobotics", "reverseSwitch"))
    definitions.append(UnitTestGenConfig("CANEncoder", "com/revrobotics", "encoder"))
    definitions.append(UnitTestGenConfig("CANPIDController", "com/revrobotics", "pid"))
    definitions.append(UnitTestGenConfig("CANSparkMax", "com/revrobotics", "spark"))
    definitions.append(UnitTestGenConfig("CANSparkMaxLowLevel", "com/revrobotics", "spark"))

    template_dir = os.path.join(PROJECT_DIR, "gen_scripts/unit_test_templates")
    java_files_dir = os.path.join(PROJECT_DIR, "build/tmp/test_files/")

    from lib.create_unit_tests import generate
    for definition in definitions:

        xxx = os.path.join(template_dir, "%s.txt" % definition.java_class_name)
        if not os.path.exists(xxx):
            shutil.copy(PROJECT_DIR + r'\gen_scripts\unit_test_templates\BaseMotorController.txt', xxx)

        generate(
            os.path.join(java_files_dir, definition.package_name, "%s.java" % definition.java_class_name),
            os.path.join(template_dir, "%s.txt" % definition.java_class_name),
            os.path.join(JAVA_TEST_DIR, "Test%sFunctions.java" % definition.java_class_name),
            definition.actuator_name,
            known_enums,
            known_classes)


def main():
    with open('../build.gradle') as f:
        results = re.findall(r'ext\.rev_library_version = "(.*)"', f.read())
        version = results[0]

    from generator_config_factory import generator_config_factory
    definitions = generator_config_factory()
    
#     __delete_sources()
    
    def create_dir_if_missing(the_dir):
        if not os.path.exists(the_dir):
            os.makedirs(the_dir)
    
    create_dir_if_missing(os.path.join(PROJECT_DIR, "build"))
    create_dir_if_missing(CCI_SOURCE_DIR)
    create_dir_if_missing(JNI_SOURCE_DIR)
    create_dir_if_missing(SNOBOT_CCI_HEADER_DIR)
    create_dir_if_missing(SNOBOT_CCI_SOURCE_DIR)
    create_dir_if_missing(JAVA_TEST_DIR)

#     extract_source_files(version, "../rev_source", redownload=True)
#     generate_cci(definitions)
#     generate_jni(definitions)
    generate_wrapper(definitions)
#     generate_unit_tests()

#     os.chdir(PROJECT_DIR)
#     subprocess.call("wpiformat")


if __name__ == "__main__":
    main()
