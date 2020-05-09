
from generator_config import GeneratorConfig


def generator_config_factory():
    

    definitions = []
#     definitions.append(__create_config("MotController_CCI", "c_MotController_", "ConvertToMotorControllerWrapper", "MotorControllerWrapper",
#                                        "com_ctre_phoenix_motorcontrol_can_MotControllerJNI", "MotControllerJNI.cpp",
#                                        "BaseMotorController", "com/ctre/phoenix/motorcontrol/can", "talon"))
#        
#     definitions.append(__create_config("PigeonIMU_CCI", "c_PigeonIMU_", "ConvertToPigeonWrapper", "PigeonImuSimulatorWrapper",
#                                        "com_ctre_phoenix_sensors_PigeonImuJNI", "PigeonImuJNI.cpp",
#                                        "PigeonIMU", "com/ctre/phoenix/sensors", "imu"))
         
    definitions.append(__create_config("CANifier_CCI", "c_CANifier_", "ConvertToCanifierWrapper", "SnobotSim::CtreCanifierWrapper",
                                       "com_ctre_phoenix_CANifierJNI", "CANifierJNI.cpp",
                                       "CANifier", "com/ctre/phoenix", "canifier"))
#         
#     definitions.append(__create_config("BuffTrajPointStream_CCI", "c_BuffTrajPointStream_", "ConvertToBuffTrajPointStreamWrapper", "SnobotSim::CtreBuffTrajPointStreamWrapper",
#                                        "com_ctre_phoenix_motion_BuffTrajPointStreamJNI", "BuffTrajPointStreamJNI.cpp",
#                                        "", "", ""))
      
#     definitions.append(__create_config("Logger_CCI", "c_Logger_", "ConvertToBuffTrajPointStreamWrapper", "SnobotSim::CtreBuffTrajPointStreamWrapper",
#                                        "com_ctre_phoenix_CTRLoggerJNI", "CTRLoggerJNI.cpp",
#                                        "", "", ""))
      
    definitions.append(__create_config("CANCoder_CCI", "c_CANCoder_", "ConvertToCanCoderWrapper", "CtreCanCoderWrapper",
                                       "com_ctre_phoenix_sensors_CANCoderJNI", "CanCoderJNI.cpp",
                                       "", "", ""))

    return definitions

#     definitions.append(Stuff("com_ctre_phoenix_platform_can_PlatformCANJNI", "MotController_CCI", "c_MotController_", "PlatformCANJNI.cpp"))
#     definitions.append(Stuff("com_ctre_phoenix_platform_PlatformJNI", "MotController_CCI", "c_MotController_", "PlatformJNI.cpp"))
#     definitions.append(Stuff("com_ctre_phoenix_sensors_CANCoderJNI", "MotController_CCI", "c_MotController_", "CANCoderJNI.cpp"))
#     definitions.append(Stuff("com_ctre_phoenix_unmanaged_UnmanagedJNI", "MotController_CCI", "c_MotController_", "UnmanagedJNI.cpp"))

#     definitions.append(Stuff("BaseMotorController", "com/ctre/phoenix/motorcontrol/can", "talon"))
#     definitions.append(Stuff("BaseTalon", "com/ctre/phoenix/motorcontrol/can", "talon"))
#     definitions.append(Stuff("TalonFX", "com/ctre/phoenix/motorcontrol/can", "talonFX"))
#     definitions.append(Stuff("TalonSRX", "com/ctre/phoenix/motorcontrol/can", "talon"))
#     definitions.append(Stuff("VictorSPX", "com/ctre/phoenix/motorcontrol/can", "victor"))
#     definitions.append(Stuff("CANCoder", "com/ctre/phoenix/sensors", "canCoder"))
#     definitions.append(Stuff("PigeonIMU", "com/ctre/phoenix/sensors", "imu"))
#     definitions.append(Stuff("CANifier", "com/ctre/phoenix", "canifier"))

def __get_cci_getter_overrides():
    
    default = [{'name': 'True'}]
    
    getter_overrides = {}
    getter_overrides['c_PigeonIMU_GetAccelerometerAngles'] = default
    getter_overrides['c_PigeonIMU_GetRawGyro'] = default
    getter_overrides['c_PigeonIMU_GetFusedHeading1'] = default
    getter_overrides['c_PigeonIMU_GetAccumGyro'] = default
    getter_overrides['c_PigeonIMU_GetYawPitchRoll'] = default
    getter_overrides['c_PigeonIMU_Get6dQuaternion'] = default
    getter_overrides['c_PigeonIMU_GetRawMagnetometer'] = default
    getter_overrides['c_PigeonIMU_GetBiasedMagnetometer'] = default
    getter_overrides['c_PigeonIMU_GetBiasedAccelerometer'] = default
    getter_overrides['c_CANifier_GetPWMInput'] = default
    
    return getter_overrides

