

#include "RevSimMocks/RevCANSparkMaxDriverWrapper.h"

#include <vector>

#include "RevSimUtils/MockHooks.h"

#define RECEIVE_HELPER(paramName, size) \
    uint8_t buffer[size]; /* NOLINT */  \
    std::memset(&buffer[0], 0, size);   \
    Receive(paramName, buffer, size);   \
    uint32_t buffer_pos = 0;

std::vector<SnobotSim::REV_CallbackFunc> gCANSparkMaxDriverCallbacks;

void SnobotSim::SetCANSparkMaxDriverCallback(SnobotSim::REV_CallbackFunc callback)
{
    gCANSparkMaxDriverCallbacks.clear();
    gCANSparkMaxDriverCallbacks.push_back(callback);
}

SnobotSim::RevCANSparkMaxDriverWrapper::RevCANSparkMaxDriverWrapper(int aDeviceId) :
        mDeviceId(aDeviceId),
        m_simDevice(std::string("RevCANSparkMaxDriverWrapper " + std::to_string(aDeviceId)).c_str(), aDeviceId)
{
    m_AltEncoderAverageDepth_depth = m_simDevice.CreateDouble("AltEncoderAverageDepth_depth", false, 0);
    m_AltEncoderCountsPerRevolution_cpr = m_simDevice.CreateDouble("AltEncoderCountsPerRevolution_cpr", false, 0);
    m_AltEncoderInverted_inverted = m_simDevice.CreateDouble("AltEncoderInverted_inverted", false, 0);
    m_AltEncoderMeasurementPeriod_samples = m_simDevice.CreateDouble("AltEncoderMeasurementPeriod_samples", false, 0);
    m_AltEncoderPositionFactor_conversion = m_simDevice.CreateDouble("AltEncoderPositionFactor_conversion", false, 0);
    m_AltEncoderPosition_position = m_simDevice.CreateDouble("AltEncoderPosition_position", false, 0);
    m_AltEncoderVelocityFactor_conversion = m_simDevice.CreateDouble("AltEncoderVelocityFactor_conversion", false, 0);
    m_AltEncoderVelocity_velocity = m_simDevice.CreateDouble("AltEncoderVelocity_velocity", false, 0);
    m_AnalogAverageDepth_depth = m_simDevice.CreateDouble("AnalogAverageDepth_depth", false, 0);
    m_AnalogInverted_inverted = m_simDevice.CreateDouble("AnalogInverted_inverted", false, 0);
    m_AnalogMeasurementPeriod_samples = m_simDevice.CreateDouble("AnalogMeasurementPeriod_samples", false, 0);
    m_AnalogMode_mode = m_simDevice.CreateDouble("AnalogMode_mode", false, 0);
    m_AnalogPositionConversionFactor_conversion = m_simDevice.CreateDouble("AnalogPositionConversionFactor_conversion", false, 0);
    m_AnalogPosition_position = m_simDevice.CreateDouble("AnalogPosition_position", false, 0);
    m_AnalogVelocityConversionFactor_conversion = m_simDevice.CreateDouble("AnalogVelocityConversionFactor_conversion", false, 0);
    m_AnalogVelocity_velocity = m_simDevice.CreateDouble("AnalogVelocity_velocity", false, 0);
    m_AnalogVoltage_voltage = m_simDevice.CreateDouble("AnalogVoltage_voltage", false, 0);
    m_AppliedOutput_appliedOutput = m_simDevice.CreateDouble("AppliedOutput_appliedOutput", false, 0);
    m_AverageDepth_depth = m_simDevice.CreateDouble("AverageDepth_depth", false, 0);
    m_BusVoltage_busVoltage = m_simDevice.CreateDouble("BusVoltage_busVoltage", false, 0);
    m_CloseTelemetryStream_telemetryHandle = m_simDevice.CreateDouble("CloseTelemetryStream_telemetryHandle", false, 0);
    m_ClosedLoopRampRate_rate = m_simDevice.CreateDouble("ClosedLoopRampRate_rate", false, 0);
    m_ControlFramePeriod_periodMs = m_simDevice.CreateDouble("ControlFramePeriod_periodMs", false, 0);
    m_CountsPerRevolution_cpr = m_simDevice.CreateDouble("CountsPerRevolution_cpr", false, 0);
    m_DRVStatus_drvStatus = m_simDevice.CreateDouble("DRVStatus_drvStatus", false, 0);
    m_DataPortConfig_config = m_simDevice.CreateDouble("DataPortConfig_config", false, 0);
    m_DeviceId_deviceId = m_simDevice.CreateDouble("DeviceId_deviceId", false, 0);
    m_EnableLimitSwitch_enable = m_simDevice.CreateDouble("EnableLimitSwitch_enable", false, 0);
    m_EnableLimitSwitch_sw = m_simDevice.CreateDouble("EnableLimitSwitch_sw", false, 0);
    m_EnableSoftLimit_dir = m_simDevice.CreateDouble("EnableSoftLimit_dir", false, 0);
    m_EnableSoftLimit_enable = m_simDevice.CreateDouble("EnableSoftLimit_enable", false, 0);
    m_EnableVoltageCompensation_nominalVoltage = m_simDevice.CreateDouble("EnableVoltageCompensation_nominalVoltage", false, 0);
    m_EncoderInverted_inverted = m_simDevice.CreateDouble("EncoderInverted_inverted", false, 0);
    m_EncoderPosition_position = m_simDevice.CreateDouble("EncoderPosition_position", false, 0);
    m_EncoderVelocity_velocity = m_simDevice.CreateDouble("EncoderVelocity_velocity", false, 0);
    m_FactoryWipe_persist = m_simDevice.CreateDouble("FactoryWipe_persist", false, 0);
    m_Fault_fault = m_simDevice.CreateDouble("Fault_fault", false, 0);
    m_Fault_faultId = m_simDevice.CreateDouble("Fault_faultId", false, 0);
    m_Faults_faults = m_simDevice.CreateDouble("Faults_faults", false, 0);
    m_FeedbackDeviceID_id = m_simDevice.CreateDouble("FeedbackDeviceID_id", false, 0);
    m_FeedbackDeviceRange_max = m_simDevice.CreateDouble("FeedbackDeviceRange_max", false, 0);
    m_FeedbackDeviceRange_min = m_simDevice.CreateDouble("FeedbackDeviceRange_min", false, 0);
    m_FeedbackDevice_sensorID = m_simDevice.CreateDouble("FeedbackDevice_sensorID", false, 0);
    m_Follow_followerArbId = m_simDevice.CreateDouble("Follow_followerArbId", false, 0);
    m_Follow_followerCfg = m_simDevice.CreateDouble("Follow_followerCfg", false, 0);
    m_Follower_isFollower = m_simDevice.CreateDouble("Follower_isFollower", false, 0);
    m_GenerateError_deviceID = m_simDevice.CreateDouble("GenerateError_deviceID", false, 0);
    m_GenerateError_error = m_simDevice.CreateDouble("GenerateError_error", false, 0);
    m_IAccum_iAccum = m_simDevice.CreateDouble("IAccum_iAccum", false, 0);
    m_IDAssign_deviceId = m_simDevice.CreateDouble("IDAssign_deviceId", false, 0);
    m_IDAssign_uniqueId = m_simDevice.CreateDouble("IDAssign_uniqueId", false, 0);
    m_IDQuery_numberOfDevices = m_simDevice.CreateDouble("IDQuery_numberOfDevices", false, 0);
    m_IDQuery_uniqueIdArray = m_simDevice.CreateDouble("IDQuery_uniqueIdArray", false, 0);
    m_IDQuery_uniqueIdArraySize = m_simDevice.CreateDouble("IDQuery_uniqueIdArraySize", false, 0);
    m_IdentifyUniqueId_uniqueId = m_simDevice.CreateDouble("IdentifyUniqueId_uniqueId", false, 0);
    m_IdleMode_idlemode = m_simDevice.CreateDouble("IdleMode_idlemode", false, 0);
    m_Inverted_inverted = m_simDevice.CreateDouble("Inverted_inverted", false, 0);
    m_LastError_error = m_simDevice.CreateDouble("LastError_error", false, 0);
    m_LimitEnabled_enabled = m_simDevice.CreateDouble("LimitEnabled_enabled", false, 0);
    m_LimitEnabled_sw = m_simDevice.CreateDouble("LimitEnabled_sw", false, 0);
    m_LimitPolarity_polarity = m_simDevice.CreateDouble("LimitPolarity_polarity", false, 0);
    m_LimitPolarity_sw = m_simDevice.CreateDouble("LimitPolarity_sw", false, 0);
    m_LimitSwitch_limit = m_simDevice.CreateDouble("LimitSwitch_limit", false, 0);
    m_LimitSwitch_sw = m_simDevice.CreateDouble("LimitSwitch_sw", false, 0);
    m_ListTelemetryStream_messages = m_simDevice.CreateDouble("ListTelemetryStream_messages", false, 0);
    m_MeasurementPeriod_samples = m_simDevice.CreateDouble("MeasurementPeriod_samples", false, 0);
    m_MotorTemperature_motorTemperature = m_simDevice.CreateDouble("MotorTemperature_motorTemperature", false, 0);
    m_MotorType_type = m_simDevice.CreateDouble("MotorType_type", false, 0);
    m_OpenLoopRampRate_rate = m_simDevice.CreateDouble("OpenLoopRampRate_rate", false, 0);
    m_OpenTelemetryStream_telemetryHandle = m_simDevice.CreateDouble("OpenTelemetryStream_telemetryHandle", false, 0);
    m_OutputCurrent_outputCurrent = m_simDevice.CreateDouble("OutputCurrent_outputCurrent", false, 0);
    m_ParameterBool_paramId = m_simDevice.CreateDouble("ParameterBool_paramId", false, 0);
    m_ParameterBool_value = m_simDevice.CreateDouble("ParameterBool_value", false, 0);
    m_ParameterFloat32_paramId = m_simDevice.CreateDouble("ParameterFloat32_paramId", false, 0);
    m_ParameterFloat32_value = m_simDevice.CreateDouble("ParameterFloat32_value", false, 0);
    m_ParameterInt32_paramId = m_simDevice.CreateDouble("ParameterInt32_paramId", false, 0);
    m_ParameterInt32_value = m_simDevice.CreateDouble("ParameterInt32_value", false, 0);
    m_ParameterUint32_paramId = m_simDevice.CreateDouble("ParameterUint32_paramId", false, 0);
    m_ParameterUint32_value = m_simDevice.CreateDouble("ParameterUint32_value", false, 0);
    m_PeriodicFramePeriod_frameId = m_simDevice.CreateDouble("PeriodicFramePeriod_frameId", false, 0);
    m_PeriodicFramePeriod_periodMs = m_simDevice.CreateDouble("PeriodicFramePeriod_periodMs", false, 0);
    m_PeriodicStatus0_rawframe = m_simDevice.CreateDouble("PeriodicStatus0_rawframe", false, 0);
    m_PeriodicStatus1_rawframe = m_simDevice.CreateDouble("PeriodicStatus1_rawframe", false, 0);
    m_PeriodicStatus2_rawframe = m_simDevice.CreateDouble("PeriodicStatus2_rawframe", false, 0);
    m_PeriodicStatus3_rawframe = m_simDevice.CreateDouble("PeriodicStatus3_rawframe", false, 0);
    m_PeriodicStatus4_rawframe = m_simDevice.CreateDouble("PeriodicStatus4_rawframe", false, 0);
    m_PositionConversionFactor_conversion = m_simDevice.CreateDouble("PositionConversionFactor_conversion", false, 0);
    m_ReadTelemetryStream_ids = m_simDevice.CreateDouble("ReadTelemetryStream_ids", false, 0);
    m_ReadTelemetryStream_messages = m_simDevice.CreateDouble("ReadTelemetryStream_messages", false, 0);
    m_ReadTelemetryStream_numOfStreams = m_simDevice.CreateDouble("ReadTelemetryStream_numOfStreams", false, 0);
    m_ReadTelemetryStream_telemetryHandle = m_simDevice.CreateDouble("ReadTelemetryStream_telemetryHandle", false, 0);
    m_RestoreFactoryDefaults_persist = m_simDevice.CreateDouble("RestoreFactoryDefaults_persist", false, 0);
    m_SecondaryCurrentLimit_chopCycles = m_simDevice.CreateDouble("SecondaryCurrentLimit_chopCycles", false, 0);
    m_SecondaryCurrentLimit_limit = m_simDevice.CreateDouble("SecondaryCurrentLimit_limit", false, 0);
    m_SensorType_sensorType = m_simDevice.CreateDouble("SensorType_sensorType", false, 0);
    m_SerialNumber_serialNumber_0 = m_simDevice.CreateDouble("SerialNumber_serialNumber_0", false, 0);
    m_SerialNumber_serialNumber_1 = m_simDevice.CreateDouble("SerialNumber_serialNumber_1", false, 0);
    m_SerialNumber_serialNumber_2 = m_simDevice.CreateDouble("SerialNumber_serialNumber_2", false, 0);
    m_SmartCurrentLimit_freeLimit = m_simDevice.CreateDouble("SmartCurrentLimit_freeLimit", false, 0);
    m_SmartCurrentLimit_limitRPM = m_simDevice.CreateDouble("SmartCurrentLimit_limitRPM", false, 0);
    m_SmartCurrentLimit_stallLimit = m_simDevice.CreateDouble("SmartCurrentLimit_stallLimit", false, 0);
    m_SoftLimitEnabled_dir = m_simDevice.CreateDouble("SoftLimitEnabled_dir", false, 0);
    m_SoftLimitEnabled_enabled = m_simDevice.CreateDouble("SoftLimitEnabled_enabled", false, 0);
    m_SoftLimit_dir = m_simDevice.CreateDouble("SoftLimit_dir", false, 0);
    m_SoftLimit_limit = m_simDevice.CreateDouble("SoftLimit_limit", false, 0);
    m_StickyFault_faultId = m_simDevice.CreateDouble("StickyFault_faultId", false, 0);
    m_StickyFault_stickyfault = m_simDevice.CreateDouble("StickyFault_stickyfault", false, 0);
    m_StickyFaults_stickyFaults = m_simDevice.CreateDouble("StickyFaults_stickyFaults", false, 0);
    m_VelocityConversionFactor_conversion = m_simDevice.CreateDouble("VelocityConversionFactor_conversion", false, 0);
    m_VoltageCompensationNominalVoltage_nominalVoltage = m_simDevice.CreateDouble("VoltageCompensationNominalVoltage_nominalVoltage", false, 0);
    m_pointCommand_arbFFUnits = m_simDevice.CreateDouble("pointCommand_arbFFUnits", false, 0);
    m_pointCommand_arbFeedforward = m_simDevice.CreateDouble("pointCommand_arbFeedforward", false, 0);
    m_pointCommand_ctrl = m_simDevice.CreateDouble("pointCommand_ctrl", false, 0);
    m_pointCommand_pidSlot = m_simDevice.CreateDouble("pointCommand_pidSlot", false, 0);
    m_pointCommand_value = m_simDevice.CreateDouble("pointCommand_value", false, 0);

    for (int slotID = 0; slotID < 6; ++slotID)
    {
        m_slotted_variables[slotID].m_DFilter_gain = m_simDevice.CreateDouble(std::string("DFilter_gain[" + std::to_string(slotID) + "]").c_str(), false, 0);
        m_slotted_variables[slotID].m_D_gain = m_simDevice.CreateDouble(std::string("D_gain[" + std::to_string(slotID) + "]").c_str(), false, 0);
        m_slotted_variables[slotID].m_FF_gain = m_simDevice.CreateDouble(std::string("FF_gain[" + std::to_string(slotID) + "]").c_str(), false, 0);
        m_slotted_variables[slotID].m_IMaxAccum_iMaxAccum = m_simDevice.CreateDouble(std::string("IMaxAccum_iMaxAccum[" + std::to_string(slotID) + "]").c_str(), false, 0);
        m_slotted_variables[slotID].m_IZone_IZone = m_simDevice.CreateDouble(std::string("IZone_IZone[" + std::to_string(slotID) + "]").c_str(), false, 0);
        m_slotted_variables[slotID].m_I_gain = m_simDevice.CreateDouble(std::string("I_gain[" + std::to_string(slotID) + "]").c_str(), false, 0);
        m_slotted_variables[slotID].m_OutputMax_max = m_simDevice.CreateDouble(std::string("OutputMax_max[" + std::to_string(slotID) + "]").c_str(), false, 0);
        m_slotted_variables[slotID].m_OutputMin_min = m_simDevice.CreateDouble(std::string("OutputMin_min[" + std::to_string(slotID) + "]").c_str(), false, 0);
        m_slotted_variables[slotID].m_OutputRange_max = m_simDevice.CreateDouble(std::string("OutputRange_max[" + std::to_string(slotID) + "]").c_str(), false, 0);
        m_slotted_variables[slotID].m_OutputRange_min = m_simDevice.CreateDouble(std::string("OutputRange_min[" + std::to_string(slotID) + "]").c_str(), false, 0);
        m_slotted_variables[slotID].m_P_gain = m_simDevice.CreateDouble(std::string("P_gain[" + std::to_string(slotID) + "]").c_str(), false, 0);
        m_slotted_variables[slotID].m_SmartMotionAccelStrategy_accelStrategy = m_simDevice.CreateDouble(std::string("SmartMotionAccelStrategy_accelStrategy[" + std::to_string(slotID) + "]").c_str(), false, 0);
        m_slotted_variables[slotID].m_SmartMotionAllowedClosedLoopError_allowedError = m_simDevice.CreateDouble(std::string("SmartMotionAllowedClosedLoopError_allowedError[" + std::to_string(slotID) + "]").c_str(), false, 0);
        m_slotted_variables[slotID].m_SmartMotionMaxAccel_maxAccel = m_simDevice.CreateDouble(std::string("SmartMotionMaxAccel_maxAccel[" + std::to_string(slotID) + "]").c_str(), false, 0);
        m_slotted_variables[slotID].m_SmartMotionMaxVelocity_maxVel = m_simDevice.CreateDouble(std::string("SmartMotionMaxVelocity_maxVel[" + std::to_string(slotID) + "]").c_str(), false, 0);
        m_slotted_variables[slotID].m_SmartMotionMinOutputVelocity_minVel = m_simDevice.CreateDouble(std::string("SmartMotionMinOutputVelocity_minVel[" + std::to_string(slotID) + "]").c_str(), false, 0);
    }

    Send("Create");
}

