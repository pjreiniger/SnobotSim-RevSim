
#pragma once

#include <string>

#include "RevSimUtils/BaseRevWrapper.h"
#include "RevSimUtils/RevMockUtilities.h"
#include "rev/CANSparkMaxDriver.h"
#include "simulation/SimDeviceSim.h"

namespace SnobotSim
{

class RevCANSparkMaxDriverWrapper : public BaseRevWrapper
{
public:
    using BaseRevWrapper::Send;

    explicit RevCANSparkMaxDriverWrapper(int aDeviceId);
    const int mDeviceId;

    void Receive(const std::string& aName, uint8_t* aBuffer, int aSize);
    void Send(const std::string& aName, uint8_t* aBuffer, int aSize);

    //////////////////////////////////////////
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
    void Identify();
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
    void SetLastError(c_SparkMax_ErrorCode error);
    void GetLastError();
    void ReadTelemetryStream(uint32_t telemetryHandle, c_SparkMax_TelemetryMessage* messages, c_SparkMax_TelemetryID* ids, uint32_t numOfStreams);
    void OpenTelemetryStream(uint32_t* telemetryHandle);
    void CloseTelemetryStream(uint32_t telemetryHandle);
    void ListTelemetryStream(c_SparkMax_TelemetryMessage* messages);


protected:
    hal::SimDevice m_simDevice;


