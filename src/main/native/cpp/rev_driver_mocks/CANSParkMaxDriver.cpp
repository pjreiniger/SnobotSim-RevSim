
#include <iostream>
#include <vector>

#include "rev/CANSparkMaxDriver.h"
#include "RevSimMocks/RevMockUtilities.h"
#include "RevSimMocks/RevDeviceWrapper.h"


#define RECEIVE_HELPER(paramName, size)                                        \
    SnobotSim::RevSimulator* wrapper = (SnobotSim::RevSimulator*) handle;      \
    uint8_t buffer[size]; /* NOLINT */                                         \
    std::memset(&buffer[0], 0, size);                                          \
    wrapper->Receive(paramName, buffer, size);                                 \
    uint32_t buffer_pos = 0;

c_SparkMax_handle c_SparkMax_Create(int deviceId, c_SparkMax_MotorType type)
{
    SnobotSim::RevSimulator* output = new SnobotSim::RevSimulator(deviceId, "Create");
    return (c_SparkMax_handle) output;
}
c_SparkMax_handle c_SparkMax_Create_Inplace(int deviceId)
{
    SnobotSim::RevSimulator* output = new SnobotSim::RevSimulator(deviceId, "Inplace");
    return (c_SparkMax_handle) output;
}
c_SparkMax_ErrorCode c_SparkMax_GetFirmwareVersion(c_SparkMax_handle handle, c_SparkMax_FirmwareVersion* fwVersion)
{
    RECEIVE_HELPER("GetFirmwareVersion", sizeof(*fwVersion));
    PoplateReceiveResults(buffer, fwVersion, buffer_pos);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_GetSerialNumber(c_SparkMax_handle handle, uint32_t* serialNumber[3])
{
    RECEIVE_HELPER("GetSerialNumber", sizeof(*serialNumber[3]));
    PoplateReceiveResults(buffer, serialNumber[3], buffer_pos);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_GetDeviceId(c_SparkMax_handle handle, int* deviceId)
{
    RECEIVE_HELPER("GetDeviceId", sizeof(*deviceId));
    PoplateReceiveResults(buffer, deviceId, buffer_pos);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_SetMotorType(c_SparkMax_handle handle, c_SparkMax_MotorType type)
{
    ((SnobotSim::RevSimulator*)handle)->Send("SetMotorType", type);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_GetMotorType(c_SparkMax_handle handle, c_SparkMax_MotorType* type)
{
    RECEIVE_HELPER("GetMotorType", sizeof(*type));
    PoplateReceiveResults(buffer, type, buffer_pos);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_SetPeriodicFramePeriod(c_SparkMax_handle handle, c_SparkMax_PeriodicFrame frameId, int periodMs)
{
    ((SnobotSim::RevSimulator*)handle)->Send("SetPeriodicFramePeriod", frameId, periodMs);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_SetParameterFloat32(c_SparkMax_handle handle, c_SparkMax_ConfigParameter paramId, float value)
{
    ((SnobotSim::RevSimulator*)handle)->Send("SetParameterFloat32", paramId, value);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_SetParameterInt32(c_SparkMax_handle handle, c_SparkMax_ConfigParameter paramId, int32_t value)
{
    ((SnobotSim::RevSimulator*)handle)->Send("SetParameterInt32", paramId, value);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_SetParameterUint32(c_SparkMax_handle handle, c_SparkMax_ConfigParameter paramId, uint32_t value)
{
    ((SnobotSim::RevSimulator*)handle)->Send("SetParameterUint32", paramId, value);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_SetParameterBool(c_SparkMax_handle handle, c_SparkMax_ConfigParameter paramId, uint8_t value)
{
    ((SnobotSim::RevSimulator*)handle)->Send("SetParameterBool", paramId, value);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_GetParameterFloat32(c_SparkMax_handle handle, c_SparkMax_ConfigParameter paramId, float* value)
{
    RECEIVE_HELPER("GetParameterFloat32", sizeof(paramId) + sizeof(*value));
    PoplateReceiveResults(buffer, &paramId, buffer_pos);
    PoplateReceiveResults(buffer, value, buffer_pos);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_GetParameterInt32(c_SparkMax_handle handle, c_SparkMax_ConfigParameter paramId, int32_t* value)
{
    RECEIVE_HELPER("GetParameterInt32", sizeof(paramId) + sizeof(*value));
    PoplateReceiveResults(buffer, &paramId, buffer_pos);
    PoplateReceiveResults(buffer, value, buffer_pos);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_GetParameterUint32(c_SparkMax_handle handle, c_SparkMax_ConfigParameter paramId, uint32_t* value)
{
    RECEIVE_HELPER("GetParameterUint32", sizeof(paramId) + sizeof(*value));
    PoplateReceiveResults(buffer, &paramId, buffer_pos);
    PoplateReceiveResults(buffer, value, buffer_pos);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_GetParameterBool(c_SparkMax_handle handle, c_SparkMax_ConfigParameter paramId, uint8_t* value)
{
    RECEIVE_HELPER("GetParameterBool", sizeof(paramId) + sizeof(*value));
    PoplateReceiveResults(buffer, &paramId, buffer_pos);
    PoplateReceiveResults(buffer, value, buffer_pos);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_GetPeriodicStatus0(c_SparkMax_handle handle, c_SparkMax_PeriodicStatus0* rawframe)
{
    RECEIVE_HELPER("GetPeriodicStatus0", sizeof(*rawframe));
    PoplateReceiveResults(buffer, rawframe, buffer_pos);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_GetPeriodicStatus1(c_SparkMax_handle handle, c_SparkMax_PeriodicStatus1* rawframe)
{
    RECEIVE_HELPER("GetPeriodicStatus1", sizeof(*rawframe));
    PoplateReceiveResults(buffer, rawframe, buffer_pos);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_GetPeriodicStatus2(c_SparkMax_handle handle, c_SparkMax_PeriodicStatus2* rawframe)
{
    RECEIVE_HELPER("GetPeriodicStatus2", sizeof(*rawframe));
    PoplateReceiveResults(buffer, rawframe, buffer_pos);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_GetPeriodicStatus3(c_SparkMax_handle handle, c_SparkMax_PeriodicStatus3* rawframe)
{
    RECEIVE_HELPER("GetPeriodicStatus3", sizeof(*rawframe));
    PoplateReceiveResults(buffer, rawframe, buffer_pos);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_GetPeriodicStatus4(c_SparkMax_handle handle, c_SparkMax_PeriodicStatus4* rawframe)
{
    RECEIVE_HELPER("GetPeriodicStatus4", sizeof(*rawframe));
    PoplateReceiveResults(buffer, rawframe, buffer_pos);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_SetEncoderPosition(c_SparkMax_handle handle, float position)
{
    ((SnobotSim::RevSimulator*)handle)->Send("SetEncoderPosition", position);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_SetAltEncoderPosition(c_SparkMax_handle handle, float position)
{
    ((SnobotSim::RevSimulator*)handle)->Send("SetAltEncoderPosition", position);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_SetIAccum(c_SparkMax_handle handle, float iAccum)
{
    ((SnobotSim::RevSimulator*)handle)->Send("SetIAccum", iAccum);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_RestoreFactoryDefaults(c_SparkMax_handle handle, uint8_t persist)
{
    ((SnobotSim::RevSimulator*)handle)->Send("RestoreFactoryDefaults", persist);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_FactoryWipe(c_SparkMax_handle handle, uint8_t persist)
{
    ((SnobotSim::RevSimulator*)handle)->Send("FactoryWipe", persist);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_SetFollow(c_SparkMax_handle handle, uint32_t followerArbId, uint32_t followerCfg)
{
    ((SnobotSim::RevSimulator*)handle)->Send("SetFollow", followerArbId, followerCfg);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_SetpointCommand(c_SparkMax_handle handle, float value, c_SparkMax_ControlType ctrl, int pidSlot, float arbFeedforward, int arbFFUnits)
{
    ((SnobotSim::RevSimulator*)handle)->Send("SetpointCommand", value, ctrl, pidSlot, arbFeedforward, arbFFUnits);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_GetDRVStatus(c_SparkMax_handle handle, c_SparkMax_DRVStatus* drvStatus)
{
    RECEIVE_HELPER("GetDRVStatus", sizeof(*drvStatus));
    PoplateReceiveResults(buffer, drvStatus, buffer_pos);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_SetInverted(c_SparkMax_handle handle, uint8_t inverted)
{
    ((SnobotSim::RevSimulator*)handle)->Send("SetInverted", inverted);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_GetInverted(c_SparkMax_handle handle, uint8_t* inverted)
{
    RECEIVE_HELPER("GetInverted", sizeof(*inverted));
    PoplateReceiveResults(buffer, inverted, buffer_pos);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_SetSmartCurrentLimit(c_SparkMax_handle handle, uint8_t stallLimit, uint8_t freeLimit, uint32_t limitRPM)
{
    ((SnobotSim::RevSimulator*)handle)->Send("SetSmartCurrentLimit", stallLimit, freeLimit, limitRPM);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_GetSmartCurrentLimit(c_SparkMax_handle handle, uint8_t* stallLimit, uint8_t* freeLimit, uint32_t* limitRPM)
{
    RECEIVE_HELPER("GetSmartCurrentLimit", sizeof(*stallLimit) + sizeof(*freeLimit) + sizeof(*limitRPM));
    PoplateReceiveResults(buffer, stallLimit, buffer_pos);
    PoplateReceiveResults(buffer, freeLimit, buffer_pos);
    PoplateReceiveResults(buffer, limitRPM, buffer_pos);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_SetSecondaryCurrentLimit(c_SparkMax_handle handle, float limit, int chopCycles)
{
    ((SnobotSim::RevSimulator*)handle)->Send("SetSecondaryCurrentLimit", limit, chopCycles);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_GetSecondaryCurrentLimit(c_SparkMax_handle handle, float* limit, int* chopCycles)
{
    RECEIVE_HELPER("GetSecondaryCurrentLimit", sizeof(*limit) + sizeof(*chopCycles));
    PoplateReceiveResults(buffer, limit, buffer_pos);
    PoplateReceiveResults(buffer, chopCycles, buffer_pos);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_SetIdleMode(c_SparkMax_handle handle, c_SparkMax_IdleMode idlemode)
{
    ((SnobotSim::RevSimulator*)handle)->Send("SetIdleMode", idlemode);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_GetIdleMode(c_SparkMax_handle handle, c_SparkMax_IdleMode* idlemode)
{
    RECEIVE_HELPER("GetIdleMode", sizeof(*idlemode));
    PoplateReceiveResults(buffer, idlemode, buffer_pos);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_EnableVoltageCompensation(c_SparkMax_handle handle, float nominalVoltage)
{
    ((SnobotSim::RevSimulator*)handle)->Send("EnableVoltageCompensation", nominalVoltage);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_GetVoltageCompensationNominalVoltage(c_SparkMax_handle handle, float* nominalVoltage)
{
    RECEIVE_HELPER("GetVoltageCompensationNominalVoltage", sizeof(*nominalVoltage));
    PoplateReceiveResults(buffer, nominalVoltage, buffer_pos);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_DisableVoltageCompensation(c_SparkMax_handle handle)
{
    ((SnobotSim::RevSimulator*)handle)->Send("DisableVoltageCompensation");
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_SetOpenLoopRampRate(c_SparkMax_handle handle, float rate)
{
    ((SnobotSim::RevSimulator*)handle)->Send("SetOpenLoopRampRate", rate);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_GetOpenLoopRampRate(c_SparkMax_handle handle, float* rate)
{
    RECEIVE_HELPER("GetOpenLoopRampRate", sizeof(*rate));
    PoplateReceiveResults(buffer, rate, buffer_pos);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_SetClosedLoopRampRate(c_SparkMax_handle handle, float rate)
{
    ((SnobotSim::RevSimulator*)handle)->Send("SetClosedLoopRampRate", rate);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_GetClosedLoopRampRate(c_SparkMax_handle handle, float* rate)
{
    RECEIVE_HELPER("GetClosedLoopRampRate", sizeof(*rate));
    PoplateReceiveResults(buffer, rate, buffer_pos);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_IsFollower(c_SparkMax_handle handle, uint8_t* isFollower)
{
    RECEIVE_HELPER("IsFollower", sizeof(*isFollower));
    PoplateReceiveResults(buffer, isFollower, buffer_pos);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_GetFaults(c_SparkMax_handle handle, uint16_t* faults)
{
    RECEIVE_HELPER("GetFaults", sizeof(*faults));
    PoplateReceiveResults(buffer, faults, buffer_pos);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_GetStickyFaults(c_SparkMax_handle handle, uint16_t* stickyFaults)
{
    RECEIVE_HELPER("GetStickyFaults", sizeof(*stickyFaults));
    PoplateReceiveResults(buffer, stickyFaults, buffer_pos);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_GetFault(c_SparkMax_handle handle, c_SparkMax_FaultID faultId, uint8_t* fault)
{
    RECEIVE_HELPER("GetFault", sizeof(faultId) + sizeof(*fault));
    PoplateReceiveResults(buffer, &faultId, buffer_pos);
    PoplateReceiveResults(buffer, fault, buffer_pos);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_GetStickyFault(c_SparkMax_handle handle, c_SparkMax_FaultID faultId, uint8_t* stickyfault)
{
    RECEIVE_HELPER("GetStickyFault", sizeof(faultId) + sizeof(*stickyfault));
    PoplateReceiveResults(buffer, &faultId, buffer_pos);
    PoplateReceiveResults(buffer, stickyfault, buffer_pos);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_GetBusVoltage(c_SparkMax_handle handle, float* busVoltage)
{
    RECEIVE_HELPER("GetBusVoltage", sizeof(*busVoltage));
    PoplateReceiveResults(buffer, busVoltage, buffer_pos);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_GetAppliedOutput(c_SparkMax_handle handle, float* appliedOutput)
{
    RECEIVE_HELPER("GetAppliedOutput", sizeof(*appliedOutput));
    PoplateReceiveResults(buffer, appliedOutput, buffer_pos);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_GetOutputCurrent(c_SparkMax_handle handle, float* outputCurrent)
{
    RECEIVE_HELPER("GetOutputCurrent", sizeof(*outputCurrent));
    PoplateReceiveResults(buffer, outputCurrent, buffer_pos);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_GetMotorTemperature(c_SparkMax_handle handle, float* motorTemperature)
{
    RECEIVE_HELPER("GetMotorTemperature", sizeof(*motorTemperature));
    PoplateReceiveResults(buffer, motorTemperature, buffer_pos);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_ClearFaults(c_SparkMax_handle handle)
{
    ((SnobotSim::RevSimulator*)handle)->Send("ClearFaults");
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_BurnFlash(c_SparkMax_handle handle)
{
    ((SnobotSim::RevSimulator*)handle)->Send("BurnFlash");
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_SetCANTimeout(c_SparkMax_handle handle, int timeoutMs)
{
    ((SnobotSim::RevSimulator*)handle)->Send("SetCANTimeout", timeoutMs);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_EnableSoftLimit(c_SparkMax_handle handle, c_SparkMax_LimitDirection dir, uint8_t enable)
{
    ((SnobotSim::RevSimulator*)handle)->Send("EnableSoftLimit", dir, enable);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_IsSoftLimitEnabled(c_SparkMax_handle handle, c_SparkMax_LimitDirection dir, uint8_t* enabled)
{
    RECEIVE_HELPER("IsSoftLimitEnabled", sizeof(dir) + sizeof(*enabled));
    PoplateReceiveResults(buffer, &dir, buffer_pos);
    PoplateReceiveResults(buffer, enabled, buffer_pos);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_SetSoftLimit(c_SparkMax_handle handle, c_SparkMax_LimitDirection dir, float limit)
{
    ((SnobotSim::RevSimulator*)handle)->Send("SetSoftLimit", dir, limit);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_GetSoftLimit(c_SparkMax_handle handle, c_SparkMax_LimitDirection dir, float* limit)
{
    RECEIVE_HELPER("GetSoftLimit", sizeof(dir) + sizeof(*limit));
    PoplateReceiveResults(buffer, &dir, buffer_pos);
    PoplateReceiveResults(buffer, limit, buffer_pos);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_SetSensorType(c_SparkMax_handle handle, c_SparkMax_EncoderType sensorType)
{
    ((SnobotSim::RevSimulator*)handle)->Send("SetSensorType", sensorType);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_IDQuery(uint32_t* uniqueIdArray, size_t uniqueIdArraySize, size_t* numberOfDevices)
{
    LOG_UNSUPPORTED_CAN_FUNC("");
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_IDAssign(uint32_t uniqueId, uint8_t deviceId)
{
    LOG_UNSUPPORTED_CAN_FUNC("");
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_Identify(c_SparkMax_handle handle)
{
    ((SnobotSim::RevSimulator*)handle)->Send("Identify");
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_IdentifyUniqueId(uint32_t uniqueId)
{
    LOG_UNSUPPORTED_CAN_FUNC("");
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_SetLimitPolarity(c_SparkMax_handle handle, c_SparkMax_LimitDirection sw, c_SparkMax_LimitPolarity polarity)
{
    ((SnobotSim::RevSimulator*)handle)->Send("SetLimitPolarity", sw, polarity);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_GetLimitPolarity(c_SparkMax_handle handle, c_SparkMax_LimitDirection sw, c_SparkMax_LimitPolarity* polarity)
{
    RECEIVE_HELPER("GetLimitPolarity", sizeof(sw) + sizeof(*polarity));
    PoplateReceiveResults(buffer, &sw, buffer_pos);
    PoplateReceiveResults(buffer, polarity, buffer_pos);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_GetLimitSwitch(c_SparkMax_handle handle, c_SparkMax_LimitDirection sw, uint8_t* limit)
{
    RECEIVE_HELPER("GetLimitSwitch", sizeof(sw) + sizeof(*limit));
    PoplateReceiveResults(buffer, &sw, buffer_pos);
    PoplateReceiveResults(buffer, limit, buffer_pos);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_EnableLimitSwitch(c_SparkMax_handle handle, c_SparkMax_LimitDirection sw, uint8_t enable)
{
    ((SnobotSim::RevSimulator*)handle)->Send("EnableLimitSwitch", sw, enable);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_IsLimitEnabled(c_SparkMax_handle handle, c_SparkMax_LimitDirection sw, uint8_t* enabled)
{
    RECEIVE_HELPER("IsLimitEnabled", sizeof(sw) + sizeof(*enabled));
    PoplateReceiveResults(buffer, &sw, buffer_pos);
    PoplateReceiveResults(buffer, enabled, buffer_pos);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_GetAnalogPosition(c_SparkMax_handle handle, float* position)
{
    RECEIVE_HELPER("GetAnalogPosition", sizeof(*position));
    PoplateReceiveResults(buffer, position, buffer_pos);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_GetAnalogVelocity(c_SparkMax_handle handle, float* velocity)
{
    RECEIVE_HELPER("GetAnalogVelocity", sizeof(*velocity));
    PoplateReceiveResults(buffer, velocity, buffer_pos);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_GetAnalogVoltage(c_SparkMax_handle handle, float* voltage)
{
    RECEIVE_HELPER("GetAnalogVoltage", sizeof(*voltage));
    PoplateReceiveResults(buffer, voltage, buffer_pos);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_SetAnalogPositionConversionFactor(c_SparkMax_handle handle, float conversion)
{
    ((SnobotSim::RevSimulator*)handle)->Send("SetAnalogPositionConversionFactor", conversion);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_SetAnalogVelocityConversionFactor(c_SparkMax_handle handle, float conversion)
{
    ((SnobotSim::RevSimulator*)handle)->Send("SetAnalogVelocityConversionFactor", conversion);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_GetAnalogPositionConversionFactor(c_SparkMax_handle handle, float* conversion)
{
    RECEIVE_HELPER("GetAnalogPositionConversionFactor", sizeof(*conversion));
    PoplateReceiveResults(buffer, conversion, buffer_pos);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_GetAnalogVelocityConversionFactor(c_SparkMax_handle handle, float* conversion)
{
    RECEIVE_HELPER("GetAnalogVelocityConversionFactor", sizeof(*conversion));
    PoplateReceiveResults(buffer, conversion, buffer_pos);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_SetAnalogInverted(c_SparkMax_handle handle, uint8_t inverted)
{
    ((SnobotSim::RevSimulator*)handle)->Send("SetAnalogInverted", inverted);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_GetAnalogInverted(c_SparkMax_handle handle, uint8_t* inverted)
{
    RECEIVE_HELPER("GetAnalogInverted", sizeof(*inverted));
    PoplateReceiveResults(buffer, inverted, buffer_pos);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_SetAnalogAverageDepth(c_SparkMax_handle handle, uint32_t depth)
{
    ((SnobotSim::RevSimulator*)handle)->Send("SetAnalogAverageDepth", depth);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_GetAnalogAverageDepth(c_SparkMax_handle handle, uint32_t* depth)
{
    RECEIVE_HELPER("GetAnalogAverageDepth", sizeof(*depth));
    PoplateReceiveResults(buffer, depth, buffer_pos);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_SetAnalogMeasurementPeriod(c_SparkMax_handle handle, uint32_t samples)
{
    ((SnobotSim::RevSimulator*)handle)->Send("SetAnalogMeasurementPeriod", samples);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_GetAnalogMeasurementPeriod(c_SparkMax_handle handle, uint32_t* samples)
{
    RECEIVE_HELPER("GetAnalogMeasurementPeriod", sizeof(*samples));
    PoplateReceiveResults(buffer, samples, buffer_pos);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_SetAnalogMode(c_SparkMax_handle handle, c_SparkMax_AnalogMode mode)
{
    ((SnobotSim::RevSimulator*)handle)->Send("SetAnalogMode", mode);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_GetAnalogMode(c_SparkMax_handle handle, c_SparkMax_AnalogMode* mode)
{
    RECEIVE_HELPER("GetAnalogMode", sizeof(*mode));
    PoplateReceiveResults(buffer, mode, buffer_pos);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_GetEncoderPosition(c_SparkMax_handle handle, float* position)
{
    RECEIVE_HELPER("GetEncoderPosition", sizeof(*position));
    PoplateReceiveResults(buffer, position, buffer_pos);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_GetEncoderVelocity(c_SparkMax_handle handle, float* velocity)
{
    RECEIVE_HELPER("GetEncoderVelocity", sizeof(*velocity));
    PoplateReceiveResults(buffer, velocity, buffer_pos);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_SetPositionConversionFactor(c_SparkMax_handle handle, float conversion)
{
    ((SnobotSim::RevSimulator*)handle)->Send("SetPositionConversionFactor", conversion);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_SetVelocityConversionFactor(c_SparkMax_handle handle, float conversion)
{
    ((SnobotSim::RevSimulator*)handle)->Send("SetVelocityConversionFactor", conversion);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_GetPositionConversionFactor(c_SparkMax_handle handle, float* conversion)
{
    RECEIVE_HELPER("GetPositionConversionFactor", sizeof(*conversion));
    PoplateReceiveResults(buffer, conversion, buffer_pos);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_GetVelocityConversionFactor(c_SparkMax_handle handle, float* conversion)
{
    RECEIVE_HELPER("GetVelocityConversionFactor", sizeof(*conversion));
    PoplateReceiveResults(buffer, conversion, buffer_pos);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_SetAverageDepth(c_SparkMax_handle handle, uint32_t depth)
{
    ((SnobotSim::RevSimulator*)handle)->Send("SetAverageDepth", depth);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_GetAverageDepth(c_SparkMax_handle handle, uint32_t* depth)
{
    RECEIVE_HELPER("GetAverageDepth", sizeof(*depth));
    PoplateReceiveResults(buffer, depth, buffer_pos);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_SetMeasurementPeriod(c_SparkMax_handle handle, uint32_t samples)
{
    ((SnobotSim::RevSimulator*)handle)->Send("SetMeasurementPeriod", samples);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_GetMeasurementPeriod(c_SparkMax_handle handle, uint32_t* samples)
{
    RECEIVE_HELPER("GetMeasurementPeriod", sizeof(*samples));
    PoplateReceiveResults(buffer, samples, buffer_pos);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_SetCountsPerRevolution(c_SparkMax_handle handle, uint32_t cpr)
{
    ((SnobotSim::RevSimulator*)handle)->Send("SetCountsPerRevolution", cpr);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_GetCountsPerRevolution(c_SparkMax_handle handle, uint32_t* cpr)
{
    RECEIVE_HELPER("GetCountsPerRevolution", sizeof(*cpr));
    PoplateReceiveResults(buffer, cpr, buffer_pos);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_SetEncoderInverted(c_SparkMax_handle handle, uint8_t inverted)
{
    ((SnobotSim::RevSimulator*)handle)->Send("SetEncoderInverted", inverted);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_GetEncoderInverted(c_SparkMax_handle handle, uint8_t* inverted)
{
    RECEIVE_HELPER("GetEncoderInverted", sizeof(*inverted));
    PoplateReceiveResults(buffer, inverted, buffer_pos);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_GetAltEncoderPosition(c_SparkMax_handle handle, float* position)
{
    RECEIVE_HELPER("GetAltEncoderPosition", sizeof(*position));
    PoplateReceiveResults(buffer, position, buffer_pos);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_GetAltEncoderVelocity(c_SparkMax_handle handle, float* velocity)
{
    RECEIVE_HELPER("GetAltEncoderVelocity", sizeof(*velocity));
    PoplateReceiveResults(buffer, velocity, buffer_pos);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_SetAltEncoderPositionFactor(c_SparkMax_handle handle, float conversion)
{
    ((SnobotSim::RevSimulator*)handle)->Send("SetAltEncoderPositionFactor", conversion);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_SetAltEncoderVelocityFactor(c_SparkMax_handle handle, float conversion)
{
    ((SnobotSim::RevSimulator*)handle)->Send("SetAltEncoderVelocityFactor", conversion);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_GetAltEncoderPositionFactor(c_SparkMax_handle handle, float* conversion)
{
    RECEIVE_HELPER("GetAltEncoderPositionFactor", sizeof(*conversion));
    PoplateReceiveResults(buffer, conversion, buffer_pos);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_GetAltEncoderVelocityFactor(c_SparkMax_handle handle, float* conversion)
{
    RECEIVE_HELPER("GetAltEncoderVelocityFactor", sizeof(*conversion));
    PoplateReceiveResults(buffer, conversion, buffer_pos);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_SetAltEncoderAverageDepth(c_SparkMax_handle handle, uint32_t depth)
{
    ((SnobotSim::RevSimulator*)handle)->Send("SetAltEncoderAverageDepth", depth);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_GetAltEncoderAverageDepth(c_SparkMax_handle handle, uint32_t* depth)
{
    RECEIVE_HELPER("GetAltEncoderAverageDepth", sizeof(*depth));
    PoplateReceiveResults(buffer, depth, buffer_pos);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_SetAltEncoderMeasurementPeriod(c_SparkMax_handle handle, uint32_t samples)
{
    ((SnobotSim::RevSimulator*)handle)->Send("SetAltEncoderMeasurementPeriod", samples);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_GetAltEncoderMeasurementPeriod(c_SparkMax_handle handle, uint32_t* samples)
{
    RECEIVE_HELPER("GetAltEncoderMeasurementPeriod", sizeof(*samples));
    PoplateReceiveResults(buffer, samples, buffer_pos);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_SetAltEncoderCountsPerRevolution(c_SparkMax_handle handle, uint32_t cpr)
{
    ((SnobotSim::RevSimulator*)handle)->Send("SetAltEncoderCountsPerRevolution", cpr);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_GetAltEncoderCountsPerRevolution(c_SparkMax_handle handle, uint32_t* cpr)
{
    RECEIVE_HELPER("GetAltEncoderCountsPerRevolution", sizeof(*cpr));
    PoplateReceiveResults(buffer, cpr, buffer_pos);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_SetAltEncoderInverted(c_SparkMax_handle handle, uint8_t inverted)
{
    ((SnobotSim::RevSimulator*)handle)->Send("SetAltEncoderInverted", inverted);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_GetAltEncoderInverted(c_SparkMax_handle handle, uint8_t* inverted)
{
    RECEIVE_HELPER("GetAltEncoderInverted", sizeof(*inverted));
    PoplateReceiveResults(buffer, inverted, buffer_pos);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_SetDataPortConfig(c_SparkMax_handle handle, c_SparkMax_DataPortConfig config)
{
    ((SnobotSim::RevSimulator*)handle)->Send("SetDataPortConfig", config);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_GetDataPortConfig(c_SparkMax_handle handle, c_SparkMax_DataPortConfig* config)
{
    RECEIVE_HELPER("GetDataPortConfig", sizeof(*config));
    PoplateReceiveResults(buffer, config, buffer_pos);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_SetP(c_SparkMax_handle handle, int slotID, float gain)
{
    ((SnobotSim::RevSimulator*)handle)->Send("SetP", slotID, gain);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_SetI(c_SparkMax_handle handle, int slotID, float gain)
{
    ((SnobotSim::RevSimulator*)handle)->Send("SetI", slotID, gain);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_SetD(c_SparkMax_handle handle, int slotID, float gain)
{
    ((SnobotSim::RevSimulator*)handle)->Send("SetD", slotID, gain);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_SetDFilter(c_SparkMax_handle handle, int slotID, float gain)
{
    ((SnobotSim::RevSimulator*)handle)->Send("SetDFilter", slotID, gain);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_SetFF(c_SparkMax_handle handle, int slotID, float gain)
{
    ((SnobotSim::RevSimulator*)handle)->Send("SetFF", slotID, gain);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_SetIZone(c_SparkMax_handle handle, int slotID, float IZone)
{
    ((SnobotSim::RevSimulator*)handle)->Send("SetIZone", slotID, IZone);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_SetOutputRange(c_SparkMax_handle handle, int slotID, float min, float max)
{
    ((SnobotSim::RevSimulator*)handle)->Send("SetOutputRange", slotID, min, max);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_GetP(c_SparkMax_handle handle, int slotID, float* gain)
{
    RECEIVE_HELPER("GetP", sizeof(slotID) + sizeof(*gain));
    PoplateReceiveResults(buffer, &slotID, buffer_pos);
    PoplateReceiveResults(buffer, gain, buffer_pos);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_GetI(c_SparkMax_handle handle, int slotID, float* gain)
{
    RECEIVE_HELPER("GetI", sizeof(slotID) + sizeof(*gain));
    PoplateReceiveResults(buffer, &slotID, buffer_pos);
    PoplateReceiveResults(buffer, gain, buffer_pos);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_GetD(c_SparkMax_handle handle, int slotID, float* gain)
{
    RECEIVE_HELPER("GetD", sizeof(slotID) + sizeof(*gain));
    PoplateReceiveResults(buffer, &slotID, buffer_pos);
    PoplateReceiveResults(buffer, gain, buffer_pos);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_GetDFilter(c_SparkMax_handle handle, int slotID, float* gain)
{
    RECEIVE_HELPER("GetDFilter", sizeof(slotID) + sizeof(*gain));
    PoplateReceiveResults(buffer, &slotID, buffer_pos);
    PoplateReceiveResults(buffer, gain, buffer_pos);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_GetFF(c_SparkMax_handle handle, int slotID, float* gain)
{
    RECEIVE_HELPER("GetFF", sizeof(slotID) + sizeof(*gain));
    PoplateReceiveResults(buffer, &slotID, buffer_pos);
    PoplateReceiveResults(buffer, gain, buffer_pos);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_GetIZone(c_SparkMax_handle handle, int slotID, float* IZone)
{
    RECEIVE_HELPER("GetIZone", sizeof(slotID) + sizeof(*IZone));
    PoplateReceiveResults(buffer, &slotID, buffer_pos);
    PoplateReceiveResults(buffer, IZone, buffer_pos);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_GetOutputMin(c_SparkMax_handle handle, int slotID, float* min)
{
    RECEIVE_HELPER("GetOutputMin", sizeof(slotID) + sizeof(*min));
    PoplateReceiveResults(buffer, &slotID, buffer_pos);
    PoplateReceiveResults(buffer, min, buffer_pos);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_GetOutputMax(c_SparkMax_handle handle, int slotID, float* max)
{
    RECEIVE_HELPER("GetOutputMax", sizeof(slotID) + sizeof(*max));
    PoplateReceiveResults(buffer, &slotID, buffer_pos);
    PoplateReceiveResults(buffer, max, buffer_pos);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_SetSmartMotionMaxVelocity(c_SparkMax_handle handle, int slotID, float maxVel)
{
    ((SnobotSim::RevSimulator*)handle)->Send("SetSmartMotionMaxVelocity", slotID, maxVel);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_SetSmartMotionMaxAccel(c_SparkMax_handle handle, int slotID, float maxAccel)
{
    ((SnobotSim::RevSimulator*)handle)->Send("SetSmartMotionMaxAccel", slotID, maxAccel);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_SetSmartMotionMinOutputVelocity(c_SparkMax_handle handle, int slotID, float minVel)
{
    ((SnobotSim::RevSimulator*)handle)->Send("SetSmartMotionMinOutputVelocity", slotID, minVel);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_SetSmartMotionAccelStrategy(c_SparkMax_handle handle, int slotID, c_SparkMax_AccelStrategy accelStrategy)
{
    ((SnobotSim::RevSimulator*)handle)->Send("SetSmartMotionAccelStrategy", slotID, accelStrategy);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_SetSmartMotionAllowedClosedLoopError(c_SparkMax_handle handle, int slotID, float allowedError)
{
    ((SnobotSim::RevSimulator*)handle)->Send("SetSmartMotionAllowedClosedLoopError", slotID, allowedError);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_GetSmartMotionMaxVelocity(c_SparkMax_handle handle, int slotID, float* maxVel)
{
    RECEIVE_HELPER("GetSmartMotionMaxVelocity", sizeof(slotID) + sizeof(*maxVel));
    PoplateReceiveResults(buffer, &slotID, buffer_pos);
    PoplateReceiveResults(buffer, maxVel, buffer_pos);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_GetSmartMotionMaxAccel(c_SparkMax_handle handle, int slotID, float* maxAccel)
{
    RECEIVE_HELPER("GetSmartMotionMaxAccel", sizeof(slotID) + sizeof(*maxAccel));
    PoplateReceiveResults(buffer, &slotID, buffer_pos);
    PoplateReceiveResults(buffer, maxAccel, buffer_pos);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_GetSmartMotionMinOutputVelocity(c_SparkMax_handle handle, int slotID, float* minVel)
{
    RECEIVE_HELPER("GetSmartMotionMinOutputVelocity", sizeof(slotID) + sizeof(*minVel));
    PoplateReceiveResults(buffer, &slotID, buffer_pos);
    PoplateReceiveResults(buffer, minVel, buffer_pos);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_GetSmartMotionAccelStrategy(c_SparkMax_handle handle, int slotID, c_SparkMax_AccelStrategy* accelStrategy)
{
    RECEIVE_HELPER("GetSmartMotionAccelStrategy", sizeof(slotID) + sizeof(*accelStrategy));
    PoplateReceiveResults(buffer, &slotID, buffer_pos);
    PoplateReceiveResults(buffer, accelStrategy, buffer_pos);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_GetSmartMotionAllowedClosedLoopError(c_SparkMax_handle handle, int slotID, float* allowedError)
{
    RECEIVE_HELPER("GetSmartMotionAllowedClosedLoopError", sizeof(slotID) + sizeof(*allowedError));
    PoplateReceiveResults(buffer, &slotID, buffer_pos);
    PoplateReceiveResults(buffer, allowedError, buffer_pos);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_SetIMaxAccum(c_SparkMax_handle handle, int slotID, float iMaxAccum)
{
    ((SnobotSim::RevSimulator*)handle)->Send("SetIMaxAccum", slotID, iMaxAccum);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_GetIMaxAccum(c_SparkMax_handle handle, int slotID, float* iMaxAccum)
{
    RECEIVE_HELPER("GetIMaxAccum", sizeof(slotID) + sizeof(*iMaxAccum));
    PoplateReceiveResults(buffer, &slotID, buffer_pos);
    PoplateReceiveResults(buffer, iMaxAccum, buffer_pos);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_GetIAccum(c_SparkMax_handle handle, float* iAccum)
{
    RECEIVE_HELPER("GetIAccum", sizeof(*iAccum));
    PoplateReceiveResults(buffer, iAccum, buffer_pos);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_SetFeedbackDevice(c_SparkMax_handle handle, uint32_t sensorID)
{
    ((SnobotSim::RevSimulator*)handle)->Send("SetFeedbackDevice", sensorID);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_GetFeedbackDeviceID(c_SparkMax_handle handle, uint32_t* id)
{
    RECEIVE_HELPER("GetFeedbackDeviceID", sizeof(*id));
    PoplateReceiveResults(buffer, id, buffer_pos);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_SetFeedbackDeviceRange(c_SparkMax_handle handle, float min, float max)
{
    ((SnobotSim::RevSimulator*)handle)->Send("SetFeedbackDeviceRange", min, max);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_GetLastError(c_SparkMax_handle handle)
{
    ((SnobotSim::RevSimulator*)handle)->Send("GetLastError");
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_GenerateError(int deviceID, c_SparkMax_ErrorCode error)
{
    LOG_UNSUPPORTED_CAN_FUNC("");
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_ReadTelemetryStream(c_SparkMax_handle handle, uint32_t telemetryHandle, c_SparkMax_TelemetryMessage* messages, c_SparkMax_TelemetryID* ids, uint32_t numOfStreams)
{
    RECEIVE_HELPER("ReadTelemetryStream", sizeof(telemetryHandle) + sizeof(*messages) + sizeof(*ids) + sizeof(numOfStreams));
    PoplateReceiveResults(buffer, &telemetryHandle, buffer_pos);
    PoplateReceiveResults(buffer, messages, buffer_pos);
    PoplateReceiveResults(buffer, ids, buffer_pos);
    PoplateReceiveResults(buffer, &numOfStreams, buffer_pos);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_OpenTelemetryStream(c_SparkMax_handle handle, uint32_t* telemetryHandle)
{
    RECEIVE_HELPER("OpenTelemetryStream", sizeof(*telemetryHandle));
    PoplateReceiveResults(buffer, telemetryHandle, buffer_pos);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_CloseTelemetryStream(c_SparkMax_handle handle, uint32_t telemetryHandle)
{
    ((SnobotSim::RevSimulator*)handle)->Send("CloseTelemetryStream", telemetryHandle);
    return (c_SparkMax_ErrorCode) 0;
}
c_SparkMax_ErrorCode c_SparkMax_ListTelemetryStream(c_SparkMax_handle handle, c_SparkMax_TelemetryMessage* messages)
{
    RECEIVE_HELPER("ListTelemetryStream", sizeof(*messages));
    PoplateReceiveResults(buffer, messages, buffer_pos);
    return (c_SparkMax_ErrorCode) 0;
}