void SnobotSim::RevCANSparkMaxDriverWrapper::Send(const std::string& aName,
        uint8_t* aBuffer, int aSize)
{
    if (!gCANSparkMaxDriverCallbacks.empty())
    {
        gCANSparkMaxDriverCallbacks[0](aName.c_str(), mDeviceId, aBuffer, aSize);
    }
    else
    {
        LOG_UNSUPPORTED_CAN_FUNC("Callback " << aName << " not registered");
    }
}

void SnobotSim::RevCANSparkMaxDriverWrapper::Receive(const std::string& aName,
        uint8_t* aBuffer,
        int aSize)
{
    if (!gCANSparkMaxDriverCallbacks.empty())
    {
        gCANSparkMaxDriverCallbacks[0](aName.c_str(), mDeviceId, aBuffer, aSize);
    }
    else
    {
        LOG_UNSUPPORTED_CAN_FUNC("Callback " << aName << " not registered");
    }
}

void SnobotSim::RevCANSparkMaxDriverWrapper::GetFirmwareVersion(c_SparkMax_FirmwareVersion* fwVersion)
{
    RECEIVE_HELPER("GetFirmwareVersion", sizeof(*fwVersion));
    PoplateReceiveResults(buffer, fwVersion, buffer_pos);

}

void SnobotSim::RevCANSparkMaxDriverWrapper::GetSerialNumber(uint32_t* serialNumber[3])
{
    RECEIVE_HELPER("GetSerialNumber", sizeof(*serialNumber[0]) + sizeof(*serialNumber[1]) + sizeof(*serialNumber[2]));
    PoplateReceiveResults(buffer, serialNumber[0], buffer_pos);
    PoplateReceiveResults(buffer, serialNumber[1], buffer_pos);
    PoplateReceiveResults(buffer, serialNumber[2], buffer_pos);

    *serialNumber_2 = m_SerialNumber_serialNumber_2.Get();
    *serialNumber_1 = m_SerialNumber_serialNumber_1.Get();
    *serialNumber_0 = m_SerialNumber_serialNumber_0.Get();
}

