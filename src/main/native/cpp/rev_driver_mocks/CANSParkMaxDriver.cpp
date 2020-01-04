
#include <iostream>
#include <vector>

#include "rev/CANSParkMaxDriver.h"
#include "RevSimMocks/RevMockUtilities.h"
#include "RevSimMocks/RevDeviceWrapper.h"


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

void c_SparkMax_Destroy(c_SparkMax_handle handle)
{
	LOG_UNSUPPORTED_CAN_FUNC("");
}

c_SparkMax_ErrorCode c_SparkMax_GetFirmwareVersion(c_SparkMax_handle handle, c_SparkMax_FirmwareVersion* fwVersion)
{
	LOG_UNSUPPORTED_CAN_FUNC("");
	return (c_SparkMax_ErrorCode) 0;
}

c_SparkMax_ErrorCode c_SparkMax_GetSerialNumber(c_SparkMax_handle handle, uint32_t* serialNumber[3])
{
	LOG_UNSUPPORTED_CAN_FUNC("");
	return (c_SparkMax_ErrorCode) 0;
}

c_SparkMax_ErrorCode c_SparkMax_GetDeviceId(c_SparkMax_handle handle, int* deviceId)
{
	LOG_UNSUPPORTED_CAN_FUNC("");
	return (c_SparkMax_ErrorCode) 0;
}

c_SparkMax_ErrorCode c_SparkMax_SetMotorType(c_SparkMax_handle handle, c_SparkMax_MotorType type)
{
	LOG_UNSUPPORTED_CAN_FUNC("");
	return (c_SparkMax_ErrorCode) 0;
}

c_SparkMax_ErrorCode c_SparkMax_GetMotorType(c_SparkMax_handle handle, c_SparkMax_MotorType* type)
{
	LOG_UNSUPPORTED_CAN_FUNC("");
	return (c_SparkMax_ErrorCode) 0;
}

c_SparkMax_ErrorCode c_SparkMax_SetPeriodicFramePeriod(c_SparkMax_handle handle, c_SparkMax_PeriodicFrame frameId, int periodMs)
{
	LOG_UNSUPPORTED_CAN_FUNC("");
	return (c_SparkMax_ErrorCode) 0;
}

void c_SparkMax_SetControlFramePeriod(c_SparkMax_handle handle, int periodMs);
int c_SparkMax_GetControlFramePeriod(c_SparkMax_handle handle);

c_SparkMax_ErrorCode c_SparkMax_SetParameterFloat32(c_SparkMax_handle handle, c_SparkMax_ConfigParameter paramId, float value);
c_SparkMax_ErrorCode c_SparkMax_SetParameterInt32(c_SparkMax_handle handle, c_SparkMax_ConfigParameter paramId, int32_t value);
c_SparkMax_ErrorCode c_SparkMax_SetParameterUint32(c_SparkMax_handle handle, c_SparkMax_ConfigParameter paramId, uint32_t value);
c_SparkMax_ErrorCode c_SparkMax_SetParameterBool(c_SparkMax_handle handle, c_SparkMax_ConfigParameter paramId, uint8_t value);
c_SparkMax_ErrorCode c_SparkMax_GetParameterFloat32(c_SparkMax_handle handle, c_SparkMax_ConfigParameter paramId, float* value);
c_SparkMax_ErrorCode c_SparkMax_GetParameterInt32(c_SparkMax_handle handle, c_SparkMax_ConfigParameter paramId, int32_t* value);
c_SparkMax_ErrorCode c_SparkMax_GetParameterUint32(c_SparkMax_handle handle, c_SparkMax_ConfigParameter paramId, uint32_t* value);
c_SparkMax_ErrorCode c_SparkMax_GetParameterBool(c_SparkMax_handle handle, c_SparkMax_ConfigParameter paramId, uint8_t* value);
//c_SparkMax_ParameterType c_SparkMax_GetParameterType(c_SparkMax_ConfigParameter paramId);
c_SparkMax_ErrorCode c_SparkMax_GetPeriodicStatus0(c_SparkMax_handle handle, c_SparkMax_PeriodicStatus0* rawframe);
c_SparkMax_ErrorCode c_SparkMax_GetPeriodicStatus1(c_SparkMax_handle handle, c_SparkMax_PeriodicStatus1* rawframe);
c_SparkMax_ErrorCode c_SparkMax_GetPeriodicStatus2(c_SparkMax_handle handle, c_SparkMax_PeriodicStatus2* rawframe);
c_SparkMax_ErrorCode c_SparkMax_GetPeriodicStatus3(c_SparkMax_handle handle, c_SparkMax_PeriodicStatus3* rawframe);
c_SparkMax_ErrorCode c_SparkMax_GetPeriodicStatus4(c_SparkMax_handle handle, c_SparkMax_PeriodicStatus4* rawframe);

