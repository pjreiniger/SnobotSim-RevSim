#include "rev/CANSparkMaxDriver.h"

#include <cstring>
#include <vector>

#include "RevSimMocks/RevCANSparkMaxDriverWrapper.h"
#include "RevSimUtils/RevMockUtilities.h"

namespace
{
SnobotSim::RevCANSparkMaxDriverWrapper* ConvertToWrapper(c_SparkMax_handle handle)
{
    return (SnobotSim::RevCANSparkMaxDriverWrapper*)handle;
}
} // namespace

extern "C" {

c_SparkMax_handle c_SparkMax_Create(int deviceId, c_SparkMax_MotorType type)
{
    SnobotSim::RevCANSparkMaxDriverWrapper* output = new SnobotSim::RevCANSparkMaxDriverWrapper(deviceId);
    return (c_SparkMax_handle)output;
}
c_SparkMax_handle c_SparkMax_Create_Inplace(int deviceId)
{
    SnobotSim::RevCANSparkMaxDriverWrapper* output = new SnobotSim::RevCANSparkMaxDriverWrapper(deviceId);
    return (c_SparkMax_handle)output;
}
void c_SparkMax_Destroy(c_SparkMax_handle handle)
{
    auto* wrapper = ConvertToWrapper(handle);
    delete wrapper;
}
c_SparkMax_ErrorCode c_SparkMax_GetFirmwareVersion(c_SparkMax_handle handle, c_SparkMax_FirmwareVersion* fwVersion)
{
    ConvertToWrapper(handle)->GetFirmwareVersion(fwVersion);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_GetSerialNumber(c_SparkMax_handle handle, uint32_t* serialNumber[3])
{
    ConvertToWrapper(handle)->GetSerialNumber(serialNumber);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_GetDeviceId(c_SparkMax_handle handle, int* deviceId)
{
    ConvertToWrapper(handle)->GetDeviceId(deviceId);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_SetMotorType(c_SparkMax_handle handle, c_SparkMax_MotorType type)
{
    ConvertToWrapper(handle)->SetMotorType(type);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_GetMotorType(c_SparkMax_handle handle, c_SparkMax_MotorType* type)
{
    ConvertToWrapper(handle)->GetMotorType(type);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_SetPeriodicFramePeriod(c_SparkMax_handle handle, c_SparkMax_PeriodicFrame frameId, int periodMs)
{
    ConvertToWrapper(handle)->SetPeriodicFramePeriod(frameId, periodMs);
    return (c_SparkMax_ErrorCode)0;
}
void c_SparkMax_SetControlFramePeriod(c_SparkMax_handle handle, int periodMs)
{
    ConvertToWrapper(handle)->SetControlFramePeriod(periodMs);
}
int c_SparkMax_GetControlFramePeriod(c_SparkMax_handle handle)
{
    return ConvertToWrapper(handle)->GetControlFramePeriod();
}
c_SparkMax_ErrorCode c_SparkMax_SetParameterFloat32(c_SparkMax_handle handle, c_SparkMax_ConfigParameter paramId, float value)
{
    ConvertToWrapper(handle)->SetParameterFloat32(paramId, value);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_SetParameterInt32(c_SparkMax_handle handle, c_SparkMax_ConfigParameter paramId, int32_t value)
{
    ConvertToWrapper(handle)->SetParameterInt32(paramId, value);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_SetParameterUint32(c_SparkMax_handle handle, c_SparkMax_ConfigParameter paramId, uint32_t value)
{
    ConvertToWrapper(handle)->SetParameterUint32(paramId, value);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_SetParameterBool(c_SparkMax_handle handle, c_SparkMax_ConfigParameter paramId, uint8_t value)
{
    ConvertToWrapper(handle)->SetParameterBool(paramId, value);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_GetParameterFloat32(c_SparkMax_handle handle, c_SparkMax_ConfigParameter paramId, float* value)
{
    ConvertToWrapper(handle)->GetParameterFloat32(paramId, value);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_GetParameterInt32(c_SparkMax_handle handle, c_SparkMax_ConfigParameter paramId, int32_t* value)
{
    ConvertToWrapper(handle)->GetParameterInt32(paramId, value);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_GetParameterUint32(c_SparkMax_handle handle, c_SparkMax_ConfigParameter paramId, uint32_t* value)
{
    ConvertToWrapper(handle)->GetParameterUint32(paramId, value);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_GetParameterBool(c_SparkMax_handle handle, c_SparkMax_ConfigParameter paramId, uint8_t* value)
{
    ConvertToWrapper(handle)->GetParameterBool(paramId, value);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_GetPeriodicStatus0(c_SparkMax_handle handle, c_SparkMax_PeriodicStatus0* rawframe)
{
    ConvertToWrapper(handle)->GetPeriodicStatus0(rawframe);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_GetPeriodicStatus1(c_SparkMax_handle handle, c_SparkMax_PeriodicStatus1* rawframe)
{
    ConvertToWrapper(handle)->GetPeriodicStatus1(rawframe);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_GetPeriodicStatus2(c_SparkMax_handle handle, c_SparkMax_PeriodicStatus2* rawframe)
{
    ConvertToWrapper(handle)->GetPeriodicStatus2(rawframe);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_GetPeriodicStatus3(c_SparkMax_handle handle, c_SparkMax_PeriodicStatus3* rawframe)
{
    ConvertToWrapper(handle)->GetPeriodicStatus3(rawframe);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_GetPeriodicStatus4(c_SparkMax_handle handle, c_SparkMax_PeriodicStatus4* rawframe)
{
    ConvertToWrapper(handle)->GetPeriodicStatus4(rawframe);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_SetEncoderPosition(c_SparkMax_handle handle, float position)
{
    ConvertToWrapper(handle)->SetEncoderPosition(position);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_SetAltEncoderPosition(c_SparkMax_handle handle, float position)
{
    ConvertToWrapper(handle)->SetAltEncoderPosition(position);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_RestoreFactoryDefaults(c_SparkMax_handle handle, uint8_t persist)
{
    ConvertToWrapper(handle)->RestoreFactoryDefaults(persist);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_FactoryWipe(c_SparkMax_handle handle, uint8_t persist)
{
    ConvertToWrapper(handle)->FactoryWipe(persist);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_SetFollow(c_SparkMax_handle handle, uint32_t followerArbId, uint32_t followerCfg)
{
    ConvertToWrapper(handle)->SetFollow(followerArbId, followerCfg);
    return (c_SparkMax_ErrorCode)0;
}
float c_SparkMax_SafeFloat(float f)
{
    LOG_UNSUPPORTED_CAN_FUNC("");
    return 0;
}
c_SparkMax_ErrorCode c_SparkMax_SetpointCommand(c_SparkMax_handle handle, float value, c_SparkMax_ControlType ctrl, int pidSlot, float arbFeedforward, int arbFFUnits)
{
    ConvertToWrapper(handle)->SetpointCommand(value, ctrl, pidSlot, arbFeedforward, arbFFUnits);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_GetDRVStatus(c_SparkMax_handle handle, c_SparkMax_DRVStatus* drvStatus)
{
    ConvertToWrapper(handle)->GetDRVStatus(drvStatus);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_SetInverted(c_SparkMax_handle handle, uint8_t inverted)
{
    ConvertToWrapper(handle)->SetInverted(inverted);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_GetInverted(c_SparkMax_handle handle, uint8_t* inverted)
{
    ConvertToWrapper(handle)->GetInverted(inverted);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_SetSmartCurrentLimit(c_SparkMax_handle handle, uint8_t stallLimit, uint8_t freeLimit, uint32_t limitRPM)
{
    ConvertToWrapper(handle)->SetSmartCurrentLimit(stallLimit, freeLimit, limitRPM);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_GetSmartCurrentLimit(c_SparkMax_handle handle, uint8_t* stallLimit, uint8_t* freeLimit, uint32_t* limitRPM)
{
    ConvertToWrapper(handle)->GetSmartCurrentLimit(stallLimit, freeLimit, limitRPM);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_SetSecondaryCurrentLimit(c_SparkMax_handle handle, float limit, int chopCycles)
{
    ConvertToWrapper(handle)->SetSecondaryCurrentLimit(limit, chopCycles);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_GetSecondaryCurrentLimit(c_SparkMax_handle handle, float* limit, int* chopCycles)
{
    ConvertToWrapper(handle)->GetSecondaryCurrentLimit(limit, chopCycles);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_SetIdleMode(c_SparkMax_handle handle, c_SparkMax_IdleMode idlemode)
{
    ConvertToWrapper(handle)->SetIdleMode(idlemode);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_GetIdleMode(c_SparkMax_handle handle, c_SparkMax_IdleMode* idlemode)
{
    ConvertToWrapper(handle)->GetIdleMode(idlemode);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_EnableVoltageCompensation(c_SparkMax_handle handle, float nominalVoltage)
{
    ConvertToWrapper(handle)->EnableVoltageCompensation(nominalVoltage);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_GetVoltageCompensationNominalVoltage(c_SparkMax_handle handle, float* nominalVoltage)
{
    ConvertToWrapper(handle)->GetVoltageCompensationNominalVoltage(nominalVoltage);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_DisableVoltageCompensation(c_SparkMax_handle handle)
{
    ConvertToWrapper(handle)->DisableVoltageCompensation();
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_SetOpenLoopRampRate(c_SparkMax_handle handle, float rate)
{
    ConvertToWrapper(handle)->SetOpenLoopRampRate(rate);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_GetOpenLoopRampRate(c_SparkMax_handle handle, float* rate)
{
    ConvertToWrapper(handle)->GetOpenLoopRampRate(rate);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_SetClosedLoopRampRate(c_SparkMax_handle handle, float rate)
{
    ConvertToWrapper(handle)->SetClosedLoopRampRate(rate);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_GetClosedLoopRampRate(c_SparkMax_handle handle, float* rate)
{
    ConvertToWrapper(handle)->GetClosedLoopRampRate(rate);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_IsFollower(c_SparkMax_handle handle, uint8_t* isFollower)
{
    ConvertToWrapper(handle)->IsFollower(isFollower);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_GetFaults(c_SparkMax_handle handle, uint16_t* faults)
{
    ConvertToWrapper(handle)->GetFaults(faults);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_GetStickyFaults(c_SparkMax_handle handle, uint16_t* stickyFaults)
{
    ConvertToWrapper(handle)->GetStickyFaults(stickyFaults);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_GetFault(c_SparkMax_handle handle, c_SparkMax_FaultID faultId, uint8_t* fault)
{
    ConvertToWrapper(handle)->GetFault(faultId, fault);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_GetStickyFault(c_SparkMax_handle handle, c_SparkMax_FaultID faultId, uint8_t* stickyfault)
{
    ConvertToWrapper(handle)->GetStickyFault(faultId, stickyfault);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_GetBusVoltage(c_SparkMax_handle handle, float* busVoltage)
{
    ConvertToWrapper(handle)->GetBusVoltage(busVoltage);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_GetAppliedOutput(c_SparkMax_handle handle, float* appliedOutput)
{
    ConvertToWrapper(handle)->GetAppliedOutput(appliedOutput);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_GetOutputCurrent(c_SparkMax_handle handle, float* outputCurrent)
{
    ConvertToWrapper(handle)->GetOutputCurrent(outputCurrent);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_GetMotorTemperature(c_SparkMax_handle handle, float* motorTemperature)
{
    ConvertToWrapper(handle)->GetMotorTemperature(motorTemperature);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_ClearFaults(c_SparkMax_handle handle)
{
    ConvertToWrapper(handle)->ClearFaults();
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_BurnFlash(c_SparkMax_handle handle)
{
    ConvertToWrapper(handle)->BurnFlash();
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_SetCANTimeout(c_SparkMax_handle handle, int timeoutMs)
{
    ConvertToWrapper(handle)->SetCANTimeout(timeoutMs);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_EnableSoftLimit(c_SparkMax_handle handle, c_SparkMax_LimitDirection dir, uint8_t enable)
{
    ConvertToWrapper(handle)->EnableSoftLimit(dir, enable);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_IsSoftLimitEnabled(c_SparkMax_handle handle, c_SparkMax_LimitDirection dir, uint8_t* enabled)
{
    ConvertToWrapper(handle)->IsSoftLimitEnabled(dir, enabled);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_SetSoftLimit(c_SparkMax_handle handle, c_SparkMax_LimitDirection dir, float limit)
{
    ConvertToWrapper(handle)->SetSoftLimit(dir, limit);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_GetSoftLimit(c_SparkMax_handle handle, c_SparkMax_LimitDirection dir, float* limit)
{
    ConvertToWrapper(handle)->GetSoftLimit(dir, limit);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_SetSensorType(c_SparkMax_handle handle, c_SparkMax_EncoderType sensorType)
{
    ConvertToWrapper(handle)->SetSensorType(sensorType);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_IDQuery(uint32_t* uniqueIdArray, size_t uniqueIdArraySize, size_t* numberOfDevices)
{
    LOG_UNSUPPORTED_CAN_FUNC("");
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_IDAssign(uint32_t uniqueId, uint8_t deviceId)
{
    LOG_UNSUPPORTED_CAN_FUNC("");
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_Identify(c_SparkMax_handle handle)
{
    ConvertToWrapper(handle)->Identify();
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_IdentifyUniqueId(uint32_t uniqueId)
{
    LOG_UNSUPPORTED_CAN_FUNC("");
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_SetLimitPolarity(c_SparkMax_handle handle, c_SparkMax_LimitDirection sw, c_SparkMax_LimitPolarity polarity)
{
    ConvertToWrapper(handle)->SetLimitPolarity(sw, polarity);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_GetLimitPolarity(c_SparkMax_handle handle, c_SparkMax_LimitDirection sw, c_SparkMax_LimitPolarity* polarity)
{
    ConvertToWrapper(handle)->GetLimitPolarity(sw, polarity);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_GetLimitSwitch(c_SparkMax_handle handle, c_SparkMax_LimitDirection sw, uint8_t* limit)
{
    ConvertToWrapper(handle)->GetLimitSwitch(sw, limit);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_EnableLimitSwitch(c_SparkMax_handle handle, c_SparkMax_LimitDirection sw, uint8_t enable)
{
    ConvertToWrapper(handle)->EnableLimitSwitch(sw, enable);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_IsLimitEnabled(c_SparkMax_handle handle, c_SparkMax_LimitDirection sw, uint8_t* enabled)
{
    ConvertToWrapper(handle)->IsLimitEnabled(sw, enabled);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_GetAnalogPosition(c_SparkMax_handle handle, float* position)
{
    ConvertToWrapper(handle)->GetAnalogPosition(position);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_GetAnalogVelocity(c_SparkMax_handle handle, float* velocity)
{
    ConvertToWrapper(handle)->GetAnalogVelocity(velocity);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_GetAnalogVoltage(c_SparkMax_handle handle, float* voltage)
{
    ConvertToWrapper(handle)->GetAnalogVoltage(voltage);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_SetAnalogPositionConversionFactor(c_SparkMax_handle handle, float conversion)
{
    ConvertToWrapper(handle)->SetAnalogPositionConversionFactor(conversion);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_SetAnalogVelocityConversionFactor(c_SparkMax_handle handle, float conversion)
{
    ConvertToWrapper(handle)->SetAnalogVelocityConversionFactor(conversion);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_GetAnalogPositionConversionFactor(c_SparkMax_handle handle, float* conversion)
{
    ConvertToWrapper(handle)->GetAnalogPositionConversionFactor(conversion);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_GetAnalogVelocityConversionFactor(c_SparkMax_handle handle, float* conversion)
{
    ConvertToWrapper(handle)->GetAnalogVelocityConversionFactor(conversion);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_SetAnalogInverted(c_SparkMax_handle handle, uint8_t inverted)
{
    ConvertToWrapper(handle)->SetAnalogInverted(inverted);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_GetAnalogInverted(c_SparkMax_handle handle, uint8_t* inverted)
{
    ConvertToWrapper(handle)->GetAnalogInverted(inverted);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_SetAnalogAverageDepth(c_SparkMax_handle handle, uint32_t depth)
{
    ConvertToWrapper(handle)->SetAnalogAverageDepth(depth);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_GetAnalogAverageDepth(c_SparkMax_handle handle, uint32_t* depth)
{
    ConvertToWrapper(handle)->GetAnalogAverageDepth(depth);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_SetAnalogMeasurementPeriod(c_SparkMax_handle handle, uint32_t samples)
{
    ConvertToWrapper(handle)->SetAnalogMeasurementPeriod(samples);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_GetAnalogMeasurementPeriod(c_SparkMax_handle handle, uint32_t* samples)
{
    ConvertToWrapper(handle)->GetAnalogMeasurementPeriod(samples);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_SetAnalogMode(c_SparkMax_handle handle, c_SparkMax_AnalogMode mode)
{
    ConvertToWrapper(handle)->SetAnalogMode(mode);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_GetAnalogMode(c_SparkMax_handle handle, c_SparkMax_AnalogMode* mode)
{
    ConvertToWrapper(handle)->GetAnalogMode(mode);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_GetEncoderPosition(c_SparkMax_handle handle, float* position)
{
    ConvertToWrapper(handle)->GetEncoderPosition(position);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_GetEncoderVelocity(c_SparkMax_handle handle, float* velocity)
{
    ConvertToWrapper(handle)->GetEncoderVelocity(velocity);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_SetPositionConversionFactor(c_SparkMax_handle handle, float conversion)
{
    ConvertToWrapper(handle)->SetPositionConversionFactor(conversion);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_SetVelocityConversionFactor(c_SparkMax_handle handle, float conversion)
{
    ConvertToWrapper(handle)->SetVelocityConversionFactor(conversion);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_GetPositionConversionFactor(c_SparkMax_handle handle, float* conversion)
{
    ConvertToWrapper(handle)->GetPositionConversionFactor(conversion);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_GetVelocityConversionFactor(c_SparkMax_handle handle, float* conversion)
{
    ConvertToWrapper(handle)->GetVelocityConversionFactor(conversion);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_SetAverageDepth(c_SparkMax_handle handle, uint32_t depth)
{
    ConvertToWrapper(handle)->SetAverageDepth(depth);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_GetAverageDepth(c_SparkMax_handle handle, uint32_t* depth)
{
    ConvertToWrapper(handle)->GetAverageDepth(depth);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_SetMeasurementPeriod(c_SparkMax_handle handle, uint32_t samples)
{
    ConvertToWrapper(handle)->SetMeasurementPeriod(samples);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_GetMeasurementPeriod(c_SparkMax_handle handle, uint32_t* samples)
{
    ConvertToWrapper(handle)->GetMeasurementPeriod(samples);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_SetCountsPerRevolution(c_SparkMax_handle handle, uint32_t cpr)
{
    ConvertToWrapper(handle)->SetCountsPerRevolution(cpr);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_GetCountsPerRevolution(c_SparkMax_handle handle, uint32_t* cpr)
{
    ConvertToWrapper(handle)->GetCountsPerRevolution(cpr);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_SetEncoderInverted(c_SparkMax_handle handle, uint8_t inverted)
{
    ConvertToWrapper(handle)->SetEncoderInverted(inverted);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_GetEncoderInverted(c_SparkMax_handle handle, uint8_t* inverted)
{
    ConvertToWrapper(handle)->GetEncoderInverted(inverted);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_GetAltEncoderPosition(c_SparkMax_handle handle, float* position)
{
    ConvertToWrapper(handle)->GetAltEncoderPosition(position);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_GetAltEncoderVelocity(c_SparkMax_handle handle, float* velocity)
{
    ConvertToWrapper(handle)->GetAltEncoderVelocity(velocity);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_SetAltEncoderPositionFactor(c_SparkMax_handle handle, float conversion)
{
    ConvertToWrapper(handle)->SetAltEncoderPositionFactor(conversion);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_SetAltEncoderVelocityFactor(c_SparkMax_handle handle, float conversion)
{
    ConvertToWrapper(handle)->SetAltEncoderVelocityFactor(conversion);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_GetAltEncoderPositionFactor(c_SparkMax_handle handle, float* conversion)
{
    ConvertToWrapper(handle)->GetAltEncoderPositionFactor(conversion);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_GetAltEncoderVelocityFactor(c_SparkMax_handle handle, float* conversion)
{
    ConvertToWrapper(handle)->GetAltEncoderVelocityFactor(conversion);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_SetAltEncoderAverageDepth(c_SparkMax_handle handle, uint32_t depth)
{
    ConvertToWrapper(handle)->SetAltEncoderAverageDepth(depth);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_GetAltEncoderAverageDepth(c_SparkMax_handle handle, uint32_t* depth)
{
    ConvertToWrapper(handle)->GetAltEncoderAverageDepth(depth);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_SetAltEncoderMeasurementPeriod(c_SparkMax_handle handle, uint32_t samples)
{
    ConvertToWrapper(handle)->SetAltEncoderMeasurementPeriod(samples);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_GetAltEncoderMeasurementPeriod(c_SparkMax_handle handle, uint32_t* samples)
{
    ConvertToWrapper(handle)->GetAltEncoderMeasurementPeriod(samples);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_SetAltEncoderCountsPerRevolution(c_SparkMax_handle handle, uint32_t cpr)
{
    ConvertToWrapper(handle)->SetAltEncoderCountsPerRevolution(cpr);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_GetAltEncoderCountsPerRevolution(c_SparkMax_handle handle, uint32_t* cpr)
{
    ConvertToWrapper(handle)->GetAltEncoderCountsPerRevolution(cpr);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_SetAltEncoderInverted(c_SparkMax_handle handle, uint8_t inverted)
{
    ConvertToWrapper(handle)->SetAltEncoderInverted(inverted);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_GetAltEncoderInverted(c_SparkMax_handle handle, uint8_t* inverted)
{
    ConvertToWrapper(handle)->GetAltEncoderInverted(inverted);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_SetDataPortConfig(c_SparkMax_handle handle, c_SparkMax_DataPortConfig config)
{
    ConvertToWrapper(handle)->SetDataPortConfig(config);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_GetDataPortConfig(c_SparkMax_handle handle, c_SparkMax_DataPortConfig* config)
{
    ConvertToWrapper(handle)->GetDataPortConfig(config);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_SetP(c_SparkMax_handle handle, int slotID, float gain)
{
    ConvertToWrapper(handle)->SetP(slotID, gain);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_SetI(c_SparkMax_handle handle, int slotID, float gain)
{
    ConvertToWrapper(handle)->SetI(slotID, gain);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_SetD(c_SparkMax_handle handle, int slotID, float gain)
{
    ConvertToWrapper(handle)->SetD(slotID, gain);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_SetDFilter(c_SparkMax_handle handle, int slotID, float gain)
{
    ConvertToWrapper(handle)->SetDFilter(slotID, gain);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_SetFF(c_SparkMax_handle handle, int slotID, float gain)
{
    ConvertToWrapper(handle)->SetFF(slotID, gain);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_SetIZone(c_SparkMax_handle handle, int slotID, float IZone)
{
    ConvertToWrapper(handle)->SetIZone(slotID, IZone);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_SetOutputRange(c_SparkMax_handle handle, int slotID, float min, float max)
{
    ConvertToWrapper(handle)->SetOutputRange(slotID, min, max);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_GetP(c_SparkMax_handle handle, int slotID, float* gain)
{
    ConvertToWrapper(handle)->GetP(slotID, gain);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_GetI(c_SparkMax_handle handle, int slotID, float* gain)
{
    ConvertToWrapper(handle)->GetI(slotID, gain);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_GetD(c_SparkMax_handle handle, int slotID, float* gain)
{
    ConvertToWrapper(handle)->GetD(slotID, gain);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_GetDFilter(c_SparkMax_handle handle, int slotID, float* gain)
{
    ConvertToWrapper(handle)->GetDFilter(slotID, gain);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_GetFF(c_SparkMax_handle handle, int slotID, float* gain)
{
    ConvertToWrapper(handle)->GetFF(slotID, gain);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_GetIZone(c_SparkMax_handle handle, int slotID, float* IZone)
{
    ConvertToWrapper(handle)->GetIZone(slotID, IZone);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_GetOutputMin(c_SparkMax_handle handle, int slotID, float* min)
{
    ConvertToWrapper(handle)->GetOutputMin(slotID, min);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_GetOutputMax(c_SparkMax_handle handle, int slotID, float* max)
{
    ConvertToWrapper(handle)->GetOutputMax(slotID, max);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_SetSmartMotionMaxVelocity(c_SparkMax_handle handle, int slotID, float maxVel)
{
    ConvertToWrapper(handle)->SetSmartMotionMaxVelocity(slotID, maxVel);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_SetSmartMotionMaxAccel(c_SparkMax_handle handle, int slotID, float maxAccel)
{
    ConvertToWrapper(handle)->SetSmartMotionMaxAccel(slotID, maxAccel);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_SetSmartMotionMinOutputVelocity(c_SparkMax_handle handle, int slotID, float minVel)
{
    ConvertToWrapper(handle)->SetSmartMotionMinOutputVelocity(slotID, minVel);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_SetSmartMotionAccelStrategy(c_SparkMax_handle handle, int slotID, c_SparkMax_AccelStrategy accelStrategy)
{
    ConvertToWrapper(handle)->SetSmartMotionAccelStrategy(slotID, accelStrategy);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_SetSmartMotionAllowedClosedLoopError(c_SparkMax_handle handle, int slotID, float allowedError)
{
    ConvertToWrapper(handle)->SetSmartMotionAllowedClosedLoopError(slotID, allowedError);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_GetSmartMotionMaxVelocity(c_SparkMax_handle handle, int slotID, float* maxVel)
{
    ConvertToWrapper(handle)->GetSmartMotionMaxVelocity(slotID, maxVel);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_GetSmartMotionMaxAccel(c_SparkMax_handle handle, int slotID, float* maxAccel)
{
    ConvertToWrapper(handle)->GetSmartMotionMaxAccel(slotID, maxAccel);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_GetSmartMotionMinOutputVelocity(c_SparkMax_handle handle, int slotID, float* minVel)
{
    ConvertToWrapper(handle)->GetSmartMotionMinOutputVelocity(slotID, minVel);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_GetSmartMotionAccelStrategy(c_SparkMax_handle handle, int slotID, c_SparkMax_AccelStrategy* accelStrategy)
{
    ConvertToWrapper(handle)->GetSmartMotionAccelStrategy(slotID, accelStrategy);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_GetSmartMotionAllowedClosedLoopError(c_SparkMax_handle handle, int slotID, float* allowedError)
{
    ConvertToWrapper(handle)->GetSmartMotionAllowedClosedLoopError(slotID, allowedError);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_SetIMaxAccum(c_SparkMax_handle handle, int slotID, float iMaxAccum)
{
    ConvertToWrapper(handle)->SetIMaxAccum(slotID, iMaxAccum);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_GetIMaxAccum(c_SparkMax_handle handle, int slotID, float* iMaxAccum)
{
    ConvertToWrapper(handle)->GetIMaxAccum(slotID, iMaxAccum);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_SetIAccum(c_SparkMax_handle handle, float iAccum)
{
    ConvertToWrapper(handle)->SetIAccum(iAccum);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_GetIAccum(c_SparkMax_handle handle, float* iAccum)
{
    ConvertToWrapper(handle)->GetIAccum(iAccum);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_SetFeedbackDevice(c_SparkMax_handle handle, uint32_t sensorID)
{
    ConvertToWrapper(handle)->SetFeedbackDevice(sensorID);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_GetFeedbackDeviceID(c_SparkMax_handle handle, uint32_t* id)
{
    ConvertToWrapper(handle)->GetFeedbackDeviceID(id);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_SetFeedbackDeviceRange(c_SparkMax_handle handle, float min, float max)
{
    ConvertToWrapper(handle)->SetFeedbackDeviceRange(min, max);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_APIVersion c_SparkMax_GetAPIVersion(void)
{
    c_SparkMax_APIVersion output{};
    output.Major = c_SparkMax_kAPIMajorVersion;
    output.Minor = c_SparkMax_kAPIMinorVersion;
    output.Build = c_SparkMax_kAPIBuildVersion;
    output.Version = c_SparkMax_kAPIVersion;

    return output;
}
void c_SparkMax_SetLastError(c_SparkMax_handle handle, c_SparkMax_ErrorCode error)
{
    ConvertToWrapper(handle)->SetLastError(error);
}
c_SparkMax_ErrorCode c_SparkMax_GetLastError(c_SparkMax_handle handle)
{
    ConvertToWrapper(handle)->GetLastError();
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_GenerateError(int deviceID, c_SparkMax_ErrorCode error)
{
    LOG_UNSUPPORTED_CAN_FUNC("");
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_ReadTelemetryStream(c_SparkMax_handle handle, uint32_t telemetryHandle, c_SparkMax_TelemetryMessage* messages, c_SparkMax_TelemetryID* ids, uint32_t numOfStreams)
{
    ConvertToWrapper(handle)->ReadTelemetryStream(telemetryHandle, messages, ids, numOfStreams);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_OpenTelemetryStream(c_SparkMax_handle handle, uint32_t* telemetryHandle)
{
    ConvertToWrapper(handle)->OpenTelemetryStream(telemetryHandle);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_CloseTelemetryStream(c_SparkMax_handle handle, uint32_t telemetryHandle)
{
    ConvertToWrapper(handle)->CloseTelemetryStream(telemetryHandle);
    return (c_SparkMax_ErrorCode)0;
}
c_SparkMax_ErrorCode c_SparkMax_ListTelemetryStream(c_SparkMax_handle handle, c_SparkMax_TelemetryMessage* messages)
{
    ConvertToWrapper(handle)->ListTelemetryStream(messages);
    return (c_SparkMax_ErrorCode)0;
}

} // extern "C"