void SnobotSim::RevCANSparkMaxDriverWrapper::GetDeviceId(int* deviceId)
{
    RECEIVE_HELPER("GetDeviceId", sizeof(*deviceId));
    PoplateReceiveResults(buffer, deviceId, buffer_pos);

    *deviceId = m_DeviceId_deviceId.Get();
}

void SnobotSim::RevCANSparkMaxDriverWrapper::SetMotorType(c_SparkMax_MotorType type)
{
    m_MotorType_type.Set(type);

    Send("SetMotorType", type);
}

void SnobotSim::RevCANSparkMaxDriverWrapper::GetMotorType(c_SparkMax_MotorType* type)
{
    RECEIVE_HELPER("GetMotorType", sizeof(*type));
    PoplateReceiveResults(buffer, type, buffer_pos);

    *type = static_cast<c_SparkMax_MotorType>(static_cast<int>(m_MotorType_type.Get()));
}

void SnobotSim::RevCANSparkMaxDriverWrapper::SetPeriodicFramePeriod(c_SparkMax_PeriodicFrame frameId, int periodMs)
{
    m_PeriodicFramePeriod_periodMs.Set(periodMs);
    m_PeriodicFramePeriod_frameId.Set(frameId);

    Send("SetPeriodicFramePeriod", frameId, periodMs);
}

void SnobotSim::RevCANSparkMaxDriverWrapper::SetControlFramePeriod(int periodMs)
{
    m_ControlFramePeriod_periodMs.Set(periodMs);

    Send("SetControlFramePeriod", periodMs);
}

void SnobotSim::RevCANSparkMaxDriverWrapper::SetParameterFloat32(c_SparkMax_ConfigParameter paramId, float value)
{
    m_ParameterFloat32_value.Set(value);
    m_ParameterFloat32_paramId.Set(paramId);

    Send("SetParameterFloat32", paramId, value);
}

void SnobotSim::RevCANSparkMaxDriverWrapper::SetParameterInt32(c_SparkMax_ConfigParameter paramId, int32_t value)
{
    m_ParameterInt32_value.Set(value);
    m_ParameterInt32_paramId.Set(paramId);

    Send("SetParameterInt32", paramId, value);
}

void SnobotSim::RevCANSparkMaxDriverWrapper::SetParameterUint32(c_SparkMax_ConfigParameter paramId, uint32_t value)
{
    m_ParameterUint32_value.Set(value);
    m_ParameterUint32_paramId.Set(paramId);

    Send("SetParameterUint32", paramId, value);
}

void SnobotSim::RevCANSparkMaxDriverWrapper::SetParameterBool(c_SparkMax_ConfigParameter paramId, uint8_t value)
{
    m_ParameterBool_value.Set(value);
    m_ParameterBool_paramId.Set(paramId);

    Send("SetParameterBool", paramId, value);
}

void SnobotSim::RevCANSparkMaxDriverWrapper::GetParameterFloat32(c_SparkMax_ConfigParameter paramId, float* value)
{
    RECEIVE_HELPER("GetParameterFloat32", sizeof(paramId) + sizeof(*value));
    PoplateReceiveResults(buffer, &paramId, buffer_pos);
    PoplateReceiveResults(buffer, value, buffer_pos);

    *value = m_ParameterFloat32_value.Get();
    *paramId = static_cast<c_SparkMax_ConfigParameter>(static_cast<int>(m_ParameterFloat32_paramId.Get()));
}

void SnobotSim::RevCANSparkMaxDriverWrapper::GetParameterInt32(c_SparkMax_ConfigParameter paramId, int32_t* value)
{
    RECEIVE_HELPER("GetParameterInt32", sizeof(paramId) + sizeof(*value));
    PoplateReceiveResults(buffer, &paramId, buffer_pos);
    PoplateReceiveResults(buffer, value, buffer_pos);

    *value = m_ParameterInt32_value.Get();
    *paramId = static_cast<c_SparkMax_ConfigParameter>(static_cast<int>(m_ParameterInt32_paramId.Get()));
}

void SnobotSim::RevCANSparkMaxDriverWrapper::GetParameterUint32(c_SparkMax_ConfigParameter paramId, uint32_t* value)
{
    RECEIVE_HELPER("GetParameterUint32", sizeof(paramId) + sizeof(*value));
    PoplateReceiveResults(buffer, &paramId, buffer_pos);
    PoplateReceiveResults(buffer, value, buffer_pos);

    *value = m_ParameterUint32_value.Get();
    *paramId = static_cast<c_SparkMax_ConfigParameter>(static_cast<int>(m_ParameterUint32_paramId.Get()));
}

void SnobotSim::RevCANSparkMaxDriverWrapper::GetParameterBool(c_SparkMax_ConfigParameter paramId, uint8_t* value)
{
    RECEIVE_HELPER("GetParameterBool", sizeof(paramId) + sizeof(*value));
    PoplateReceiveResults(buffer, &paramId, buffer_pos);
    PoplateReceiveResults(buffer, value, buffer_pos);

    *value = static_cast<uint8_t>(static_cast<int>(m_ParameterBool_value.Get()));
    *paramId = static_cast<c_SparkMax_ConfigParameter>(static_cast<int>(m_ParameterBool_paramId.Get()));
}

void SnobotSim::RevCANSparkMaxDriverWrapper::GetPeriodicStatus0(c_SparkMax_PeriodicStatus0* rawframe)
{
    RECEIVE_HELPER("GetPeriodicStatus0", sizeof(*rawframe));
    PoplateReceiveResults(buffer, rawframe, buffer_pos);

    *rawframe = m_PeriodicStatus0_rawframe.Get();
}

void SnobotSim::RevCANSparkMaxDriverWrapper::GetPeriodicStatus1(c_SparkMax_PeriodicStatus1* rawframe)
{
    RECEIVE_HELPER("GetPeriodicStatus1", sizeof(*rawframe));
    PoplateReceiveResults(buffer, rawframe, buffer_pos);

    *rawframe = m_PeriodicStatus1_rawframe.Get();
}

void SnobotSim::RevCANSparkMaxDriverWrapper::GetPeriodicStatus2(c_SparkMax_PeriodicStatus2* rawframe)
{
    RECEIVE_HELPER("GetPeriodicStatus2", sizeof(*rawframe));
    PoplateReceiveResults(buffer, rawframe, buffer_pos);

    *rawframe = m_PeriodicStatus2_rawframe.Get();
}

void SnobotSim::RevCANSparkMaxDriverWrapper::GetPeriodicStatus3(c_SparkMax_PeriodicStatus3* rawframe)
{
    RECEIVE_HELPER("GetPeriodicStatus3", sizeof(*rawframe));
    PoplateReceiveResults(buffer, rawframe, buffer_pos);

    *rawframe = m_PeriodicStatus3_rawframe.Get();
}