c_SparkMax_ErrorCode c_SparkMax_SetEncoderPosition(c_SparkMax_handle handle, float position);
c_SparkMax_ErrorCode c_SparkMax_SetAltEncoderPosition(c_SparkMax_handle handle, float position);
c_SparkMax_ErrorCode c_SparkMax_SetIAccum(c_SparkMax_handle handle, float Iaccum);
c_SparkMax_ErrorCode c_SparkMax_RestoreFactoryDefaults(c_SparkMax_handle handle, uint8_t persist);
c_SparkMax_ErrorCode c_SparkMax_FactoryWipe(c_SparkMax_handle handle, uint8_t persist);

c_SparkMax_ErrorCode c_SparkMax_SetFollow(c_SparkMax_handle handle, uint32_t followerArbId, uint32_t followerCfg);
//c_SparkMax_ErrorCode c_SparkMax_FollowerInvert(c_SparkMax_handle handle, uint8_t invert);
float c_SparkMax_SafeFloat(float f);

c_SparkMax_ErrorCode c_SparkMax_SetpointCommand(c_SparkMax_handle handle, float value, c_SparkMax_ControlType ctrl,
                                    int pidSlot, float arbFeedforward, int arbFFUnits)
{
    ((SnobotSim::RevSimulator*)handle)->Send("SetpointCommand", value, ctrl, pidSlot, arbFeedforward, arbFFUnits);
	return (c_SparkMax_ErrorCode) 0;
}

c_SparkMax_ErrorCode c_SparkMax_GetDRVStatus(c_SparkMax_handle handle, c_SparkMax_DRVStatus* drvStatus);

