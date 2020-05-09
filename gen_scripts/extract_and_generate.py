import shutil
import os
from extract_source_files import extract_source_files
import re

PROJECT_DIR =  r'F:\git\FIRST\SnobotSim\SparkMaxSim'


def __delete_sources():
    def delete_if_exists(path):
        if os.path.exists(path):
            shutil.rmtree(path)
    delete_if_exists("../rev_source")
    delete_if_exists(r"../src\main\native\cpp\rev_driver_mocks")
    delete_if_exists(r"../src\main\native\cpp\rev_jni_mocks")
    delete_if_exists(r"../src\test\java/com/snobot/simulator/rev")
    
    
def generate_cci(definitions):
    from lib.create_cci import CciGenerator
    
    cci_header_dir = os.path.join(PROJECT_DIR, r'rev_source\native\include\rev')
    cci_dump_dir = os.path.join(PROJECT_DIR, r'src\main\native\cpp\rev_driver_mocks')
    
    if not os.path.exists(cci_dump_dir):
        os.makedirs(cci_dump_dir)

    for definition in definitions:
        print(definition)
    
        generator = CciGenerator(definition)
        
        generator.generate(
            os.path.join(cci_header_dir, r'%s.h' % definition.cci_class_name), 
            os.path.join(cci_dump_dir, r'%s.cpp' % definition.cci_class_name),
            os.path.join(PROJECT_DIR, "gen_scripts/cci_templates/_template.txt"))

def generate_jni(definitions):    

    from lib.create_jni import JniGenerator

    cci_dir = os.path.join(PROJECT_DIR, r"rev_source\native\include\rev")
    jni_dir = os.path.join(PROJECT_DIR, r"build\jniinclude\compileJava")
    output_dir = os.path.join(PROJECT_DIR, r"src/main/native/cpp/rev_jni_mocks")
    

    if not os.path.exists(output_dir):
        os.makedirs(output_dir)
    
    for definition in definitions:
        generator = JniGenerator(definition)
        
        # TODO tome
        print(os.path.join(cci_dir, '%s.h' % definition.cci_class_name))
        # F:\git\FIRST\SnobotSim\SparkMaxSim\rev_source\include\rev\CANSparkMaxDriver.h
        # F:\git\FIRST\SnobotSim\SparkMaxSim\rev_source\native\include\rev\CANSparkMaxDriver.h

        generator.generate(
            os.path.join(jni_dir, '%s.h' % definition.jni_package), 
            os.path.join(cci_dir, '%s.h' % definition.cci_class_name),
            os.path.join(PROJECT_DIR, "gen_scripts/jni_templates/%s.txt" % definition.cci_class_name),
            os.path.join(output_dir, definition.jni_class_name),)
        

def generate_unit_tests():
#     known_enums, known_classes = ["TalonSRXFeedbackDevice"], ["SupplyCurrentLimitConfiguration", "TalonSRXPIDSetConfiguration", "TalonSRXConfiguration"]
#     generate("TEMP/TalonSRX.java", "unit_test_templates/talon.txt", r'F:\git\FIRST\SnobotSim\CtreSimulator\src\test\java\com\snobot\simulator\ctre\TestTalonSRXFunctions.java', "talon", known_enums, known_classes)
    