void SnobotSim::RevCANSparkMaxDriverWrapper::GetPeriodicStatus4(c_SparkMax_PeriodicStatus4* rawframe)
{
    RECEIVE_HELPER("GetPeriodicStatus4", sizeof(*rawframe));
    PoplateReceiveResults(buffer, rawframe, buffer_pos);

    *rawframe = m_PeriodicStatus4_rawframe.Get();
}

void SnobotSim::RevCANSparkMaxDriverWrapper::SetEncoderPosition(float position)
{
    m_EncoderPosition_position.Set(position);

    Send("SetEncoderPosition", position);
}

void SnobotSim::RevCANSparkMaxDriverWrapper::SetAltEncoderPosition(float position)
{
    m_AltEncoderPosition_position.Set(position);

    Send("SetAltEncoderPosition", position);
}

void SnobotSim::RevCANSparkMaxDriverWrapper::RestoreFactoryDefaults(uint8_t persist)
{
    m_RestoreFactoryDefaults_persist.Set(persist);

    Send("RestoreFactoryDefaults", persist);
}

void SnobotSim::RevCANSparkMaxDriverWrapper::FactoryWipe(uint8_t persist)
{
    m_FactoryWipe_persist.Set(persist);

    Send("FactoryWipe", persist);
}

void SnobotSim::RevCANSparkMaxDriverWrapper::SetFollow(uint32_t followerArbId, uint32_t followerCfg)
{
    m_Follow_followerCfg.Set(followerCfg);
    m_Follow_followerArbId.Set(followerArbId);

    Send("SetFollow", followerArbId, followerCfg);
}

void SnobotSim::RevCANSparkMaxDriverWrapper::SetpointCommand(float value, c_SparkMax_ControlType ctrl, int pidSlot, float arbFeedforward, int arbFFUnits)
{
    m_pointCommand_value.Set(value);
    m_pointCommand_pidSlot.Set(pidSlot);
    m_pointCommand_ctrl.Set(ctrl);
    m_pointCommand_arbFeedforward.Set(arbFeedforward);
    m_pointCommand_arbFFUnits.Set(arbFFUnits);

    Send("SetpointCommand", value, ctrl, pidSlot, arbFeedforward, arbFFUnits);
}

void SnobotSim::RevCANSparkMaxDriverWrapper::GetDRVStatus(c_SparkMax_DRVStatus* drvStatus)
{
    RECEIVE_HELPER("GetDRVStatus", sizeof(*drvStatus));
    PoplateReceiveResults(buffer, drvStatus, buffer_pos);

    *drvStatus = m_DRVStatus_drvStatus.Get();
}

void SnobotSim::RevCANSparkMaxDriverWrapper::SetInverted(uint8_t inverted)
{
    m_Inverted_inverted.Set(inverted);

    Send("SetInverted", inverted);
}

void SnobotSim::RevCANSparkMaxDriverWrapper::GetInverted(uint8_t* inverted)
{
    RECEIVE_HELPER("GetInverted", sizeof(*inverted));
    PoplateReceiveResults(buffer, inverted, buffer_pos);

    *inverted = static_cast<uint8_t>(static_cast<int>(m_Inverted_inverted.Get()));
}

void SnobotSim::RevCANSparkMaxDriverWrapper::SetSmartCurrentLimit(uint8_t stallLimit, uint8_t freeLimit, uint32_t limitRPM)
{
    m_SmartCurrentLimit_stallLimit.Set(stallLimit);
    m_SmartCurrentLimit_limitRPM.Set(limitRPM);
    m_SmartCurrentLimit_freeLimit.Set(freeLimit);

    Send("SetSmartCurrentLimit", stallLimit, freeLimit, limitRPM);
}

void SnobotSim::RevCANSparkMaxDriverWrapper::GetSmartCurrentLimit(uint8_t* stallLimit, uint8_t* freeLimit, uint32_t* limitRPM)
{
    RECEIVE_HELPER("GetSmartCurrentLimit", sizeof(*stallLimit) + sizeof(*freeLimit) + sizeof(*limitRPM));
    PoplateReceiveResults(buffer, stallLimit, buffer_pos);
    PoplateReceiveResults(buffer, freeLimit, buffer_pos);
    PoplateReceiveResults(buffer, limitRPM, buffer_pos);

    *stallLimit = static_cast<uint8_t>(static_cast<int>(m_SmartCurrentLimit_stallLimit.Get()));
    *limitRPM = m_SmartCurrentLimit_limitRPM.Get();
    *freeLimit = static_cast<uint8_t>(static_cast<int>(m_SmartCurrentLimit_freeLimit.Get()));
}

void SnobotSim::RevCANSparkMaxDriverWrapper::SetSecondaryCurrentLimit(float limit, int chopCycles)
{
    m_SecondaryCurrentLimit_limit.Set(limit);
    m_SecondaryCurrentLimit_chopCycles.Set(chopCycles);

    Send("SetSecondaryCurrentLimit", limit, chopCycles);
}

void SnobotSim::RevCANSparkMaxDriverWrapper::GetSecondaryCurrentLimit(float* limit, int* chopCycles)
{
    RECEIVE_HELPER("GetSecondaryCurrentLimit", sizeof(*limit) + sizeof(*chopCycles));
    PoplateReceiveResults(buffer, limit, buffer_pos);
    PoplateReceiveResults(buffer, chopCycles, buffer_pos);

    *limit = m_SecondaryCurrentLimit_limit.Get();
    *chopCycles = m_SecondaryCurrentLimit_chopCycles.Get();
}

void SnobotSim::RevCANSparkMaxDriverWrapper::SetIdleMode(c_SparkMax_IdleMode idlemode)
{
    m_IdleMode_idlemode.Set(idlemode);

    Send("SetIdleMode", idlemode);
}

void SnobotSim::RevCANSparkMaxDriverWrapper::GetIdleMode(c_SparkMax_IdleMode* idlemode)
{
    RECEIVE_HELPER("GetIdleMode", sizeof(*idlemode));
    PoplateReceiveResults(buffer, idlemode, buffer_pos);

    *idlemode = static_cast<c_SparkMax_IdleMode>(static_cast<int>(m_IdleMode_idlemode.Get()));
}

void SnobotSim::RevCANSparkMaxDriverWrapper::EnableVoltageCompensation(float nominalVoltage)
{
    m_EnableVoltageCompensation_nominalVoltage.Set(nominalVoltage);

    Send("EnableVoltageCompensation", nominalVoltage);
}

void SnobotSim::RevCANSparkMaxDriverWrapper::GetVoltageCompensationNominalVoltage(float* nominalVoltage)
{
    RECEIVE_HELPER("GetVoltageCompensationNominalVoltage", sizeof(*nominalVoltage));
    PoplateReceiveResults(buffer, nominalVoltage, buffer_pos);

    *nominalVoltage = m_VoltageCompensationNominalVoltage_nominalVoltage.Get();
}

void SnobotSim::RevCANSparkMaxDriverWrapper::DisableVoltageCompensation()
{

    Send("DisableVoltageCompensation");
}

void SnobotSim::RevCANSparkMaxDriverWrapper::SetOpenLoopRampRate(float rate)
{
    m_OpenLoopRampRate_rate.Set(rate);

    Send("SetOpenLoopRampRate", rate);
}

void SnobotSim::RevCANSparkMaxDriverWrapper::GetOpenLoopRampRate(float* rate)
{
    RECEIVE_HELPER("GetOpenLoopRampRate", sizeof(*rate));
    PoplateReceiveResults(buffer, rate, buffer_pos);

    *rate = m_OpenLoopRampRate_rate.Get();
}

void SnobotSim::RevCANSparkMaxDriverWrapper::SetClosedLoopRampRate(float rate)
{
    m_ClosedLoopRampRate_rate.Set(rate);

    Send("SetClosedLoopRampRate", rate);
}

void SnobotSim::RevCANSparkMaxDriverWrapper::GetClosedLoopRampRate(float* rate)
{
    RECEIVE_HELPER("GetClosedLoopRampRate", sizeof(*rate));
    PoplateReceiveResults(buffer, rate, buffer_pos);

    *rate = m_ClosedLoopRampRate_rate.Get();
}

void SnobotSim::RevCANSparkMaxDriverWrapper::IsFollower(uint8_t* isFollower)
{
    RECEIVE_HELPER("IsFollower", sizeof(*isFollower));
    PoplateReceiveResults(buffer, isFollower, buffer_pos);

    *isFollower = static_cast<uint8_t>(static_cast<int>(m_Follower_isFollower.Get()));
}

void SnobotSim::RevCANSparkMaxDriverWrapper::GetFaults(uint16_t* faults)
{
    RECEIVE_HELPER("GetFaults", sizeof(*faults));
    PoplateReceiveResults(buffer, faults, buffer_pos);

    *faults = m_Faults_faults.Get();
}