// CANSparkMax
c_SparkMax_ErrorCode c_SparkMax_SetInverted(c_SparkMax_handle handle, uint8_t inverted);
c_SparkMax_ErrorCode c_SparkMax_GetInverted(c_SparkMax_handle handle, uint8_t* inverted);
c_SparkMax_ErrorCode c_SparkMax_SetSmartCurrentLimit(c_SparkMax_handle handle, uint8_t stallLimit, uint8_t freeLimit, uint32_t limitRPM);
c_SparkMax_ErrorCode c_SparkMax_GetSmartCurrentLimit(c_SparkMax_handle handle, uint8_t* stallLimit, uint8_t* freeLimit, uint32_t* limitRPM);
c_SparkMax_ErrorCode c_SparkMax_SetSecondaryCurrentLimit(c_SparkMax_handle handle, float limit, int chopCycles);
c_SparkMax_ErrorCode c_SparkMax_GetSecondaryCurrentLimit(c_SparkMax_handle handle, float* limit, int* chopCycles);
c_SparkMax_ErrorCode c_SparkMax_SetIdleMode(c_SparkMax_handle handle, c_SparkMax_IdleMode idlemode);
c_SparkMax_ErrorCode c_SparkMax_GetIdleMode(c_SparkMax_handle handle, c_SparkMax_IdleMode* idlemode);
c_SparkMax_ErrorCode c_SparkMax_EnableVoltageCompensation(c_SparkMax_handle handle, float nominalVoltage);
c_SparkMax_ErrorCode c_SparkMax_GetVoltageCompensationNominalVoltage(c_SparkMax_handle handle, float* nominalVoltage);
c_SparkMax_ErrorCode c_SparkMax_DisableVoltageCompensation(c_SparkMax_handle handle);
c_SparkMax_ErrorCode c_SparkMax_SetOpenLoopRampRate(c_SparkMax_handle handle, float rate);
c_SparkMax_ErrorCode c_SparkMax_GetOpenLoopRampRate(c_SparkMax_handle handle, float* rate);
c_SparkMax_ErrorCode c_SparkMax_SetClosedLoopRampRate(c_SparkMax_handle handle, float rate);
c_SparkMax_ErrorCode c_SparkMax_GetClosedLoopRampRate(c_SparkMax_handle handle, float* rate);
c_SparkMax_ErrorCode c_SparkMax_IsFollower(c_SparkMax_handle handle, uint8_t* isFollower);
c_SparkMax_ErrorCode c_SparkMax_GetFaults(c_SparkMax_handle handle, uint16_t* faults);
c_SparkMax_ErrorCode c_SparkMax_GetStickyFaults(c_SparkMax_handle handle, uint16_t* stickyFaults);
c_SparkMax_ErrorCode c_SparkMax_GetFault(c_SparkMax_handle handle, c_SparkMax_FaultID faultId, uint8_t* fault);
c_SparkMax_ErrorCode c_SparkMax_GetStickyFault(c_SparkMax_handle handle, c_SparkMax_FaultID faultId, uint8_t* stickyfault);
c_SparkMax_ErrorCode c_SparkMax_GetBusVoltage(c_SparkMax_handle handle, float* busVoltage);
c_SparkMax_ErrorCode c_SparkMax_GetAppliedOutput(c_SparkMax_handle handle, float* appliedOutput);
c_SparkMax_ErrorCode c_SparkMax_GetOutputCurrent(c_SparkMax_handle handle, float* outputCurrent);
c_SparkMax_ErrorCode c_SparkMax_GetMotorTemperature(c_SparkMax_handle handle, float* motorTemperature);
c_SparkMax_ErrorCode c_SparkMax_ClearFaults(c_SparkMax_handle handle);
c_SparkMax_ErrorCode c_SparkMax_BurnFlash(c_SparkMax_handle handle);
c_SparkMax_ErrorCode c_SparkMax_SetCANTimeout(c_SparkMax_handle handle, int timeoutMs);
c_SparkMax_ErrorCode c_SparkMax_EnableSoftLimit(c_SparkMax_handle handle, c_SparkMax_LimitDirection dir, uint8_t enable);
c_SparkMax_ErrorCode c_SparkMax_IsSoftLimitEnabled(c_SparkMax_handle handle, c_SparkMax_LimitDirection dir, uint8_t* enabled);
c_SparkMax_ErrorCode c_SparkMax_SetSoftLimit(c_SparkMax_handle handle, c_SparkMax_LimitDirection dir, float limit);
c_SparkMax_ErrorCode c_SparkMax_GetSoftLimit(c_SparkMax_handle handle, c_SparkMax_LimitDirection dir, float* limit);
c_SparkMax_ErrorCode c_SparkMax_SetSensorType(c_SparkMax_handle handle, c_SparkMax_EncoderType sensorType);
c_SparkMax_ErrorCode c_SparkMax_IDQuery(uint32_t* uniqueIdArray, size_t uniqueIdArraySize, size_t* numberOfDevices);
c_SparkMax_ErrorCode c_SparkMax_IDAssign(uint32_t uniqueId, uint8_t deviceId);
c_SparkMax_ErrorCode c_SparkMax_Identify(c_SparkMax_handle handle);
c_SparkMax_ErrorCode c_SparkMax_IdentifyUniqueId(uint32_t uniqueId);

// Digital Input
c_SparkMax_ErrorCode c_SparkMax_SetLimitPolarity(c_SparkMax_handle handle, c_SparkMax_LimitDirection sw, c_SparkMax_LimitPolarity polarity);
c_SparkMax_ErrorCode c_SparkMax_GetLimitPolarity(c_SparkMax_handle handle, c_SparkMax_LimitDirection sw, c_SparkMax_LimitPolarity* polarity);
c_SparkMax_ErrorCode c_SparkMax_GetLimitSwitch(c_SparkMax_handle handle, c_SparkMax_LimitDirection sw, uint8_t* limit);
c_SparkMax_ErrorCode c_SparkMax_EnableLimitSwitch(c_SparkMax_handle handle, c_SparkMax_LimitDirection sw, uint8_t enable);
c_SparkMax_ErrorCode c_SparkMax_IsLimitEnabled(c_SparkMax_handle handle, c_SparkMax_LimitDirection sw, uint8_t* enabled);

