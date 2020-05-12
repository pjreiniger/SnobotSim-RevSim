from lib.generator_config import GeneratorConfig


def generator_config_factory():

    definitions = []

    definitions.append(
        __create_config(cci_class_name="CANSparkMaxDriver",
                        cci_prefix="c_SparkMax_",
                        cci_wrapper_type="CCIWRAPPER",
                        jni_package="com_revrobotics_jni_CANSparkMaxJNI",
                        jni_class_name="CANSparkMaxJNI.cpp",
                        java_class_name="JAVACLASSNAME"))

    return definitions


def __get_cci_getter_overrides():

    getter_overrides = {}

    return getter_overrides


def __create_config(**kargs):
    
    class CtreGeneratorConfig(GeneratorConfig):
        def get_stripped_cci_class_name(self):
            return self.cci_class_name
            
        def get_wrapper_class_name(self):
            return "Rev" + self.cci_class_name + "Wrapper"
    
    output = CtreGeneratorConfig(**kargs)

    output.cci_getter_overrides = []
    output.error_ret_code = "c_SparkMax_ErrorCode"
    
    output.full_jni_package = "com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1"
    
    output.cci_overriden_function_bodies['c_SparkMax_Destroy'] = '{\n    auto* wrapper = ConvertToWrapper(handle);\n    delete wrapper;\n}'
    
    output.cci_overriden_function_bodies['c_SparkMax_Create'] = '''{
    SnobotSim::RevCANSparkMaxDriverWrapper* output = new SnobotSim::RevCANSparkMaxDriverWrapper(deviceId, "Create");
    return (c_SparkMax_handle)output;
}'''
    
    output.cci_overriden_function_bodies['c_SparkMax_Create_Inplace'] = '''{
    SnobotSim::RevCANSparkMaxDriverWrapper* output = new SnobotSim::RevCANSparkMaxDriverWrapper(deviceId, "Inplace");
    return (c_SparkMax_handle)output;
}'''
    
    output.cci_overriden_function_bodies['c_SparkMax_SafeFloat'] = '{\n    LOG_UNSUPPORTED_CAN_FUNC("");\n    return 0;\n}'
    output.cci_overriden_function_bodies['c_SparkMax_GenerateError'] = '{\n    LOG_UNSUPPORTED_CAN_FUNC("");\n    return (c_SparkMax_ErrorCode)0;\n}'
    output.cci_overriden_function_bodies['c_SparkMax_IDQuery'] = '{\n    LOG_UNSUPPORTED_CAN_FUNC("");\n    return (c_SparkMax_ErrorCode)0;\n}'
    output.cci_overriden_function_bodies['c_SparkMax_IDAssign'] = '{\n    LOG_UNSUPPORTED_CAN_FUNC("");\n    return (c_SparkMax_ErrorCode)0;\n}'
    output.cci_overriden_function_bodies['c_SparkMax_IdentifyUniqueId'] = '{\n    LOG_UNSUPPORTED_CAN_FUNC("");\n    return (c_SparkMax_ErrorCode)0;\n}'
    output.cci_overriden_function_bodies['c_SparkMax_GetControlFramePeriod'] = '{\n    return ConvertToWrapper(handle)->GetControlFramePeriod();\n}'
    output.cci_overriden_function_bodies['c_SparkMax_SetCANTimeout'] = '{\n    ConvertToWrapper(handle)->SetCANTimeout(timeoutMs);\n    return (c_SparkMax_ErrorCode)0;\n}'
    output.cci_overriden_function_bodies['c_SparkMax_GetAPIVersion'] = '''{
    c_SparkMax_APIVersion output{};
    output.Major = c_SparkMax_kAPIMajorVersion;
    output.Minor = c_SparkMax_kAPIMinorVersion;
    output.Build = c_SparkMax_kAPIBuildVersion;
    output.Version = c_SparkMax_kAPIVersion;

    return output;
}'''

    output.cci_overriden_function_bodies['Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1Create'] = '    c_SparkMax_handle output = c_SparkMax_Create(deviceId, (c_SparkMax_MotorType)type);\n    return (jlong)output;'
    output.cci_overriden_function_bodies['Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1Destroy'] = '    LOG_UNSUPPORTED_CAN_FUNC("");'
    output.cci_overriden_function_bodies['Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1GetAPIBuildRevision'] = '    return c_SparkMax_GetAPIVersion().Build;'
    output.cci_overriden_function_bodies['Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1GetAPIVersion'] = '    return c_SparkMax_GetAPIVersion().Version;'

    output.cpp_enum_types.append("c_SparkMax_FirmwareVersion")
    output.cpp_enum_types.append("c_SparkMax_MotorType")
    output.cpp_enum_types.append("c_SparkMax_IdleMode")
    output.cpp_enum_types.append("c_SparkMax_LimitPolarity")
    output.cpp_enum_types.append("c_SparkMax_AnalogMode")
    output.cpp_enum_types.append("c_SparkMax_AccelStrategy")
    output.cpp_enum_types.append("c_SparkMax_PeriodicFrame")
    output.cpp_enum_types.append("c_SparkMax_ControlType")
    output.cpp_enum_types.append("c_SparkMax_FaultID")
    output.cpp_enum_types.append("c_SparkMax_LimitDirection")
    output.cpp_enum_types.append("c_SparkMax_EncoderType")
    output.cpp_enum_types.append("c_SparkMax_DataPortConfig")


#     default_value["c_SparkMax_FirmwareVersion *"] = " = 0"
#     default_value["c_SparkMax_MotorType *"] = " = 0"
#     default_value["c_SparkMax_IdleMode *"] = " = 0"
#     default_value["c_SparkMax_LimitPolarity *"] = " = 0"
#     default_value["c_SparkMax_AnalogMode *"] = " = 0"
#     default_value["c_SparkMax_AccelStrategy *"] = " = 0"
# 
#     cpp_to_jni = {}
#     cpp_to_jni["nt"] = "jint"
#     cpp_to_jni["int16_t"] = "jint"
#     cpp_to_jni["int32_t"] = "jint"
#     cpp_to_jni["int8_t"] = "jboolean"
#     cpp_to_jni["loat"] = "jfloat"
#     cpp_to_jni["float *"] = "float"
#     cpp_to_jni["_SparkMax_FirmwareVersion"] = "jint"
#     cpp_to_jni["_SparkMax_MotorType"] = "jint"
#     cpp_to_jni["_SparkMax_IdleMode"] = "jint"
#     cpp_to_jni["_SparkMax_LimitPolarity"] = "jint"
#     cpp_to_jni["_SparkMax_AnalogMode"] = "jint"
#     cpp_to_jni["_SparkMax_AccelStrategy"] = "jint"
#     cpp_to_jni["_SparkMax_AccelStrategy"] = "uint8_t"
        
    return output