void SnobotSim::RevCANSparkMaxDriverWrapper::GetStickyFaults(uint16_t* stickyFaults)
{
    RECEIVE_HELPER("GetStickyFaults", sizeof(*stickyFaults));
    PoplateReceiveResults(buffer, stickyFaults, buffer_pos);

    *stickyFaults = m_StickyFaults_stickyFaults.Get();
}

void SnobotSim::RevCANSparkMaxDriverWrapper::GetFault(c_SparkMax_FaultID faultId, uint8_t* fault)
{
    RECEIVE_HELPER("GetFault", sizeof(faultId) + sizeof(*fault));
    PoplateReceiveResults(buffer, &faultId, buffer_pos);
    PoplateReceiveResults(buffer, fault, buffer_pos);

    *faultId = static_cast<c_SparkMax_FaultID>(static_cast<int>(m_Fault_faultId.Get()));
    *fault = static_cast<uint8_t>(static_cast<int>(m_Fault_fault.Get()));
}

void SnobotSim::RevCANSparkMaxDriverWrapper::GetStickyFault(c_SparkMax_FaultID faultId, uint8_t* stickyfault)
{
    RECEIVE_HELPER("GetStickyFault", sizeof(faultId) + sizeof(*stickyfault));
    PoplateReceiveResults(buffer, &faultId, buffer_pos);
    PoplateReceiveResults(buffer, stickyfault, buffer_pos);

    *stickyfault = static_cast<uint8_t>(static_cast<int>(m_StickyFault_stickyfault.Get()));
    *faultId = static_cast<c_SparkMax_FaultID>(static_cast<int>(m_StickyFault_faultId.Get()));
}

void SnobotSim::RevCANSparkMaxDriverWrapper::GetBusVoltage(float* busVoltage)
{
    RECEIVE_HELPER("GetBusVoltage", sizeof(*busVoltage));
    PoplateReceiveResults(buffer, busVoltage, buffer_pos);

    *busVoltage = m_BusVoltage_busVoltage.Get();
}

void SnobotSim::RevCANSparkMaxDriverWrapper::GetAppliedOutput(float* appliedOutput)
{
    RECEIVE_HELPER("GetAppliedOutput", sizeof(*appliedOutput));
    PoplateReceiveResults(buffer, appliedOutput, buffer_pos);

    *appliedOutput = m_AppliedOutput_appliedOutput.Get();
}

void SnobotSim::RevCANSparkMaxDriverWrapper::GetOutputCurrent(float* outputCurrent)
{
    RECEIVE_HELPER("GetOutputCurrent", sizeof(*outputCurrent));
    PoplateReceiveResults(buffer, outputCurrent, buffer_pos);

    *outputCurrent = m_OutputCurrent_outputCurrent.Get();
}

void SnobotSim::RevCANSparkMaxDriverWrapper::GetMotorTemperature(float* motorTemperature)
{
    RECEIVE_HELPER("GetMotorTemperature", sizeof(*motorTemperature));
    PoplateReceiveResults(buffer, motorTemperature, buffer_pos);

    *motorTemperature = m_MotorTemperature_motorTemperature.Get();
}

void SnobotSim::RevCANSparkMaxDriverWrapper::ClearFaults()
{

    Send("ClearFaults");
}

void SnobotSim::RevCANSparkMaxDriverWrapper::BurnFlash()
{

    Send("BurnFlash");
}

void SnobotSim::RevCANSparkMaxDriverWrapper::EnableSoftLimit(c_SparkMax_LimitDirection dir, uint8_t enable)
{
    m_EnableSoftLimit_enable.Set(enable);
    m_EnableSoftLimit_dir.Set(dir);

    Send("EnableSoftLimit", dir, enable);
}

void SnobotSim::RevCANSparkMaxDriverWrapper::IsSoftLimitEnabled(c_SparkMax_LimitDirection dir, uint8_t* enabled)
{
    RECEIVE_HELPER("IsSoftLimitEnabled", sizeof(dir) + sizeof(*enabled));
    PoplateReceiveResults(buffer, &dir, buffer_pos);
    PoplateReceiveResults(buffer, enabled, buffer_pos);

    *enabled = static_cast<uint8_t>(static_cast<int>(m_SoftLimitEnabled_enabled.Get()));
    *dir = static_cast<c_SparkMax_LimitDirection>(static_cast<int>(m_SoftLimitEnabled_dir.Get()));
}

void SnobotSim::RevCANSparkMaxDriverWrapper::SetSoftLimit(c_SparkMax_LimitDirection dir, float limit)
{
    m_SoftLimit_limit.Set(limit);
    m_SoftLimit_dir.Set(dir);

    Send("SetSoftLimit", dir, limit);
}

void SnobotSim::RevCANSparkMaxDriverWrapper::GetSoftLimit(c_SparkMax_LimitDirection dir, float* limit)
{
    RECEIVE_HELPER("GetSoftLimit", sizeof(dir) + sizeof(*limit));
    PoplateReceiveResults(buffer, &dir, buffer_pos);
    PoplateReceiveResults(buffer, limit, buffer_pos);

    *limit = m_SoftLimit_limit.Get();
    *dir = static_cast<c_SparkMax_LimitDirection>(static_cast<int>(m_SoftLimit_dir.Get()));
}

void SnobotSim::RevCANSparkMaxDriverWrapper::SetSensorType(c_SparkMax_EncoderType sensorType)
{
    m_SensorType_sensorType.Set(sensorType);

    Send("SetSensorType", sensorType);
}

void SnobotSim::RevCANSparkMaxDriverWrapper::Identify()
{

    Send("Identify");
}

void SnobotSim::RevCANSparkMaxDriverWrapper::SetLimitPolarity(c_SparkMax_LimitDirection sw, c_SparkMax_LimitPolarity polarity)
{
    m_LimitPolarity_sw.Set(sw);
    m_LimitPolarity_polarity.Set(polarity);

    Send("SetLimitPolarity", sw, polarity);
}

void SnobotSim::RevCANSparkMaxDriverWrapper::GetLimitPolarity(c_SparkMax_LimitDirection sw, c_SparkMax_LimitPolarity* polarity)
{
    RECEIVE_HELPER("GetLimitPolarity", sizeof(sw) + sizeof(*polarity));
    PoplateReceiveResults(buffer, &sw, buffer_pos);
    PoplateReceiveResults(buffer, polarity, buffer_pos);

    *sw = static_cast<c_SparkMax_LimitDirection>(static_cast<int>(m_LimitPolarity_sw.Get()));
    *polarity = static_cast<c_SparkMax_LimitPolarity>(static_cast<int>(m_LimitPolarity_polarity.Get()));
}

void SnobotSim::RevCANSparkMaxDriverWrapper::GetLimitSwitch(c_SparkMax_LimitDirection sw, uint8_t* limit)
{
    RECEIVE_HELPER("GetLimitSwitch", sizeof(sw) + sizeof(*limit));
    PoplateReceiveResults(buffer, &sw, buffer_pos);
    PoplateReceiveResults(buffer, limit, buffer_pos);

    *sw = static_cast<c_SparkMax_LimitDirection>(static_cast<int>(m_LimitSwitch_sw.Get()));
    *limit = static_cast<uint8_t>(static_cast<int>(m_LimitSwitch_limit.Get()));
}

void SnobotSim::RevCANSparkMaxDriverWrapper::EnableLimitSwitch(c_SparkMax_LimitDirection sw, uint8_t enable)
{
    m_EnableLimitSwitch_sw.Set(sw);
    m_EnableLimitSwitch_enable.Set(enable);

    Send("EnableLimitSwitch", sw, enable);
}

void SnobotSim::RevCANSparkMaxDriverWrapper::IsLimitEnabled(c_SparkMax_LimitDirection sw, uint8_t* enabled)
{
    RECEIVE_HELPER("IsLimitEnabled", sizeof(sw) + sizeof(*enabled));
    PoplateReceiveResults(buffer, &sw, buffer_pos);
    PoplateReceiveResults(buffer, enabled, buffer_pos);

    *sw = static_cast<c_SparkMax_LimitDirection>(static_cast<int>(m_LimitEnabled_sw.Get()));
    *enabled = static_cast<uint8_t>(static_cast<int>(m_LimitEnabled_enabled.Get()));
}

void SnobotSim::RevCANSparkMaxDriverWrapper::GetAnalogPosition(float* position)
{
    RECEIVE_HELPER("GetAnalogPosition", sizeof(*position));
    PoplateReceiveResults(buffer, position, buffer_pos);

    *position = m_AnalogPosition_position.Get();
}

void SnobotSim::RevCANSparkMaxDriverWrapper::GetAnalogVelocity(float* velocity)
{
    RECEIVE_HELPER("GetAnalogVelocity", sizeof(*velocity));
    PoplateReceiveResults(buffer, velocity, buffer_pos);

    *velocity = m_AnalogVelocity_velocity.Get();
}

void SnobotSim::RevCANSparkMaxDriverWrapper::GetAnalogVoltage(float* voltage)
{
    RECEIVE_HELPER("GetAnalogVoltage", sizeof(*voltage));
    PoplateReceiveResults(buffer, voltage, buffer_pos);

    *voltage = m_AnalogVoltage_voltage.Get();
}