// CANAnalog
c_SparkMax_ErrorCode c_SparkMax_GetAnalogPosition(c_SparkMax_handle handle, float* position);
c_SparkMax_ErrorCode c_SparkMax_GetAnalogVelocity(c_SparkMax_handle handle, float* velocity);
c_SparkMax_ErrorCode c_SparkMax_GetAnalogVoltage(c_SparkMax_handle, float* voltage);
c_SparkMax_ErrorCode c_SparkMax_SetAnalogPositionConversionFactor(c_SparkMax_handle, float conversion);
c_SparkMax_ErrorCode c_SparkMax_SetAnalogVelocityConversionFactor(c_SparkMax_handle, float conversion);
c_SparkMax_ErrorCode c_SparkMax_GetAnalogPositionConversionFactor(c_SparkMax_handle, float* conversion);
c_SparkMax_ErrorCode c_SparkMax_GetAnalogVelocityConversionFactor(c_SparkMax_handle, float* conversion);
c_SparkMax_ErrorCode c_SparkMax_SetAnalogInverted(c_SparkMax_handle, uint8_t inverted);
c_SparkMax_ErrorCode c_SparkMax_GetAnalogInverted(c_SparkMax_handle, uint8_t* inverted);
c_SparkMax_ErrorCode c_SparkMax_SetAnalogAverageDepth(c_SparkMax_handle handle, uint32_t depth);
c_SparkMax_ErrorCode c_SparkMax_GetAnalogAverageDepth(c_SparkMax_handle handle, uint32_t* depth);
c_SparkMax_ErrorCode c_SparkMax_SetAnalogMeasurementPeriod(c_SparkMax_handle handle, uint32_t samples);
c_SparkMax_ErrorCode c_SparkMax_GetAnalogMeasurementPeriod(c_SparkMax_handle handle, uint32_t* samples);
c_SparkMax_ErrorCode c_SparkMax_SetAnalogMode(c_SparkMax_handle handle, c_SparkMax_AnalogMode mode);
c_SparkMax_ErrorCode c_SparkMax_GetAnalogMode(c_SparkMax_handle handle, c_SparkMax_AnalogMode* mode);

// CANEncoder
c_SparkMax_ErrorCode c_SparkMax_GetEncoderPosition(c_SparkMax_handle handle, float* position);
c_SparkMax_ErrorCode c_SparkMax_GetEncoderVelocity(c_SparkMax_handle handle, float* velocity);
c_SparkMax_ErrorCode c_SparkMax_SetPositionConversionFactor(c_SparkMax_handle handle, float conversion);
c_SparkMax_ErrorCode c_SparkMax_SetVelocityConversionFactor(c_SparkMax_handle handle, float conversion);
c_SparkMax_ErrorCode c_SparkMax_GetPositionConversionFactor(c_SparkMax_handle handle, float* conversion);
c_SparkMax_ErrorCode c_SparkMax_GetVelocityConversionFactor(c_SparkMax_handle handle, float* conversion);
c_SparkMax_ErrorCode c_SparkMax_SetAverageDepth(c_SparkMax_handle handle, uint32_t depth);
c_SparkMax_ErrorCode c_SparkMax_GetAverageDepth(c_SparkMax_handle handle, uint32_t* depth);
c_SparkMax_ErrorCode c_SparkMax_SetMeasurementPeriod(c_SparkMax_handle handle, uint32_t samples);
c_SparkMax_ErrorCode c_SparkMax_GetMeasurementPeriod(c_SparkMax_handle handle, uint32_t* samples);
c_SparkMax_ErrorCode c_SparkMax_SetCountsPerRevolution(c_SparkMax_handle handle, uint32_t cpr);
c_SparkMax_ErrorCode c_SparkMax_GetCountsPerRevolution(c_SparkMax_handle handle, uint32_t* cpr);
c_SparkMax_ErrorCode c_SparkMax_SetEncoderInverted(c_SparkMax_handle handle, uint8_t inverted);
c_SparkMax_ErrorCode c_SparkMax_GetEncoderInverted(c_SparkMax_handle handle, uint8_t* inverted);

