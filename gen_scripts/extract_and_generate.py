import shutil
import os
from extract_source_files import extract_source_files
import re


def __delete_sources():
    def delete_if_exists(path):
        if os.path.exists(path):
            shutil.rmtree(path)
    delete_if_exists("../ctre_source")
    delete_if_exists(r"../src\main\native\cpp\ctre_cci_mocks")
    delete_if_exists(r"../src\main\native\cpp\ctre_jni_mocks")
    delete_if_exists(r"../src\test\java/com/snobot/simulator/ctre")
    
    
def generate_cci(definitions):
    from lib.create_cci import CciGenerator
    
    project_dir = r'F:\git\FIRST\SnobotSim\CtreSimulator'
    cci_header_dir = os.path.join(project_dir, r'ctre_source\cci\native\include\ctre\phoenix\cci')
    cci_dump_dir = os.path.join(project_dir, r'src\main\native\cpp\ctre_cci_mocks')
    
    if not os.path.exists(cci_dump_dir):
        os.makedirs(cci_dump_dir)

    for definition in definitions:
    
        generator = CciGenerator(definition)
        
        generator.generate(
            os.path.join(cci_header_dir, r'%s.h' % definition.cci_class_name), 
            os.path.join(cci_dump_dir, r'%s.cpp' % definition.cci_class_name),
            os.path.join(project_dir, "gen_scripts/cci_templates/%s.txt" % definition.cci_class_name))

def generate_jni(definitions):    

    from lib.create_jni import JniGenerator

    project_dir = r'F:\git\FIRST\SnobotSim\CtreSimulator'
    jni_dir = os.path.join(project_dir, r"ctre_source\cci\native\include\ctre\phoenix\jni")
    cci_dir = os.path.join(project_dir, r"ctre_source\cci\native\include\ctre\phoenix\cci")
    output_dir = os.path.join(project_dir, r"src/main/native/cpp/ctre_jni_mocks")

    if not os.path.exists(output_dir):
        os.makedirs(output_dir)
    
    for definition in definitions:
        generator = JniGenerator(definition)

        generator.generate(
            os.path.join(jni_dir, '%s.h' % definition.jni_package), 
            os.path.join(cci_dir, '%s.h' % definition.cci_class_name),
            os.path.join(project_dir, "gen_scripts/jni_templates/%s.txt" % definition.cci_class_name),
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
    
    class UnitTestGenConfig:
        def __init__(self, java_class_name, package_name, actuator_name):
            self.java_class_name = java_class_name
            self.package_name = package_name
            self.actuator_name = actuator_name
    

    definitions = []
#     definitions.append(UnitTestGenConfig("BaseMotorController", "com/ctre/phoenix/motorcontrol/can", "talon"))
#     definitions.append(UnitTestGenConfig("BaseTalon", "com/ctre/phoenix/motorcontrol/can", "talon"))
#     definitions.append(UnitTestGenConfig("TalonFX", "com/ctre/phoenix/motorcontrol/can", "talonFX"))
#     definitions.append(UnitTestGenConfig("TalonSRX", "com/ctre/phoenix/motorcontrol/can", "talon"))
#     definitions.append(UnitTestGenConfig("VictorSPX", "com/ctre/phoenix/motorcontrol/can", "victor"))
#     definitions.append(UnitTestGenConfig("CANCoder", "com/ctre/phoenix/sensors", "canCoder"))
#     definitions.append(UnitTestGenConfig("PigeonIMU", "com/ctre/phoenix/sensors", "imu"))
#     definitions.append(UnitTestGenConfig("CANifier", "com/ctre/phoenix", "canifier"))
    
    project_dir = r'F:\git\FIRST\SnobotSim\CtreSimulator'
    template_dir = os.path.join(project_dir, "gen_scripts/unit_test_templates")
    java_files_dir = os.path.join(project_dir, "build/tmp/test_files/")
    output_dir = os.path.join(project_dir, "src/test/java/com/snobot/simulator/ctre")
    
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
    
    
    __delete_sources()
    extract_source_files(version, "../ctre_source", redownload=True)
    generate_cci(definitions)
    generate_jni(definitions)
    generate_unit_tests()
    


if __name__ == "__main__":
    main()