void SnobotSim::RevCANSparkMaxDriverWrapper::SetAnalogPositionConversionFactor(float conversion)
{
    m_AnalogPositionConversionFactor_conversion.Set(conversion);

    Send("SetAnalogPositionConversionFactor", conversion);
}

void SnobotSim::RevCANSparkMaxDriverWrapper::SetAnalogVelocityConversionFactor(float conversion)
{
    m_AnalogVelocityConversionFactor_conversion.Set(conversion);

    Send("SetAnalogVelocityConversionFactor", conversion);
}

void SnobotSim::RevCANSparkMaxDriverWrapper::GetAnalogPositionConversionFactor(float* conversion)
{
    RECEIVE_HELPER("GetAnalogPositionConversionFactor", sizeof(*conversion));
    PoplateReceiveResults(buffer, conversion, buffer_pos);

    *conversion = m_AnalogPositionConversionFactor_conversion.Get();
}

void SnobotSim::RevCANSparkMaxDriverWrapper::GetAnalogVelocityConversionFactor(float* conversion)
{
    RECEIVE_HELPER("GetAnalogVelocityConversionFactor", sizeof(*conversion));
    PoplateReceiveResults(buffer, conversion, buffer_pos);

    *conversion = m_AnalogVelocityConversionFactor_conversion.Get();
}

void SnobotSim::RevCANSparkMaxDriverWrapper::SetAnalogInverted(uint8_t inverted)
{
    m_AnalogInverted_inverted.Set(inverted);

    Send("SetAnalogInverted", inverted);
}

void SnobotSim::RevCANSparkMaxDriverWrapper::GetAnalogInverted(uint8_t* inverted)
{
    RECEIVE_HELPER("GetAnalogInverted", sizeof(*inverted));
    PoplateReceiveResults(buffer, inverted, buffer_pos);

    *inverted = static_cast<uint8_t>(static_cast<int>(m_AnalogInverted_inverted.Get()));
}

void SnobotSim::RevCANSparkMaxDriverWrapper::SetAnalogAverageDepth(uint32_t depth)
{
    m_AnalogAverageDepth_depth.Set(depth);

    Send("SetAnalogAverageDepth", depth);
}

void SnobotSim::RevCANSparkMaxDriverWrapper::GetAnalogAverageDepth(uint32_t* depth)
{
    RECEIVE_HELPER("GetAnalogAverageDepth", sizeof(*depth));
    PoplateReceiveResults(buffer, depth, buffer_pos);

    *depth = m_AnalogAverageDepth_depth.Get();
}

void SnobotSim::RevCANSparkMaxDriverWrapper::SetAnalogMeasurementPeriod(uint32_t samples)
{
    m_AnalogMeasurementPeriod_samples.Set(samples);

    Send("SetAnalogMeasurementPeriod", samples);
}

void SnobotSim::RevCANSparkMaxDriverWrapper::GetAnalogMeasurementPeriod(uint32_t* samples)
{
    RECEIVE_HELPER("GetAnalogMeasurementPeriod", sizeof(*samples));
    PoplateReceiveResults(buffer, samples, buffer_pos);

    *samples = m_AnalogMeasurementPeriod_samples.Get();
}

void SnobotSim::RevCANSparkMaxDriverWrapper::SetAnalogMode(c_SparkMax_AnalogMode mode)
{
    m_AnalogMode_mode.Set(mode);

    Send("SetAnalogMode", mode);
}

void SnobotSim::RevCANSparkMaxDriverWrapper::GetAnalogMode(c_SparkMax_AnalogMode* mode)
{
    RECEIVE_HELPER("GetAnalogMode", sizeof(*mode));
    PoplateReceiveResults(buffer, mode, buffer_pos);

    *mode = static_cast<c_SparkMax_AnalogMode>(static_cast<int>(m_AnalogMode_mode.Get()));
}

void SnobotSim::RevCANSparkMaxDriverWrapper::GetEncoderPosition(float* position)
{
    RECEIVE_HELPER("GetEncoderPosition", sizeof(*position));
    PoplateReceiveResults(buffer, position, buffer_pos);

    *position = m_EncoderPosition_position.Get();
}

void SnobotSim::RevCANSparkMaxDriverWrapper::GetEncoderVelocity(float* velocity)
{
    RECEIVE_HELPER("GetEncoderVelocity", sizeof(*velocity));
    PoplateReceiveResults(buffer, velocity, buffer_pos);

    *velocity = m_EncoderVelocity_velocity.Get();
}

void SnobotSim::RevCANSparkMaxDriverWrapper::SetPositionConversionFactor(float conversion)
{
    m_PositionConversionFactor_conversion.Set(conversion);

    Send("SetPositionConversionFactor", conversion);
}

void SnobotSim::RevCANSparkMaxDriverWrapper::SetVelocityConversionFactor(float conversion)
{
    m_VelocityConversionFactor_conversion.Set(conversion);

    Send("SetVelocityConversionFactor", conversion);
}

void SnobotSim::RevCANSparkMaxDriverWrapper::GetPositionConversionFactor(float* conversion)
{
    RECEIVE_HELPER("GetPositionConversionFactor", sizeof(*conversion));
    PoplateReceiveResults(buffer, conversion, buffer_pos);

    *conversion = m_PositionConversionFactor_conversion.Get();
}

void SnobotSim::RevCANSparkMaxDriverWrapper::GetVelocityConversionFactor(float* conversion)
{
    RECEIVE_HELPER("GetVelocityConversionFactor", sizeof(*conversion));
    PoplateReceiveResults(buffer, conversion, buffer_pos);

    *conversion = m_VelocityConversionFactor_conversion.Get();
}

void SnobotSim::RevCANSparkMaxDriverWrapper::SetAverageDepth(uint32_t depth)
{
    m_AverageDepth_depth.Set(depth);

    Send("SetAverageDepth", depth);
}

void SnobotSim::RevCANSparkMaxDriverWrapper::GetAverageDepth(uint32_t* depth)
{
    RECEIVE_HELPER("GetAverageDepth", sizeof(*depth));
    PoplateReceiveResults(buffer, depth, buffer_pos);

    *depth = m_AverageDepth_depth.Get();
}

void SnobotSim::RevCANSparkMaxDriverWrapper::SetMeasurementPeriod(uint32_t samples)
{
    m_MeasurementPeriod_samples.Set(samples);

    Send("SetMeasurementPeriod", samples);
}

void SnobotSim::RevCANSparkMaxDriverWrapper::GetMeasurementPeriod(uint32_t* samples)
{
    RECEIVE_HELPER("GetMeasurementPeriod", sizeof(*samples));
    PoplateReceiveResults(buffer, samples, buffer_pos);

    *samples = m_MeasurementPeriod_samples.Get();
}

void SnobotSim::RevCANSparkMaxDriverWrapper::SetCountsPerRevolution(uint32_t cpr)
{
    m_CountsPerRevolution_cpr.Set(cpr);

    Send("SetCountsPerRevolution", cpr);
}

void SnobotSim::RevCANSparkMaxDriverWrapper::GetCountsPerRevolution(uint32_t* cpr)
{
    RECEIVE_HELPER("GetCountsPerRevolution", sizeof(*cpr));
    PoplateReceiveResults(buffer, cpr, buffer_pos);

    *cpr = m_CountsPerRevolution_cpr.Get();
}

void SnobotSim::RevCANSparkMaxDriverWrapper::SetEncoderInverted(uint8_t inverted)
{
    m_EncoderInverted_inverted.Set(inverted);

    Send("SetEncoderInverted", inverted);
}

void SnobotSim::RevCANSparkMaxDriverWrapper::GetEncoderInverted(uint8_t* inverted)
{
    RECEIVE_HELPER("GetEncoderInverted", sizeof(*inverted));
    PoplateReceiveResults(buffer, inverted, buffer_pos);

    *inverted = static_cast<uint8_t>(static_cast<int>(m_EncoderInverted_inverted.Get()));
}

void SnobotSim::RevCANSparkMaxDriverWrapper::GetAltEncoderPosition(float* position)
{
    RECEIVE_HELPER("GetAltEncoderPosition", sizeof(*position));
    PoplateReceiveResults(buffer, position, buffer_pos);

    *position = m_AltEncoderPosition_position.Get();
}

void SnobotSim::RevCANSparkMaxDriverWrapper::GetAltEncoderVelocity(float* velocity)
{
    RECEIVE_HELPER("GetAltEncoderVelocity", sizeof(*velocity));
    PoplateReceiveResults(buffer, velocity, buffer_pos);

    *velocity = m_AltEncoderVelocity_velocity.Get();
}

void SnobotSim::RevCANSparkMaxDriverWrapper::SetAltEncoderPositionFactor(float conversion)
{
    m_AltEncoderPositionFactor_conversion.Set(conversion);

    Send("SetAltEncoderPositionFactor", conversion);
}

void SnobotSim::RevCANSparkMaxDriverWrapper::SetAltEncoderVelocityFactor(float conversion)
{
    m_AltEncoderVelocityFactor_conversion.Set(conversion);

    Send("SetAltEncoderVelocityFactor", conversion);
}