// Alt Encoder
c_SparkMax_ErrorCode c_SparkMax_GetAltEncoderPosition(c_SparkMax_handle handle, float* position);
c_SparkMax_ErrorCode c_SparkMax_GetAltEncoderVelocity(c_SparkMax_handle handle, float* velocity);
c_SparkMax_ErrorCode c_SparkMax_SetAltEncoderPositionFactor(c_SparkMax_handle handle, float conversion);
c_SparkMax_ErrorCode c_SparkMax_SetAltEncoderVelocityFactor(c_SparkMax_handle handle, float conversion);
c_SparkMax_ErrorCode c_SparkMax_GetAltEncoderPositionFactor(c_SparkMax_handle handle, float* conversion);
c_SparkMax_ErrorCode c_SparkMax_GetAltEncoderVelocityFactor(c_SparkMax_handle handle, float* conversion);
c_SparkMax_ErrorCode c_SparkMax_SetAltEncoderAverageDepth(c_SparkMax_handle handle, uint32_t depth);
c_SparkMax_ErrorCode c_SparkMax_GetAltEncoderAverageDepth(c_SparkMax_handle handle, uint32_t* depth);
c_SparkMax_ErrorCode c_SparkMax_SetAltEncoderMeasurementPeriod(c_SparkMax_handle handle, uint32_t samples);
c_SparkMax_ErrorCode c_SparkMax_GetAltEncoderMeasurementPeriod(c_SparkMax_handle handle, uint32_t* samples);
c_SparkMax_ErrorCode c_SparkMax_SetAltEncoderCountsPerRevolution(c_SparkMax_handle handle, uint32_t cpr);
c_SparkMax_ErrorCode c_SparkMax_GetAltEncoderCountsPerRevolution(c_SparkMax_handle handle, uint32_t* cpr);
c_SparkMax_ErrorCode c_SparkMax_SetAltEncoderInverted(c_SparkMax_handle handle, uint8_t inverted);
c_SparkMax_ErrorCode c_SparkMax_GetAltEncoderInverted(c_SparkMax_handle handle, uint8_t* inverted);

c_SparkMax_ErrorCode c_SparkMax_SetDataPortConfig(c_SparkMax_handle handle, c_SparkMax_DataPortConfig config);
c_SparkMax_ErrorCode c_SparkMax_GetDataPortConfig(c_SparkMax_handle handle, c_SparkMax_DataPortConfig* config);

// CANPIDController
c_SparkMax_ErrorCode c_SparkMax_SetP(c_SparkMax_handle handle, int slotID, float gain);
c_SparkMax_ErrorCode c_SparkMax_SetI(c_SparkMax_handle handle, int slotID, float gain);
c_SparkMax_ErrorCode c_SparkMax_SetD(c_SparkMax_handle handle, int slotID, float gain);
c_SparkMax_ErrorCode c_SparkMax_SetDFilter(c_SparkMax_handle handle, int slotID, float gain);
c_SparkMax_ErrorCode c_SparkMax_SetFF(c_SparkMax_handle handle, int slotID, float gain);
c_SparkMax_ErrorCode c_SparkMax_SetIZone(c_SparkMax_handle handle, int slotID, float IZone);
c_SparkMax_ErrorCode c_SparkMax_SetOutputRange(c_SparkMax_handle handle, int slotID, float min, float max);
c_SparkMax_ErrorCode c_SparkMax_GetP(c_SparkMax_handle handle, int slotID, float* gain);
c_SparkMax_ErrorCode c_SparkMax_GetI(c_SparkMax_handle handle, int slotID, float* gain);
c_SparkMax_ErrorCode c_SparkMax_GetD(c_SparkMax_handle handle, int slotID, float* gain);
c_SparkMax_ErrorCode c_SparkMax_GetDFilter(c_SparkMax_handle handle, int slotID, float* gain);
c_SparkMax_ErrorCode c_SparkMax_GetFF(c_SparkMax_handle handle, int slotID, float* gain);
c_SparkMax_ErrorCode c_SparkMax_GetIZone(c_SparkMax_handle handle, int slotID, float* IZone);
c_SparkMax_ErrorCode c_SparkMax_GetOutputMin(c_SparkMax_handle handle, int slotID, float* min);
c_SparkMax_ErrorCode c_SparkMax_GetOutputMax(c_SparkMax_handle handle, int slotID, float* max);