    hal::SimDouble m_AltEncoderAverageDepth_depth;
    hal::SimDouble m_AltEncoderCountsPerRevolution_cpr;
    hal::SimDouble m_AltEncoderInverted_inverted;
    hal::SimDouble m_AltEncoderMeasurementPeriod_samples;
    hal::SimDouble m_AltEncoderPositionFactor_conversion;
    hal::SimDouble m_AltEncoderPosition_position;
    hal::SimDouble m_AltEncoderVelocityFactor_conversion;
    hal::SimDouble m_AltEncoderVelocity_velocity;
    hal::SimDouble m_AnalogAverageDepth_depth;
    hal::SimDouble m_AnalogInverted_inverted;
    hal::SimDouble m_AnalogMeasurementPeriod_samples;
    hal::SimDouble m_AnalogMode_mode;
    hal::SimDouble m_AnalogPositionConversionFactor_conversion;
    hal::SimDouble m_AnalogPosition_position;
    hal::SimDouble m_AnalogVelocityConversionFactor_conversion;
    hal::SimDouble m_AnalogVelocity_velocity;
    hal::SimDouble m_AnalogVoltage_voltage;
    hal::SimDouble m_AppliedOutput_appliedOutput;
    hal::SimDouble m_AverageDepth_depth;
    hal::SimDouble m_BusVoltage_busVoltage;
    hal::SimDouble m_CloseTelemetryStream_telemetryHandle;
    hal::SimDouble m_ClosedLoopRampRate_rate;
    hal::SimDouble m_ControlFramePeriod_periodMs;
    hal::SimDouble m_CountsPerRevolution_cpr;
    hal::SimDouble m_DRVStatus_drvStatus;
    hal::SimDouble m_DataPortConfig_config;
    hal::SimDouble m_DeviceId_deviceId;
    hal::SimDouble m_EnableLimitSwitch_enable;
    hal::SimDouble m_EnableLimitSwitch_sw;
    hal::SimDouble m_EnableSoftLimit_dir;
    hal::SimDouble m_EnableSoftLimit_enable;
    hal::SimDouble m_EnableVoltageCompensation_nominalVoltage;
    hal::SimDouble m_EncoderInverted_inverted;
    hal::SimDouble m_EncoderPosition_position;
    hal::SimDouble m_EncoderVelocity_velocity;
    hal::SimDouble m_FactoryWipe_persist;
    hal::SimDouble m_Fault_fault;
    hal::SimDouble m_Fault_faultId;
    hal::SimDouble m_Faults_faults;
    hal::SimDouble m_FeedbackDeviceID_id;
    hal::SimDouble m_FeedbackDeviceRange_max;
    hal::SimDouble m_FeedbackDeviceRange_min;
    hal::SimDouble m_FeedbackDevice_sensorID;
    hal::SimDouble m_Follow_followerArbId;
    hal::SimDouble m_Follow_followerCfg;
    hal::SimDouble m_Follower_isFollower;
    hal::SimDouble m_GenerateError_deviceID;
    hal::SimDouble m_GenerateError_error;
    hal::SimDouble m_IAccum_iAccum;
    hal::SimDouble m_IDAssign_deviceId;
    hal::SimDouble m_IDAssign_uniqueId;
    hal::SimDouble m_IDQuery_numberOfDevices;
    hal::SimDouble m_IDQuery_uniqueIdArray;
    hal::SimDouble m_IDQuery_uniqueIdArraySize;
    hal::SimDouble m_IdentifyUniqueId_uniqueId;
    hal::SimDouble m_IdleMode_idlemode;
    hal::SimDouble m_Inverted_inverted;
    hal::SimDouble m_LastError_error;
    hal::SimDouble m_LimitEnabled_enabled;
    hal::SimDouble m_LimitEnabled_sw;
    hal::SimDouble m_LimitPolarity_polarity;
    hal::SimDouble m_LimitPolarity_sw;
    hal::SimDouble m_LimitSwitch_limit;
    hal::SimDouble m_LimitSwitch_sw;
    hal::SimDouble m_ListTelemetryStream_messages;
    hal::SimDouble m_MeasurementPeriod_samples;
    hal::SimDouble m_MotorTemperature_motorTemperature;
    hal::SimDouble m_MotorType_type;
    hal::SimDouble m_OpenLoopRampRate_rate;
    hal::SimDouble m_OpenTelemetryStream_telemetryHandle;
    hal::SimDouble m_OutputCurrent_outputCurrent;
    hal::SimDouble m_ParameterBool_paramId;
    hal::SimDouble m_ParameterBool_value;
    hal::SimDouble m_ParameterFloat32_paramId;
    hal::SimDouble m_ParameterFloat32_value;
    hal::SimDouble m_ParameterInt32_paramId;
    hal::SimDouble m_ParameterInt32_value;
    hal::SimDouble m_ParameterUint32_paramId;
    hal::SimDouble m_ParameterUint32_value;
    hal::SimDouble m_PeriodicFramePeriod_frameId;
    hal::SimDouble m_PeriodicFramePeriod_periodMs;
    hal::SimDouble m_PeriodicStatus0_rawframe;
    hal::SimDouble m_PeriodicStatus1_rawframe;
    hal::SimDouble m_PeriodicStatus2_rawframe;
    hal::SimDouble m_PeriodicStatus3_rawframe;
    hal::SimDouble m_PeriodicStatus4_rawframe;
    hal::SimDouble m_PositionConversionFactor_conversion;
    hal::SimDouble m_ReadTelemetryStream_ids;
    hal::SimDouble m_ReadTelemetryStream_messages;
    hal::SimDouble m_ReadTelemetryStream_numOfStreams;
    hal::SimDouble m_ReadTelemetryStream_telemetryHandle;
    hal::SimDouble m_RestoreFactoryDefaults_persist;
    hal::SimDouble m_SecondaryCurrentLimit_chopCycles;
    hal::SimDouble m_SecondaryCurrentLimit_limit;
    hal::SimDouble m_SensorType_sensorType;
    hal::SimDouble m_SerialNumber_serialNumber;
    hal::SimDouble m_SmartCurrentLimit_freeLimit;
    hal::SimDouble m_SmartCurrentLimit_limitRPM;
    hal::SimDouble m_SmartCurrentLimit_stallLimit;
    hal::SimDouble m_SoftLimitEnabled_dir;
    hal::SimDouble m_SoftLimitEnabled_enabled;
    hal::SimDouble m_SoftLimit_dir;
    hal::SimDouble m_SoftLimit_limit;
    hal::SimDouble m_StickyFault_faultId;
    hal::SimDouble m_StickyFault_stickyfault;
    hal::SimDouble m_StickyFaults_stickyFaults;
    hal::SimDouble m_VelocityConversionFactor_conversion;
    hal::SimDouble m_VoltageCompensationNominalVoltage_nominalVoltage;
    hal::SimDouble m_pointCommand_arbFFUnits;
    hal::SimDouble m_pointCommand_arbFeedforward;
    hal::SimDouble m_pointCommand_ctrl;
    hal::SimDouble m_pointCommand_pidSlot;
    hal::SimDouble m_pointCommand_value;



struct SlottedVariables
{

    hal::SimDouble m_DFilter_gain;
    hal::SimDouble m_D_gain;
    hal::SimDouble m_FF_gain;
    hal::SimDouble m_IMaxAccum_iMaxAccum;
    hal::SimDouble m_IZone_IZone;
    hal::SimDouble m_I_gain;
    hal::SimDouble m_OutputMax_max;
    hal::SimDouble m_OutputMin_min;
    hal::SimDouble m_OutputRange_max;
    hal::SimDouble m_OutputRange_min;
    hal::SimDouble m_P_gain;
    hal::SimDouble m_SmartMotionAccelStrategy_accelStrategy;
    hal::SimDouble m_SmartMotionAllowedClosedLoopError_allowedError;
    hal::SimDouble m_SmartMotionMaxAccel_maxAccel;
    hal::SimDouble m_SmartMotionMaxVelocity_maxVel;
    hal::SimDouble m_SmartMotionMinOutputVelocity_minVel;
};

SlottedVariables m_slotted_variables[6];



};

} // namespace SnobotSim