__CCI_GETTER_TEMPLATE = """{
    RECEIVE_HELPER("{{ callback_name }}", {% for arg in args if arg.name != "handle" and arg.name != "timeoutMs" %}sizeof({{ "*" if "*" in arg.type }}{{arg.name}}){{ " + " if not loop.last }}{% endfor %});{% for arg in args if arg.name != "handle" and arg.name != "timeoutMs" %}
    PoplateReceiveResults(buffer, {{ "&" if "*" not in arg.type }}{{arg.name}}, buffer_pos);{% endfor %}
    {% if return_type == "ctre::phoenix::ErrorCode" %}return (ctre::phoenix::ErrorCode)0;{% endif %}
}"""

__CCI_SETTER_TEMPLATE = """{
    Send("{{ callback_name }}"{% for arg in args if arg.name != "handle" and arg.name != "timeoutMs" %}, {{arg.name}}{% endfor %});{% if return_type == "ctre::phoenix::ErrorCode" %}
    return (ctre::phoenix::ErrorCode)0;{% endif %}
}"""

def __create_config(*kargs):
        output = GeneratorConfig(*kargs)
        
#         if output.jni_package == "com_ctre_phoenix_sensors_PigeonImuJNI_JNI_1":
#             output.full_jni_package = "com_ctre_phoenix_sensors_PigeonImuJNI"
        print(output.full_jni_package)
        if output.jni_package == "com_ctre_phoenix_sensors_PigeonImuJNI":
            print("OVERRIDING FULL NAME")
            output.full_jni_package += "JNI_11"
            output.include_jni_in_method_name = True
        elif output.jni_package == "com_ctre_phoenix_CANifierJNI":
            print("OVERRIDING FULL NAME")
            output.full_jni_package += "JNI_11"
            output.include_jni_in_method_name = True
        else:
            output.full_jni_package += "_"
        
        output.cci_getter_template = __CCI_GETTER_TEMPLATE
        output.cci_setter_template = __CCI_SETTER_TEMPLATE
        output.cci_getter_overrides = __get_cci_getter_overrides()
        
        ###############################################
        output.cci_overriden_function_bodies['c_MotController_Create1'] = '{\n    auto* output = new SnobotSim::CtreMotControllerWrapper(baseArbId);\n    return output;\n}'
        output.cci_overriden_function_bodies['c_MotController_Create2'] = '{\n    auto* output = new SnobotSim::CtreMotControllerWrapper(deviceID);\n    return output;\n}'
        
        
        output.cci_overriden_function_bodies['c_MotController_DestroyAll'] = '{\n\n}'
        output.cci_overriden_function_bodies['c_MotController_Destroy'] = '{\n    auto* wrapper = {{ conversion_function }}(handle);\n    delete wrapper;\n    return (ctre::phoenix::ErrorCode)0;\n}'
        output.cci_overriden_function_bodies['c_MotController_GetDeviceNumber'] = '''{
    auto* wrapper = ConvertToMotorControllerWrapper(handle);
    *deviceNumber = wrapper->mDeviceId;
    return (ctre::phoenix::ErrorCode)0;
}'''
        output.cci_overriden_function_bodies['c_MotController_PushMotionProfileTrajectory_2'] = '''{
\tLOG_UNSUPPORTED_CAN_FUNC("")
//    auto* wrapper = ConvertToMotorControllerWrapper(handle);
//    wrapper->Send("PushMotionProfileTrajectory_2", position, velocity, headingDeg, profileSlotSelect0, profileSlotSelect1, isLastPoint, zeroPos, durationMs);
    return (ctre::phoenix::ErrorCode)0;
}'''
        output.cci_overriden_function_bodies['c_MotController_GetLastError'] = '''{
    int lastError = 0;
    RECEIVE_HELPER("GetLastError", sizeof(lastError));
    PoplateReceiveResults(buffer, &lastError, buffer_pos);
    return (ctre::phoenix::ErrorCode) lastError;
}'''
        output.cci_overriden_function_bodies['c_MotController_ConfigSupplyCurrentLimit'] = '''{
\tLOG_UNSUPPORTED_CAN_FUNC("")
//    RECEIVE_HELPER("ConfigSupplyCurrentLimit", sizeof(*params) + sizeof(paramCnt) + sizeof(timeoutMs));
//    PoplateReceiveResults(buffer, params, buffer_pos);
//    PoplateReceiveResults(buffer, &paramCnt, buffer_pos);
//    PoplateReceiveResults(buffer, &timeoutMs, buffer_pos);
    return (ctre::phoenix::ErrorCode)0;
}'''
        output.cci_overriden_function_bodies['c_MotController_ConfigStatorCurrentLimit'] = '''{
\tLOG_UNSUPPORTED_CAN_FUNC("")
//    RECEIVE_HELPER("ConfigStatorCurrentLimit", sizeof(*params) + sizeof(paramCnt) + sizeof(timeoutMs));
//    PoplateReceiveResults(buffer, params, buffer_pos);
//    PoplateReceiveResults(buffer, &paramCnt, buffer_pos);
//    PoplateReceiveResults(buffer, &timeoutMs, buffer_pos);
    return (ctre::phoenix::ErrorCode)0;
}'''

        ###############################################
        output.cci_overriden_function_bodies['c_CANCoder_Create1'] = '{\n    auto* output = new {{ wrapper_type }}(deviceNumber);\n    return output;\n}'
        output.cci_overriden_function_bodies['c_CANCoder_DestroyAll'] = '{\n    LOG_UNSUPPORTED_CAN_FUNC("");\n}'
        output.cci_overriden_function_bodies['c_CANCoder_Destroy'] = '{\n    auto* wrapper = {{ conversion_function }}(handle);\n    delete wrapper;\n    return (ctre::phoenix::ErrorCode)0;\n}'

        output.cci_overriden_function_bodies['c_CANCoder_GetDescription'] = '''{
    RECEIVE_HELPER("GetDescription", 1);
    buffer_pos += 1; // Removes compiler warning
    return (ctre::phoenix::ErrorCode)0;
}'''
        output.cci_overriden_function_bodies['c_CANCoder_GetLastError'] = '''{
    int lastError = 0;
    RECEIVE_HELPER("GetLastError", sizeof(lastError));
    PoplateReceiveResults(buffer, &lastError, buffer_pos);
    return (ctre::phoenix::ErrorCode) lastError;
}'''


        ##############################################
        output.cci_overriden_function_bodies['c_PigeonIMU_Create2'] = '{\n    auto* output = new SnobotSim::CtrePigeonIMUWrapper(talonDeviceID);\n    return output;\n}'
        output.cci_overriden_function_bodies['c_PigeonIMU_Create1'] = '{\n    auto* output = new SnobotSim::CtrePigeonIMUWrapper(deviceNumber);\n    return output;\n}'
        output.cci_overriden_function_bodies['c_PigeonIMU_DestroyAll'] = '{\n    LOG_UNSUPPORTED_CAN_FUNC("");\n}'
        output.cci_overriden_function_bodies['c_PigeonIMU_Destroy'] = '{\n    auto* wrapper = {{ conversion_function }}(handle);\n    delete wrapper;\n    return (ctre::phoenix::ErrorCode)0;\n}'
        
        output.cci_overriden_function_bodies['c_PigeonIMU_GetLastError'] = '''{
    int lastError = 0;
    RECEIVE_HELPER("GetLastError", sizeof(lastError));
    PoplateReceiveResults(buffer, &lastError, buffer_pos);
    return (ctre::phoenix::ErrorCode) lastError;
}'''
        output.cci_overriden_function_bodies['c_PigeonIMU_GetDescription'] = '''{
    RECEIVE_HELPER("GetDescription", 1);
    buffer_pos += 1; // Removes compiler warning
    return (ctre::phoenix::ErrorCode)0;
}'''

        ###################################
        output.cci_overriden_function_bodies['c_BuffTrajPointStream_Create1'] = '{\n    auto* output = new {{ wrapper_type }}();\n    return output;\n}'
        output.cci_overriden_function_bodies['c_BuffTrajPointStream_DestroyAll'] = '{\n    LOG_UNSUPPORTED_CAN_FUNC("");\n}'
        output.cci_overriden_function_bodies['c_BuffTrajPointStream_Destroy'] = '{\n    auto* wrapper = {{ conversion_function }}(handle);\n    delete wrapper;\n    return (ctre::phoenix::ErrorCode)0;\n}'
        output.cci_overriden_function_bodies['c_BuffTrajPointStream_Lookup'] = '''{
    LOG_UNSUPPORTED_CAN_FUNC("");
    // RECEIVE_HELPER("Lookup", sizeof(*outObject));
    // PoplateReceiveResults(buffer, outObject, buffer_pos);
    return (ctre::phoenix::ErrorCode)0;
}'''

        ###################################
        output.cci_overriden_function_bodies['c_CANifier_Create1'] = '{\n    auto* output = new SnobotSim::CtreCANifierWrapper(deviceNumber);\n    return output;\n}'
        output.cci_overriden_function_bodies['c_CANifier_DestroyAll'] = '{\n    LOG_UNSUPPORTED_CAN_FUNC("");\n}'
        output.cci_overriden_function_bodies['c_CANifier_Destroy'] = '{\n    auto* wrapper = {{ conversion_function }}(handle);\n    delete wrapper;\n    return (ctre::phoenix::ErrorCode)0;\n}'
        output.cci_overriden_function_bodies['c_CANifier_GetDescription'] = '''{
    LOG_UNSUPPORTED_CAN_FUNC("");
    return (ctre::phoenix::ErrorCode)0;
}'''
        output.cci_overriden_function_bodies['c_CANifier_GetLastError'] = '''{
    int error = 0;
    RECEIVE_HELPER("GetLastError", sizeof(error));
    PoplateReceiveResults(buffer, &error, buffer_pos);
    return (ctre::phoenix::ErrorCode)error;
}'''
        output.cci_overriden_function_bodies['c_CANifier_GetGeneralInputs'] = '''{
    RECEIVE_HELPER("GetGeneralInputs", sizeof(bool) * 11);
    for(unsigned int i = 0; i < capacity; ++i)
    {
        PoplateReceiveResults(buffer, &allPins[i], buffer_pos);
    }
    return (ctre::phoenix::ErrorCode)0;
}'''
        


        return output
    