c_SparkMax_ErrorCode c_SparkMax_SetSmartMotionMaxVelocity(c_SparkMax_handle handle, int slotID, float maxVel);
c_SparkMax_ErrorCode c_SparkMax_SetSmartMotionMaxAccel(c_SparkMax_handle handle, int slotID, float maxAccel);
c_SparkMax_ErrorCode c_SparkMax_SetSmartMotionMinOutputVelocity(c_SparkMax_handle handle, int slotID, float minVel);
c_SparkMax_ErrorCode c_SparkMax_SetSmartMotionAccelStrategy(c_SparkMax_handle handle, int slotID, c_SparkMax_AccelStrategy accelStrategy);
c_SparkMax_ErrorCode c_SparkMax_SetSmartMotionAllowedClosedLoopError(c_SparkMax_handle handle, int slotID, float allowedError);
c_SparkMax_ErrorCode c_SparkMax_GetSmartMotionMaxVelocity(c_SparkMax_handle handle, int slotID, float* maxVel);
c_SparkMax_ErrorCode c_SparkMax_GetSmartMotionMaxAccel(c_SparkMax_handle handle, int slotID, float* maxAccel);
c_SparkMax_ErrorCode c_SparkMax_GetSmartMotionMinOutputVelocity(c_SparkMax_handle handle, int slotID, float* minVel);
c_SparkMax_ErrorCode c_SparkMax_GetSmartMotionAccelStrategy(c_SparkMax_handle handle, int slotID, c_SparkMax_AccelStrategy* accelStrategy);
c_SparkMax_ErrorCode c_SparkMax_GetSmartMotionAllowedClosedLoopError(c_SparkMax_handle handle, int slotID, float* allowedError);

c_SparkMax_ErrorCode c_SparkMax_SetIMaxAccum(c_SparkMax_handle handle, int slotID, float iMaxAccum);
c_SparkMax_ErrorCode c_SparkMax_GetIMaxAccum(c_SparkMax_handle handle, int slotID, float* iMaxAccum);
c_SparkMax_ErrorCode c_SparkMax_SetIAccum(c_SparkMax_handle handle, float iAccum);
c_SparkMax_ErrorCode c_SparkMax_GetIAccum(c_SparkMax_handle handle, float* iAccum);

c_SparkMax_ErrorCode c_SparkMax_SetFeedbackDevice(c_SparkMax_handle handle, uint32_t sensorID);
c_SparkMax_ErrorCode c_SparkMax_GetFeedbackDeviceID(c_SparkMax_handle handle, uint32_t* id);
c_SparkMax_ErrorCode c_SparkMax_SetFeedbackDeviceRange(c_SparkMax_handle handle, float min, float max);

// Other helpers
c_SparkMax_APIVersion c_SparkMax_GetAPIVersion();
void c_SparkMax_SetLastError(c_SparkMax_handle handle, c_SparkMax_ErrorCode error);
c_SparkMax_ErrorCode c_SparkMax_GetLastError(c_SparkMax_handle handle);
c_SparkMax_ErrorCode c_SparkMax_GenerateError(int deviceID, c_SparkMax_ErrorCode error);

// Streamable
c_SparkMax_ErrorCode c_SparkMax_ReadTelemetryStream(c_SparkMax_handle handle, uint32_t telemetryHandle, c_SparkMax_TelemetryMessage* messages,
                                                    c_SparkMax_TelemetryID* ids, uint32_t numOfStreams);
c_SparkMax_ErrorCode c_SparkMax_OpenTelemetryStream(c_SparkMax_handle handle, uint32_t* telemetryHandle);
c_SparkMax_ErrorCode c_SparkMax_CloseTelemetryStream(c_SparkMax_handle handle, uint32_t telemetryHandle);
c_SparkMax_ErrorCode c_SparkMax_ListTelemetryStream(c_SparkMax_handle handle, c_SparkMax_TelemetryMessage* messages);


//#include "RevJni/com_re
