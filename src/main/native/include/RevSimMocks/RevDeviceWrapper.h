
#pragma once

#include <string>

#include "RevSimMocks/BaseRevWrapper.h"
#include "RevSimMocks/RevMockUtilities.h"
#include "rev/CANSparkMaxDriver.h"

namespace SnobotSim
{

class RevSimulator : public BaseRevWrapper
{
public:
    using BaseRevWrapper::Send;

    RevSimulator(int aHandle, const std::string& aName);
    const int mDeviceId;

    void Receive(const std::string& aName, uint8_t* aBuffer, int aSize);
    void Send(const std::string& aName, uint8_t* aBuffer, int aSize);

    void GetFirmwareVersion(c_SparkMax_FirmwareVersion* fwVersion);
    void GetSerialNumber(uint32_t* serialNumber[3]);
    void GetDeviceId(int* deviceId);
    void SetMotorType(c_SparkMax_MotorType type);
    void GetMotorType(c_SparkMax_MotorType* type);
    void SetPeriodicFramePeriod(c_SparkMax_PeriodicFrame frameId, int periodMs);
    void SetControlFramePeriod(int periodMs);
    int GetControlFramePeriod();
    void SetParameterFloat32(c_SparkMax_ConfigParameter paramId, float value);
    void SetParameterInt32(c_SparkMax_ConfigParameter paramId, int32_t value);
    void SetParameterUint32(c_SparkMax_ConfigParameter paramId, uint32_t value);
    void SetParameterBool(c_SparkMax_ConfigParameter paramId, uint8_t value);
    void GetParameterFloat32(c_SparkMax_ConfigParameter paramId, float* value);
    void GetParameterInt32(c_SparkMax_ConfigParameter paramId, int32_t* value);
    void GetParameterUint32(c_SparkMax_ConfigParameter paramId, uint32_t* value);
    void GetParameterBool(c_SparkMax_ConfigParameter paramId, uint8_t* value);
    void GetPeriodicStatus0(c_SparkMax_PeriodicStatus0* rawframe);
    void GetPeriodicStatus1(c_SparkMax_PeriodicStatus1* rawframe);
    void GetPeriodicStatus2(c_SparkMax_PeriodicStatus2* rawframe);
    void GetPeriodicStatus3(c_SparkMax_PeriodicStatus3* rawframe);
    void GetPeriodicStatus4(c_SparkMax_PeriodicStatus4* rawframe);
    void SetEncoderPosition(float position);
    void SetAltEncoderPosition(float position);
    void RestoreFactoryDefaults(uint8_t persist);
    void FactoryWipe(uint8_t persist);
    void SetFollow(uint32_t followerArbId, uint32_t followerCfg);
    void SafeFloat(float f);
    void SetpointCommand(float value, c_SparkMax_ControlType ctrl, int pidSlot, float arbFeedforward, int arbFFUnits);
    void GetDRVStatus(c_SparkMax_DRVStatus* drvStatus);
    void SetInverted(uint8_t inverted);
    void GetInverted(uint8_t* inverted);
    void SetSmartCurrentLimit(uint8_t stallLimit, uint8_t freeLimit, uint32_t limitRPM);
    void GetSmartCurrentLimit(uint8_t* stallLimit, uint8_t* freeLimit, uint32_t* limitRPM);
    void SetSecondaryCurrentLimit(float limit, int chopCycles);
    void GetSecondaryCurrentLimit(float* limit, int* chopCycles);
    void SetIdleMode(c_SparkMax_IdleMode idlemode);
    void GetIdleMode(c_SparkMax_IdleMode* idlemode);
    void EnableVoltageCompensation(float nominalVoltage);
    void GetVoltageCompensationNominalVoltage(float* nominalVoltage);
    void DisableVoltageCompensation();
    void SetOpenLoopRampRate(float rate);
    void GetOpenLoopRampRate(float* rate);
    void SetClosedLoopRampRate(float rate);
    void GetClosedLoopRampRate(float* rate);
    void IsFollower(uint8_t* isFollower);
    void GetFaults(uint16_t* faults);
    void GetStickyFaults(uint16_t* stickyFaults);
    void GetFault(c_SparkMax_FaultID faultId, uint8_t* fault);
    void GetStickyFault(c_SparkMax_FaultID faultId, uint8_t* stickyfault);
    void GetBusVoltage(float* busVoltage);
    void GetAppliedOutput(float* appliedOutput);
    void GetOutputCurrent(float* outputCurrent);
    void GetMotorTemperature(float* motorTemperature);
    void ClearFaults();
    void BurnFlash();
    void SetCANTimeout(int timeoutMs);
    void EnableSoftLimit(c_SparkMax_LimitDirection dir, uint8_t enable);
    void IsSoftLimitEnabled(c_SparkMax_LimitDirection dir, uint8_t* enabled);
    void SetSoftLimit(c_SparkMax_LimitDirection dir, float limit);
    void GetSoftLimit(c_SparkMax_LimitDirection dir, float* limit);
    void SetSensorType(c_SparkMax_EncoderType sensorType);
    void IDQuery(uint32_t* uniqueIdArray, size_t uniqueIdArraySize, size_t* numberOfDevices);
    void IDAssign(uint32_t uniqueId, uint8_t deviceId);
    void Identify();
    void IdentifyUniqueId(uint32_t uniqueId);
    void SetLimitPolarity(c_SparkMax_LimitDirection sw, c_SparkMax_LimitPolarity polarity);
    void GetLimitPolarity(c_SparkMax_LimitDirection sw, c_SparkMax_LimitPolarity* polarity);
    void GetLimitSwitch(c_SparkMax_LimitDirection sw, uint8_t* limit);
    void EnableLimitSwitch(c_SparkMax_LimitDirection sw, uint8_t enable);
    void IsLimitEnabled(c_SparkMax_LimitDirection sw, uint8_t* enabled);
    void GetAnalogPosition(float* position);
    void GetAnalogVelocity(float* velocity);
    void GetAnalogVoltage(float* voltage);
    void SetAnalogPositionConversionFactor(float conversion);
    void SetAnalogVelocityConversionFactor(float conversion);
    void GetAnalogPositionConversionFactor(float* conversion);
    void GetAnalogVelocityConversionFactor(float* conversion);
    void SetAnalogInverted(uint8_t inverted);
    void GetAnalogInverted(uint8_t* inverted);
    void SetAnalogAverageDepth(uint32_t depth);
    void GetAnalogAverageDepth(uint32_t* depth);
    void SetAnalogMeasurementPeriod(uint32_t samples);
    void GetAnalogMeasurementPeriod(uint32_t* samples);
    void SetAnalogMode(c_SparkMax_AnalogMode mode);
    void GetAnalogMode(c_SparkMax_AnalogMode* mode);
    void GetEncoderPosition(float* position);
    void GetEncoderVelocity(float* velocity);
    void SetPositionConversionFactor(float conversion);
    void SetVelocityConversionFactor(float conversion);
    void GetPositionConversionFactor(float* conversion);
    void GetVelocityConversionFactor(float* conversion);
    void SetAverageDepth(uint32_t depth);
    void GetAverageDepth(uint32_t* depth);
    void SetMeasurementPeriod(uint32_t samples);
    void GetMeasurementPeriod(uint32_t* samples);
    void SetCountsPerRevolution(uint32_t cpr);
    void GetCountsPerRevolution(uint32_t* cpr);
    void SetEncoderInverted(uint8_t inverted);
    void GetEncoderInverted(uint8_t* inverted);
    void GetAltEncoderPosition(float* position);
    void GetAltEncoderVelocity(float* velocity);
    void SetAltEncoderPositionFactor(float conversion);
    void SetAltEncoderVelocityFactor(float conversion);
    void GetAltEncoderPositionFactor(float* conversion);
    void GetAltEncoderVelocityFactor(float* conversion);
    void SetAltEncoderAverageDepth(uint32_t depth);
    void GetAltEncoderAverageDepth(uint32_t* depth);
    void SetAltEncoderMeasurementPeriod(uint32_t samples);
    void GetAltEncoderMeasurementPeriod(uint32_t* samples);
    void SetAltEncoderCountsPerRevolution(uint32_t cpr);
    void GetAltEncoderCountsPerRevolution(uint32_t* cpr);
    void SetAltEncoderInverted(uint8_t inverted);
    void GetAltEncoderInverted(uint8_t* inverted);
    void SetDataPortConfig(c_SparkMax_DataPortConfig config);
    void GetDataPortConfig(c_SparkMax_DataPortConfig* config);
    void SetP(int slotID, float gain);
    void SetI(int slotID, float gain);
    void SetD(int slotID, float gain);
    void SetDFilter(int slotID, float gain);
    void SetFF(int slotID, float gain);
    void SetIZone(int slotID, float IZone);
    void SetOutputRange(int slotID, float min, float max);
    void GetP(int slotID, float* gain);
    void GetI(int slotID, float* gain);
    void GetD(int slotID, float* gain);
    void GetDFilter(int slotID, float* gain);
    void GetFF(int slotID, float* gain);
    void GetIZone(int slotID, float* IZone);
    void GetOutputMin(int slotID, float* min);
    void GetOutputMax(int slotID, float* max);
    void SetSmartMotionMaxVelocity(int slotID, float maxVel);
    void SetSmartMotionMaxAccel(int slotID, float maxAccel);
    void SetSmartMotionMinOutputVelocity(int slotID, float minVel);
    void SetSmartMotionAccelStrategy(int slotID, c_SparkMax_AccelStrategy accelStrategy);
    void SetSmartMotionAllowedClosedLoopError(int slotID, float allowedError);
    void GetSmartMotionMaxVelocity(int slotID, float* maxVel);
    void GetSmartMotionMaxAccel(int slotID, float* maxAccel);
    void GetSmartMotionMinOutputVelocity(int slotID, float* minVel);
    void GetSmartMotionAccelStrategy(int slotID, c_SparkMax_AccelStrategy* accelStrategy);
    void GetSmartMotionAllowedClosedLoopError(int slotID, float* allowedError);
    void SetIMaxAccum(int slotID, float iMaxAccum);
    void GetIMaxAccum(int slotID, float* iMaxAccum);
    void SetIAccum(float iAccum);
    void GetIAccum(float* iAccum);
    void SetFeedbackDevice(uint32_t sensorID);
    void GetFeedbackDeviceID(uint32_t* id);
    void SetFeedbackDeviceRange(float min, float max);
    c_SparkMax_APIVersion GetAPIVersion();
    void SetLastError(c_SparkMax_ErrorCode error);
    void GetLastError();
    void GenerateError(int deviceID, c_SparkMax_ErrorCode error);
    void ReadTelemetryStream(uint32_t telemetryHandle, c_SparkMax_TelemetryMessage* messages, c_SparkMax_TelemetryID* ids, uint32_t numOfStreams);
    void OpenTelemetryStream(uint32_t* telemetryHandle);
    void CloseTelemetryStream(uint32_t telemetryHandle);
    void ListTelemetryStream(c_SparkMax_TelemetryMessage* messages);
};

} // namespace SnobotSim