void SnobotSim::RevCANSparkMaxDriverWrapper::GetAltEncoderPositionFactor(float* conversion)
{
    RECEIVE_HELPER("GetAltEncoderPositionFactor", sizeof(*conversion));
    PoplateReceiveResults(buffer, conversion, buffer_pos);

    *conversion = m_AltEncoderPositionFactor_conversion.Get();
}

void SnobotSim::RevCANSparkMaxDriverWrapper::GetAltEncoderVelocityFactor(float* conversion)
{
    RECEIVE_HELPER("GetAltEncoderVelocityFactor", sizeof(*conversion));
    PoplateReceiveResults(buffer, conversion, buffer_pos);

    *conversion = m_AltEncoderVelocityFactor_conversion.Get();
}

void SnobotSim::RevCANSparkMaxDriverWrapper::SetAltEncoderAverageDepth(uint32_t depth)
{
    m_AltEncoderAverageDepth_depth.Set(depth);

    Send("SetAltEncoderAverageDepth", depth);
}

void SnobotSim::RevCANSparkMaxDriverWrapper::GetAltEncoderAverageDepth(uint32_t* depth)
{
    RECEIVE_HELPER("GetAltEncoderAverageDepth", sizeof(*depth));
    PoplateReceiveResults(buffer, depth, buffer_pos);

    *depth = m_AltEncoderAverageDepth_depth.Get();
}

void SnobotSim::RevCANSparkMaxDriverWrapper::SetAltEncoderMeasurementPeriod(uint32_t samples)
{
    m_AltEncoderMeasurementPeriod_samples.Set(samples);

    Send("SetAltEncoderMeasurementPeriod", samples);
}

void SnobotSim::RevCANSparkMaxDriverWrapper::GetAltEncoderMeasurementPeriod(uint32_t* samples)
{
    RECEIVE_HELPER("GetAltEncoderMeasurementPeriod", sizeof(*samples));
    PoplateReceiveResults(buffer, samples, buffer_pos);

    *samples = m_AltEncoderMeasurementPeriod_samples.Get();
}

void SnobotSim::RevCANSparkMaxDriverWrapper::SetAltEncoderCountsPerRevolution(uint32_t cpr)
{
    m_AltEncoderCountsPerRevolution_cpr.Set(cpr);

    Send("SetAltEncoderCountsPerRevolution", cpr);
}

void SnobotSim::RevCANSparkMaxDriverWrapper::GetAltEncoderCountsPerRevolution(uint32_t* cpr)
{
    RECEIVE_HELPER("GetAltEncoderCountsPerRevolution", sizeof(*cpr));
    PoplateReceiveResults(buffer, cpr, buffer_pos);

    *cpr = m_AltEncoderCountsPerRevolution_cpr.Get();
}

void SnobotSim::RevCANSparkMaxDriverWrapper::SetAltEncoderInverted(uint8_t inverted)
{
    m_AltEncoderInverted_inverted.Set(inverted);

    Send("SetAltEncoderInverted", inverted);
}

void SnobotSim::RevCANSparkMaxDriverWrapper::GetAltEncoderInverted(uint8_t* inverted)
{
    RECEIVE_HELPER("GetAltEncoderInverted", sizeof(*inverted));
    PoplateReceiveResults(buffer, inverted, buffer_pos);

    *inverted = static_cast<uint8_t>(static_cast<int>(m_AltEncoderInverted_inverted.Get()));
}

void SnobotSim::RevCANSparkMaxDriverWrapper::SetDataPortConfig(c_SparkMax_DataPortConfig config)
{
    m_DataPortConfig_config.Set(config);

    Send("SetDataPortConfig", config);
}

void SnobotSim::RevCANSparkMaxDriverWrapper::GetDataPortConfig(c_SparkMax_DataPortConfig* config)
{
    RECEIVE_HELPER("GetDataPortConfig", sizeof(*config));
    PoplateReceiveResults(buffer, config, buffer_pos);

    *config = m_DataPortConfig_config.Get();
}

void SnobotSim::RevCANSparkMaxDriverWrapper::SetP(int slotID, float gain)
{
    m_slotted_variables[slotID].m_P_gain.Set(gain);

    Send("SetP", slotID, gain);
}

void SnobotSim::RevCANSparkMaxDriverWrapper::SetI(int slotID, float gain)
{
    m_slotted_variables[slotID].m_I_gain.Set(gain);

    Send("SetI", slotID, gain);
}

void SnobotSim::RevCANSparkMaxDriverWrapper::SetD(int slotID, float gain)
{
    m_slotted_variables[slotID].m_D_gain.Set(gain);

    Send("SetD", slotID, gain);
}

void SnobotSim::RevCANSparkMaxDriverWrapper::SetDFilter(int slotID, float gain)
{
    m_slotted_variables[slotID].m_DFilter_gain.Set(gain);

    Send("SetDFilter", slotID, gain);
}

void SnobotSim::RevCANSparkMaxDriverWrapper::SetFF(int slotID, float gain)
{
    m_slotted_variables[slotID].m_FF_gain.Set(gain);

    Send("SetFF", slotID, gain);
}

void SnobotSim::RevCANSparkMaxDriverWrapper::SetIZone(int slotID, float IZone)
{
    m_slotted_variables[slotID].m_IZone_IZone.Set(IZone);

    Send("SetIZone", slotID, IZone);
}

void SnobotSim::RevCANSparkMaxDriverWrapper::SetOutputRange(int slotID, float min, float max)
{
    m_slotted_variables[slotID].m_OutputRange_min.Set(min);
    m_slotted_variables[slotID].m_OutputRange_max.Set(max);

    Send("SetOutputRange", slotID, min, max);
}

void SnobotSim::RevCANSparkMaxDriverWrapper::GetP(int slotID, float* gain)
{
    RECEIVE_HELPER("GetP", sizeof(slotID) + sizeof(*gain));
    PoplateReceiveResults(buffer, &slotID, buffer_pos);
    PoplateReceiveResults(buffer, gain, buffer_pos);

    *gain = m_slotted_variables[slotID].m_P_gain.Get();
}

void SnobotSim::RevCANSparkMaxDriverWrapper::GetI(int slotID, float* gain)
{
    RECEIVE_HELPER("GetI", sizeof(slotID) + sizeof(*gain));
    PoplateReceiveResults(buffer, &slotID, buffer_pos);
    PoplateReceiveResults(buffer, gain, buffer_pos);

    *gain = m_slotted_variables[slotID].m_I_gain.Get();
}

void SnobotSim::RevCANSparkMaxDriverWrapper::GetD(int slotID, float* gain)
{
    RECEIVE_HELPER("GetD", sizeof(slotID) + sizeof(*gain));
    PoplateReceiveResults(buffer, &slotID, buffer_pos);
    PoplateReceiveResults(buffer, gain, buffer_pos);

    *gain = m_slotted_variables[slotID].m_D_gain.Get();
}

void SnobotSim::RevCANSparkMaxDriverWrapper::GetDFilter(int slotID, float* gain)
{
    RECEIVE_HELPER("GetDFilter", sizeof(slotID) + sizeof(*gain));
    PoplateReceiveResults(buffer, &slotID, buffer_pos);
    PoplateReceiveResults(buffer, gain, buffer_pos);

    *gain = m_slotted_variables[slotID].m_DFilter_gain.Get();
}

void SnobotSim::RevCANSparkMaxDriverWrapper::GetFF(int slotID, float* gain)
{
    RECEIVE_HELPER("GetFF", sizeof(slotID) + sizeof(*gain));
    PoplateReceiveResults(buffer, &slotID, buffer_pos);
    PoplateReceiveResults(buffer, gain, buffer_pos);

    *gain = m_slotted_variables[slotID].m_FF_gain.Get();
}

void SnobotSim::RevCANSparkMaxDriverWrapper::GetIZone(int slotID, float* IZone)
{
    RECEIVE_HELPER("GetIZone", sizeof(slotID) + sizeof(*IZone));
    PoplateReceiveResults(buffer, &slotID, buffer_pos);
    PoplateReceiveResults(buffer, IZone, buffer_pos);

    *IZone = m_slotted_variables[slotID].m_IZone_IZone.Get();
}

void SnobotSim::RevCANSparkMaxDriverWrapper::GetOutputMin(int slotID, float* min)
{
    RECEIVE_HELPER("GetOutputMin", sizeof(slotID) + sizeof(*min));
    PoplateReceiveResults(buffer, &slotID, buffer_pos);
    PoplateReceiveResults(buffer, min, buffer_pos);

    *min = m_slotted_variables[slotID].m_OutputMin_min.Get();
}

void SnobotSim::RevCANSparkMaxDriverWrapper::GetOutputMax(int slotID, float* max)
{
    RECEIVE_HELPER("GetOutputMax", sizeof(slotID) + sizeof(*max));
    PoplateReceiveResults(buffer, &slotID, buffer_pos);
    PoplateReceiveResults(buffer, max, buffer_pos);

    *max = m_slotted_variables[slotID].m_OutputMax_max.Get();
}