#     known_enums = ["TalonSRXFeedbackDevice", "ControlMode", "DemandType", "NeutralMode", "InvertType", "FollowerType", "ParamEnum", "StatusFrame", "StatusFrameEnhanced", "VelocityMeasPeriod",
#                    "RemoteLimitSwitchSource", "LimitSwitchNormal", "LimitSwitchSource", "RemoteFeedbackDevice", "SensorTerm", "ControlFrame", "FeedbackDevice", "RemoteSensorSource",
#                    "CalibrationMode", "PigeonIMU_StatusFrame", "PigeonIMU_ControlFrame", "LEDChannel", "GeneralPin", "PWMChannel", "VelocityPeriod",
#                    "CANifierStatusFrame", "CANifierControlFrame", "AbsoluteSensorRange", "SensorVelocityMeasPeriod", "SensorInitializationStrategy",
#                    "SensorTimeBase", "CANCoderStatusFrame", "TalonFXControlMode", "TalonFXInvertType", "TalonFXFeedbackDevice", "MotorCommutation"]
#     known_classes = ["SupplyCurrentLimitConfiguration", "TalonSRXPIDSetConfiguration", "TalonSRXConfiguration", "BufferedTrajectoryPointStream", "Faults", "StickyFaults",
#                      "MotionProfileStatus", "SlotConfiguration", "FilterConfiguration", "GeneralStatus", "PigeonIMU_Faults", "PigeonIMU_StickyFaults", "PigeonIMUConfiguration",
#                      "CANifierFaults", "CANifierStickyFaults", "PinValues", "CANifierConfiguration", "FusionStatus",
#                      "VictorSPXPIDSetConfiguration", "CANCoderFaults", "CANCoderStickyFaults", "CANCoderConfiguration", "SupplyCurrentLimitConfiguration",
#                      "TalonFXPIDSetConfiguration", "TalonFXPIDSetConfiguration", "StatorCurrentLimitConfiguration", "TalonFXConfiguration", "VictorSPXConfiguration"]
    
    known_enums = []
    known_classes = []
    
    class UnitTestGenConfig:
        def __init__(self, java_class_name, package_name, actuator_name):
            self.java_class_name = java_class_name
            self.package_name = package_name
            self.actuator_name = actuator_name
    

    definitions = []
    definitions.append(UnitTestGenConfig("CANAnalog", "com/revrobotics", "analog"))
#     definitions.append(UnitTestGenConfig("BaseTalon", "com/revrobotics", "talon"))
#     definitions.append(UnitTestGenConfig("TalonFX", "com/revrobotics", "talonFX"))
#     definitions.append(UnitTestGenConfig("TalonSRX", "com/revrobotics", "talon"))
#     definitions.append(UnitTestGenConfig("VictorSPX", "com/revrobotics", "victor"))
#     definitions.append(UnitTestGenConfig("CANCoder", "com/ctre/phoenix/sensors", "canCoder"))
#     definitions.append(UnitTestGenConfig("PigeonIMU", "com/ctre/phoenix/sensors", "imu"))
#     definitions.append(UnitTestGenConfig("CANifier", "com/ctre/phoenix", "canifier"))
    
    template_dir = os.path.join(PROJECT_DIR, "gen_scripts/unit_test_templates")
    java_files_dir = os.path.join(PROJECT_DIR, "build/tmp/test_files/")
    output_dir = os.path.join(PROJECT_DIR, "src/test/java/com/snobot/simulator/rev")
    
    if not os.path.exists(output_dir):
        os.makedirs(output_dir)
    
    from lib.create_unit_tests import generate
    for definition in definitions:
        
        xxx = os.path.join(template_dir, "%s.txt" % definition.java_class_name)
        if not os.path.exists(xxx):
            shutil.copy(r'F:\git\FIRST\SnobotSim\CtreSimulator\gen_scripts\unit_test_templates\BaseMotorController.txt', xxx)
        
        generate(
            os.path.join(java_files_dir, definition.package_name, "%s.java" % definition.java_class_name), 
            os.path.join(template_dir, "%s.txt" % definition.java_class_name), 
            os.path.join(output_dir, "Test%sFunctions.java" % definition.java_class_name), 
            definition.actuator_name, 
            known_enums, 
            known_classes)

def main():
    with open('../build.gradle') as f:
        results = re.findall(r'ext\.rev_library_version = "(.*)"', f.read())
        version = results[0]
    
    from lib.generator_config_factory import generator_config_factory
    definitions = generator_config_factory()
    
    
#     __delete_sources()
#     extract_source_files(version, "../rev_source", redownload=True)
#     generate_cci(definitions)
#     generate_jni(definitions)
    generate_unit_tests()
    


if __name__ == "__main__":
    main()