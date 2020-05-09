import javalang

from jinja2 import Environment, Template, PackageLoader, select_autoescape
import os
import shutil

    
def __safe_get_next(enumeration_iter):
    try:
        n = next(enumeration_iter)
        return True, n
    except StopIteration:
        return False, None
    
def __format_args(object_name, node, default_value_lookup, indent):
    output = ""
    if indent > 2:
        output += "    " * (indent)
    else:
        output += "        "
    output += object_name + "." + node.name + "(" + ", ".join(default_value_lookup.get(arg.type.name, "FIXME") for arg in node.parameters) + ");"
    return output

def __prepare_variable_name(in_name):
    
    outname = in_name.replace("LED", "led")
    outname = outname.replace("CAN", "can")
    outname = outname.replace("PWM", "pwm")
    
    lower_first_char = lambda s: s[:1].lower() + s[1:] if s else ''
    outname = lower_first_char(outname)
    
    return outname

def __dump_for_loop(object_name, node, default_value_lookup, enumeration_iter, indent):
        
    valid, enum = __safe_get_next(enumeration_iter)
    if valid:
        default_value_lookup[enum] = __prepare_variable_name(enum)
        contents = __dump_for_loop(object_name, node, default_value_lookup, enumeration_iter, indent + 1)
        output = """{{ "    " * indent }}for ({{enum_type}} {{enum_name}} : {{enum_type}}.values())
{{ "    " * indent }}{
{{ contents }}
{{ "    " * indent }}}"""
     
        return Template(output).render(indent=indent, contents=contents, enum_type=enum, enum_name=__prepare_variable_name(enum))
    else:
        return __format_args(object_name, node, default_value_lookup, indent)


def __dump(object_name, node, known_enums, known_classes):
        
    default_value_lookup = {}
    default_value_lookup["int"] = "0"
    default_value_lookup["double"] = "0"
    default_value_lookup["boolean"] = "false"
    default_value_lookup["String"] = '""'
    
    enums = []
    
    for arg in node.parameters:
        if arg.type.name in known_enums:
            enums.append(arg.type.name)
        elif arg.type.name in known_classes:
            default_value_lookup[arg.type.name] = "new %s()" % arg.type.name 
        
    enum_iter = iter(enums) if enums else iter([])
    return __dump_for_loop(object_name, node, default_value_lookup, enum_iter, 2)


def generate(java_class, template_file, output_file, object_name, known_enums, known_classes):

    print(java_class)
    with open(java_class) as f:
        class_contents = f.read()
#         print(class_contents)
        tree = javalang.parse.parse(class_contents)
    
    with open(template_file) as f:
        template_text = f.read()

    with open(output_file, 'w') as f:
        
        kwargs = {}
        function_calls = []
        for path, node in tree.filter(javalang.tree.MethodDeclaration):
            if "public" in node.modifiers:
                if node.name != "DestroyObject" and node.name != "valueOf" and node.name != "toString":
                    function_calls.append(__dump(object_name, node, known_enums, known_classes))
            else:
                print("Skipping protected function", node.name)
        
        data_dump = Template(template_text).render(functions="\n".join(function_calls))
        f.write(data_dump)
    

def main():
#     known_enums, known_classes = ["TalonSRXFeedbackDevice"], ["SupplyCurrentLimitConfiguration", "TalonSRXPIDSetConfiguration", "TalonSRXConfiguration"]
#     generate("TEMP/TalonSRX.java", "unit_test_templates/talon.txt", r'F:\git\FIRST\SnobotSim\CtreSimulator\src\test\java\com\snobot\simulator\ctre\TestTalonSRXFunctions.java', "talon", known_enums, known_classes)
    
    known_enums = ["TalonSRXFeedbackDevice", "ControlMode", "DemandType", "NeutralMode", "InvertType", "FollowerType", "ParamEnum", "StatusFrame", "StatusFrameEnhanced", "VelocityMeasPeriod",
                   "RemoteLimitSwitchSource", "LimitSwitchNormal", "LimitSwitchSource", "RemoteFeedbackDevice", "SensorTerm", "ControlFrame", "FeedbackDevice", "RemoteSensorSource",
                   "CalibrationMode", "PigeonIMU_StatusFrame", "PigeonIMU_ControlFrame", "LEDChannel", "GeneralPin", "PWMChannel", "VelocityPeriod",
                   "CANifierStatusFrame", "CANifierControlFrame", "AbsoluteSensorRange", "SensorVelocityMeasPeriod", "SensorInitializationStrategy",
                   "SensorTimeBase", "CANCoderStatusFrame", "TalonFXControlMode", "TalonFXInvertType", "TalonFXFeedbackDevice", "MotorCommutation"]
    known_classes = ["SupplyCurrentLimitConfiguration", "TalonSRXPIDSetConfiguration", "TalonSRXConfiguration", "BufferedTrajectoryPointStream", "Faults", "StickyFaults",
                     "MotionProfileStatus", "SlotConfiguration", "FilterConfiguration", "GeneralStatus", "PigeonIMU_Faults", "PigeonIMU_StickyFaults", "PigeonIMUConfiguration",
                     "CANifierFaults", "CANifierStickyFaults", "PinValues", "CANifierConfiguration", "FusionStatus",
                     "VictorSPXPIDSetConfiguration", "CANCoderFaults", "CANCoderStickyFaults", "CANCoderConfiguration", "SupplyCurrentLimitConfiguration",
                     "TalonFXPIDSetConfiguration", "TalonFXPIDSetConfiguration", "StatorCurrentLimitConfiguration", "TalonFXConfiguration", "VictorSPXConfiguration"]
    
    class UnitTestGenConfig:
        def __init__(self, java_class_name, package_name, actuator_name):
            self.java_class_name = java_class_name
            self.package_name = package_name
            self.actuator_name = actuator_name
    

    definitions = []
    definitions.append(UnitTestGenConfig("BaseMotorController", "com/ctre/phoenix/motorcontrol/can", "talon"))
    definitions.append(UnitTestGenConfig("BaseTalon", "com/ctre/phoenix/motorcontrol/can", "talon"))
    definitions.append(UnitTestGenConfig("TalonFX", "com/ctre/phoenix/motorcontrol/can", "talonFX"))
    definitions.append(UnitTestGenConfig("TalonSRX", "com/ctre/phoenix/motorcontrol/can", "talon"))
    definitions.append(UnitTestGenConfig("VictorSPX", "com/ctre/phoenix/motorcontrol/can", "victor"))
    definitions.append(UnitTestGenConfig("CANCoder", "com/ctre/phoenix/sensors", "canCoder"))
    definitions.append(UnitTestGenConfig("PigeonIMU", "com/ctre/phoenix/sensors", "imu"))
    definitions.append(UnitTestGenConfig("CANifier", "com/ctre/phoenix", "canifier"))
    
    project_dir = r'F:\git\FIRST\SnobotSim\CtreSimulator'
    template_dir = os.path.join(project_dir, "gen_scripts/unit_test_templates")
    java_files_dir = os.path.join(project_dir, "build/tmp/test_files/")
    output_dir = os.path.join(project_dir, "src/test/java/com/snobot/simulator/ctre")
    
    if not os.path.exists(output_dir):
        os.makedirs(output_dir)
    
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
    
if __name__ == "__main__":
    main()