void SnobotSim::RevCANSparkMaxDriverWrapper::SetSmartMotionMaxVelocity(int slotID, float maxVel)
{
    m_slotted_variables[slotID].m_SmartMotionMaxVelocity_maxVel.Set(maxVel);

    Send("SetSmartMotionMaxVelocity", slotID, maxVel);
}

void SnobotSim::RevCANSparkMaxDriverWrapper::SetSmartMotionMaxAccel(int slotID, float maxAccel)
{
    m_slotted_variables[slotID].m_SmartMotionMaxAccel_maxAccel.Set(maxAccel);

    Send("SetSmartMotionMaxAccel", slotID, maxAccel);
}

void SnobotSim::RevCANSparkMaxDriverWrapper::SetSmartMotionMinOutputVelocity(int slotID, float minVel)
{
    m_slotted_variables[slotID].m_SmartMotionMinOutputVelocity_minVel.Set(minVel);

    Send("SetSmartMotionMinOutputVelocity", slotID, minVel);
}

void SnobotSim::RevCANSparkMaxDriverWrapper::SetSmartMotionAccelStrategy(int slotID, c_SparkMax_AccelStrategy accelStrategy)
{
    m_slotted_variables[slotID].m_SmartMotionAccelStrategy_accelStrategy.Set(accelStrategy);

    Send("SetSmartMotionAccelStrategy", slotID, accelStrategy);
}

void SnobotSim::RevCANSparkMaxDriverWrapper::SetSmartMotionAllowedClosedLoopError(int slotID, float allowedError)
{
    m_slotted_variables[slotID].m_SmartMotionAllowedClosedLoopError_allowedError.Set(allowedError);

    Send("SetSmartMotionAllowedClosedLoopError", slotID, allowedError);
}

void SnobotSim::RevCANSparkMaxDriverWrapper::GetSmartMotionMaxVelocity(int slotID, float* maxVel)
{
    RECEIVE_HELPER("GetSmartMotionMaxVelocity", sizeof(slotID) + sizeof(*maxVel));
    PoplateReceiveResults(buffer, &slotID, buffer_pos);
    PoplateReceiveResults(buffer, maxVel, buffer_pos);

    *maxVel = m_slotted_variables[slotID].m_SmartMotionMaxVelocity_maxVel.Get();
}

void SnobotSim::RevCANSparkMaxDriverWrapper::GetSmartMotionMaxAccel(int slotID, float* maxAccel)
{
    RECEIVE_HELPER("GetSmartMotionMaxAccel", sizeof(slotID) + sizeof(*maxAccel));
    PoplateReceiveResults(buffer, &slotID, buffer_pos);
    PoplateReceiveResults(buffer, maxAccel, buffer_pos);

    *maxAccel = m_slotted_variables[slotID].m_SmartMotionMaxAccel_maxAccel.Get();
}

void SnobotSim::RevCANSparkMaxDriverWrapper::GetSmartMotionMinOutputVelocity(int slotID, float* minVel)
{
    RECEIVE_HELPER("GetSmartMotionMinOutputVelocity", sizeof(slotID) + sizeof(*minVel));
    PoplateReceiveResults(buffer, &slotID, buffer_pos);
    PoplateReceiveResults(buffer, minVel, buffer_pos);

    *minVel = m_slotted_variables[slotID].m_SmartMotionMinOutputVelocity_minVel.Get();
}

void SnobotSim::RevCANSparkMaxDriverWrapper::GetSmartMotionAccelStrategy(int slotID, c_SparkMax_AccelStrategy* accelStrategy)
{
    RECEIVE_HELPER("GetSmartMotionAccelStrategy", sizeof(slotID) + sizeof(*accelStrategy));
    PoplateReceiveResults(buffer, &slotID, buffer_pos);
    PoplateReceiveResults(buffer, accelStrategy, buffer_pos);

    *accelStrategy = static_cast<c_SparkMax_AccelStrategy>(static_cast<int>(m_slotted_variables[slotID].m_SmartMotionAccelStrategy_accelStrategy.Get()));
}

void SnobotSim::RevCANSparkMaxDriverWrapper::GetSmartMotionAllowedClosedLoopError(int slotID, float* allowedError)
{
    RECEIVE_HELPER("GetSmartMotionAllowedClosedLoopError", sizeof(slotID) + sizeof(*allowedError));
    PoplateReceiveResults(buffer, &slotID, buffer_pos);
    PoplateReceiveResults(buffer, allowedError, buffer_pos);

    *allowedError = m_slotted_variables[slotID].m_SmartMotionAllowedClosedLoopError_allowedError.Get();
}

void SnobotSim::RevCANSparkMaxDriverWrapper::SetIMaxAccum(int slotID, float iMaxAccum)
{
    m_slotted_variables[slotID].m_IMaxAccum_iMaxAccum.Set(iMaxAccum);

    Send("SetIMaxAccum", slotID, iMaxAccum);
}

void SnobotSim::RevCANSparkMaxDriverWrapper::GetIMaxAccum(int slotID, float* iMaxAccum)
{
    RECEIVE_HELPER("GetIMaxAccum", sizeof(slotID) + sizeof(*iMaxAccum));
    PoplateReceiveResults(buffer, &slotID, buffer_pos);
    PoplateReceiveResults(buffer, iMaxAccum, buffer_pos);

    *iMaxAccum = m_slotted_variables[slotID].m_IMaxAccum_iMaxAccum.Get();
}

void SnobotSim::RevCANSparkMaxDriverWrapper::SetIAccum(float iAccum)
{
    m_IAccum_iAccum.Set(iAccum);

    Send("SetIAccum", iAccum);
}

void SnobotSim::RevCANSparkMaxDriverWrapper::GetIAccum(float* iAccum)
{
    RECEIVE_HELPER("GetIAccum", sizeof(*iAccum));
    PoplateReceiveResults(buffer, iAccum, buffer_pos);

    *iAccum = m_IAccum_iAccum.Get();
}

void SnobotSim::RevCANSparkMaxDriverWrapper::SetFeedbackDevice(uint32_t sensorID)
{
    m_FeedbackDevice_sensorID.Set(sensorID);

    Send("SetFeedbackDevice", sensorID);
}

void SnobotSim::RevCANSparkMaxDriverWrapper::GetFeedbackDeviceID(uint32_t* id)
{
    RECEIVE_HELPER("GetFeedbackDeviceID", sizeof(*id));
    PoplateReceiveResults(buffer, id, buffer_pos);

    *id = m_FeedbackDeviceID_id.Get();
}

void SnobotSim::RevCANSparkMaxDriverWrapper::SetFeedbackDeviceRange(float min, float max)
{
    m_FeedbackDeviceRange_min.Set(min);
    m_FeedbackDeviceRange_max.Set(max);

    Send("SetFeedbackDeviceRange", min, max);
}

void SnobotSim::RevCANSparkMaxDriverWrapper::SetLastError(c_SparkMax_ErrorCode error)
{
    m_LastError_error.Set(error);

    Send("SetLastError", error);
}

void SnobotSim::RevCANSparkMaxDriverWrapper::GetLastError()
{

    Send("GetLastError");
}

void SnobotSim::RevCANSparkMaxDriverWrapper::ReadTelemetryStream(uint32_t telemetryHandle, c_SparkMax_TelemetryMessage* messages, c_SparkMax_TelemetryID* ids, uint32_t numOfStreams)
{
    RECEIVE_HELPER("ReadTelemetryStream", sizeof(telemetryHandle) + sizeof(*messages) + sizeof(*ids) + sizeof(numOfStreams));
    PoplateReceiveResults(buffer, &telemetryHandle, buffer_pos);
    PoplateReceiveResults(buffer, messages, buffer_pos);
    PoplateReceiveResults(buffer, ids, buffer_pos);
    PoplateReceiveResults(buffer, &numOfStreams, buffer_pos);

    *telemetryHandle = m_ReadTelemetryStream_telemetryHandle.Get();
    *numOfStreams = m_ReadTelemetryStream_numOfStreams.Get();
    *messages = m_ReadTelemetryStream_messages.Get();
    *ids = m_ReadTelemetryStream_ids.Get();
}

void SnobotSim::RevCANSparkMaxDriverWrapper::OpenTelemetryStream(uint32_t* telemetryHandle)
{
    RECEIVE_HELPER("OpenTelemetryStream", sizeof(*telemetryHandle));
    PoplateReceiveResults(buffer, telemetryHandle, buffer_pos);

    *telemetryHandle = m_OpenTelemetryStream_telemetryHandle.Get();
}

void SnobotSim::RevCANSparkMaxDriverWrapper::CloseTelemetryStream(uint32_t telemetryHandle)
{
    m_CloseTelemetryStream_telemetryHandle.Set(telemetryHandle);

    Send("CloseTelemetryStream", telemetryHandle);
}

void SnobotSim::RevCANSparkMaxDriverWrapper::ListTelemetryStream(c_SparkMax_TelemetryMessage* messages)
{
    RECEIVE_HELPER("ListTelemetryStream", sizeof(*messages));
    PoplateReceiveResults(buffer, messages, buffer_pos);

    *messages = m_ListTelemetryStream_messages.Get();
}

