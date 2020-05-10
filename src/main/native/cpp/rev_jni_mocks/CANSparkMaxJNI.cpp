
#include <jni.h>

#include <cassert>

#include "RevSimMocks/RevDeviceWrapper.h"
#include "RevSimMocks/RevMockUtilities.h"
#include "com_revrobotics_jni_CANSparkMaxJNI.h"
#include "rev/CANSparkMaxDriver.h"

extern "C" {

c_SparkMax_handle ConvertToMotorControllerWrapper(jlong aHandle)
{
    return (c_SparkMax_handle) reinterpret_cast<SnobotSim::RevSimulator*>(aHandle);
}

/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1Create
 * Signature: (II)J
 */
JNIEXPORT jlong JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1Create
  (JNIEnv*, jclass, jint deviceId, jint type)
{
    c_SparkMax_handle output = c_SparkMax_Create(deviceId, (c_SparkMax_MotorType)type);
    return (jlong)output;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1Destroy
 * Signature: (J)V
 */
JNIEXPORT void JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1Destroy
  (JNIEnv*, jclass, jlong handle)
{
    LOG_UNSUPPORTED_CAN_FUNC("");
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1GetFirmwareVersion
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1GetFirmwareVersion
  (JNIEnv*, jclass, jlong handle)
{
    c_SparkMax_FirmwareVersion fwVersion;
    c_SparkMax_GetFirmwareVersion(ConvertToMotorControllerWrapper(handle), &fwVersion);

    return (jint)fwVersion.versionRaw;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1GetDeviceId
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1GetDeviceId
  (JNIEnv*, jclass, jlong handle)
{
    int deviceId;
    c_SparkMax_GetDeviceId(ConvertToMotorControllerWrapper(handle), &deviceId);
    return (jint)deviceId;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1SetMotorType
 * Signature: (JI)I
 */
JNIEXPORT jint JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1SetMotorType
  (JNIEnv*, jclass, jlong handle, jint type)
{
    c_SparkMax_ErrorCode output = c_SparkMax_SetMotorType(ConvertToMotorControllerWrapper(handle), (c_SparkMax_MotorType)type);
    return (jint)output;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1GetMotorType
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1GetMotorType
  (JNIEnv*, jclass, jlong handle)
{
    c_SparkMax_MotorType type;
    c_SparkMax_GetMotorType(ConvertToMotorControllerWrapper(handle), &type);
    return (jint)type;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1SetPeriodicFramePeriod
 * Signature: (JII)I
 */
JNIEXPORT jint JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1SetPeriodicFramePeriod
  (JNIEnv*, jclass, jlong handle, jint frameId, jint periodMs)
{
    c_SparkMax_ErrorCode output = c_SparkMax_SetPeriodicFramePeriod(ConvertToMotorControllerWrapper(handle), (c_SparkMax_PeriodicFrame)frameId, periodMs);
    return (jint)output;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1SetControlFramePeriod
 * Signature: (JI)V
 */
JNIEXPORT void JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1SetControlFramePeriod
  (JNIEnv*, jclass, jlong handle, jint periodMs)
{
    c_SparkMax_SetControlFramePeriod(ConvertToMotorControllerWrapper(handle), periodMs);
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1GetControlFramePeriod
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1GetControlFramePeriod
  (JNIEnv*, jclass, jlong handle)
{
    return c_SparkMax_GetControlFramePeriod(ConvertToMotorControllerWrapper(handle));
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1SetEncoderPosition
 * Signature: (JF)I
 */
JNIEXPORT jint JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1SetEncoderPosition
  (JNIEnv*, jclass, jlong handle, jfloat position)
{
    c_SparkMax_ErrorCode output = c_SparkMax_SetEncoderPosition(ConvertToMotorControllerWrapper(handle), position);
    return (jint)output;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1RestoreFactoryDefaults
 * Signature: (JZ)I
 */
JNIEXPORT jint JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1RestoreFactoryDefaults
  (JNIEnv*, jclass, jlong handle, jboolean persist)
{
    c_SparkMax_ErrorCode output = c_SparkMax_RestoreFactoryDefaults(ConvertToMotorControllerWrapper(handle), persist);
    return (jint)output;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1SetFollow
 * Signature: (JII)I
 */
JNIEXPORT jint JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1SetFollow
  (JNIEnv*, jclass, jlong handle, jint followerArbId, jint followerCfg)
{
    c_SparkMax_ErrorCode output = c_SparkMax_SetFollow(ConvertToMotorControllerWrapper(handle), followerArbId, followerCfg);
    return (jint)output;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1SafeFloat
 * Signature: (F)F
 */
JNIEXPORT jfloat JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1SafeFloat
  (JNIEnv*, jclass, jfloat f)
{
    return (jfloat)c_SparkMax_SafeFloat(f);
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1EnableExternalControl
 * Signature: (Z)V
 */
JNIEXPORT void JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1EnableExternalControl
  (JNIEnv*, jclass, jboolean)
{
    LOG_UNSUPPORTED_CAN_FUNC("");
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1SetEnable
 * Signature: (Z)V
 */
JNIEXPORT void JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1SetEnable
  (JNIEnv*, jclass, jboolean)
{
    LOG_UNSUPPORTED_CAN_FUNC("");
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1SetpointCommand
 * Signature: (JFIIFI)I
 */
JNIEXPORT jint JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1SetpointCommand
  (JNIEnv*, jclass, jlong handle, jfloat value, jint ctrl, jint pidSlot,
   jfloat arbFeedforward, jint arbFFUnits)
{
    c_SparkMax_ErrorCode output = c_SparkMax_SetpointCommand(ConvertToMotorControllerWrapper(handle), value, (c_SparkMax_ControlType)ctrl, pidSlot, arbFeedforward, arbFFUnits);
    return (jint)output;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1SetInverted
 * Signature: (JZ)I
 */
JNIEXPORT jint JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1SetInverted
  (JNIEnv*, jclass, jlong handle, jboolean inverted)
{
    c_SparkMax_ErrorCode output = c_SparkMax_SetInverted(ConvertToMotorControllerWrapper(handle), inverted);
    return (jint)output;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1GetInverted
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1GetInverted
  (JNIEnv*, jclass, jlong handle)
{
    uint8_t inverted;
    c_SparkMax_GetInverted(ConvertToMotorControllerWrapper(handle), &inverted);
    return (jboolean)inverted;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1SetSmartCurrentLimit
 * Signature: (JIII)I
 */
JNIEXPORT jint JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1SetSmartCurrentLimit
  (JNIEnv*, jclass, jlong handle, jint stallLimit, jint freeLimit,
   jint limitRPM)
{
    c_SparkMax_ErrorCode output = c_SparkMax_SetSmartCurrentLimit(ConvertToMotorControllerWrapper(handle), stallLimit, freeLimit, limitRPM);
    return (jint)output;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1GetSmartCurrentStallLimit
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1GetSmartCurrentStallLimit
  (JNIEnv*, jclass, jlong)
{
    LOG_UNSUPPORTED_CAN_FUNC("");
    return 0;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1GetSmartCurrentFreeLimit
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1GetSmartCurrentFreeLimit
  (JNIEnv*, jclass, jlong)
{
    LOG_UNSUPPORTED_CAN_FUNC("");
    return 0;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1GetSmartCurrentLimitRPM
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1GetSmartCurrentLimitRPM
  (JNIEnv*, jclass, jlong)
{
    LOG_UNSUPPORTED_CAN_FUNC("");
    return 0;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1SetSecondaryCurrentLimit
 * Signature: (JFI)I
 */
JNIEXPORT jint JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1SetSecondaryCurrentLimit
  (JNIEnv*, jclass, jlong handle, jfloat limit, jint chopCycles)
{
    c_SparkMax_ErrorCode output = c_SparkMax_SetSecondaryCurrentLimit(ConvertToMotorControllerWrapper(handle), limit, chopCycles);
    return (jint)output;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1GetSecondaryCurrentLimit
 * Signature: (J)F
 */
JNIEXPORT jfloat JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1GetSecondaryCurrentLimit
  (JNIEnv*, jclass, jlong handle)
{
    float limit;
    int chopCycles;
    c_SparkMax_GetSecondaryCurrentLimit(ConvertToMotorControllerWrapper(handle), &limit, &chopCycles);
    return (jfloat)limit;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1GetSecondaryCurrentLimitCycles
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1GetSecondaryCurrentLimitCycles
  (JNIEnv*, jclass, jlong)
{
    LOG_UNSUPPORTED_CAN_FUNC("");
    return 0;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1SetIdleMode
 * Signature: (JI)I
 */
JNIEXPORT jint JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1SetIdleMode
  (JNIEnv*, jclass, jlong handle, jint idlemode)
{
    c_SparkMax_ErrorCode output = c_SparkMax_SetIdleMode(ConvertToMotorControllerWrapper(handle), (c_SparkMax_IdleMode)idlemode);
    return (jint)output;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1GetIdleMode
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1GetIdleMode
  (JNIEnv*, jclass, jlong handle)
{
    c_SparkMax_IdleMode idlemode;
    c_SparkMax_GetIdleMode(ConvertToMotorControllerWrapper(handle), &idlemode);
    return (jint)idlemode;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1EnableVoltageCompensation
 * Signature: (JF)I
 */
JNIEXPORT jint JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1EnableVoltageCompensation
  (JNIEnv*, jclass, jlong handle, jfloat nominalVoltage)
{
    c_SparkMax_ErrorCode output = c_SparkMax_EnableVoltageCompensation(ConvertToMotorControllerWrapper(handle), nominalVoltage);
    return (jint)output;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1GetVoltageCompensationNominalVoltage
 * Signature: (J)F
 */
JNIEXPORT jfloat JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1GetVoltageCompensationNominalVoltage
  (JNIEnv*, jclass, jlong handle)
{
    float nominalVoltage;
    c_SparkMax_GetVoltageCompensationNominalVoltage(ConvertToMotorControllerWrapper(handle), &nominalVoltage);
    return (jfloat)nominalVoltage;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1DisableVoltageCompensation
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1DisableVoltageCompensation
  (JNIEnv*, jclass, jlong handle)
{
    c_SparkMax_ErrorCode output = c_SparkMax_DisableVoltageCompensation(ConvertToMotorControllerWrapper(handle));
    return (jint)output;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1SetOpenLoopRampRate
 * Signature: (JF)I
 */
JNIEXPORT jint JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1SetOpenLoopRampRate
  (JNIEnv*, jclass, jlong handle, jfloat rate)
{
    c_SparkMax_ErrorCode output = c_SparkMax_SetOpenLoopRampRate(ConvertToMotorControllerWrapper(handle), rate);
    return (jint)output;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1GetOpenLoopRampRate
 * Signature: (J)F
 */
JNIEXPORT jfloat JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1GetOpenLoopRampRate
  (JNIEnv*, jclass, jlong handle)
{
    float rate;
    c_SparkMax_GetOpenLoopRampRate(ConvertToMotorControllerWrapper(handle), &rate);
    return (jfloat)rate;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1SetClosedLoopRampRate
 * Signature: (JF)I
 */
JNIEXPORT jint JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1SetClosedLoopRampRate
  (JNIEnv*, jclass, jlong handle, jfloat rate)
{
    c_SparkMax_ErrorCode output = c_SparkMax_SetClosedLoopRampRate(ConvertToMotorControllerWrapper(handle), rate);
    return (jint)output;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1GetClosedLoopRampRate
 * Signature: (J)F
 */
JNIEXPORT jfloat JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1GetClosedLoopRampRate
  (JNIEnv*, jclass, jlong handle)
{
    float rate;
    c_SparkMax_GetClosedLoopRampRate(ConvertToMotorControllerWrapper(handle), &rate);
    return (jfloat)rate;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1IsFollower
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1IsFollower
  (JNIEnv*, jclass, jlong handle)
{
    uint8_t isFollower;
    c_SparkMax_IsFollower(ConvertToMotorControllerWrapper(handle), &isFollower);
    return (jboolean)isFollower;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1GetFaults
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1GetFaults
  (JNIEnv*, jclass, jlong handle)
{
    uint16_t faults;
    c_SparkMax_GetFaults(ConvertToMotorControllerWrapper(handle), &faults);
    return (jint)faults;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1GetStickyFaults
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1GetStickyFaults
  (JNIEnv*, jclass, jlong handle)
{
    uint16_t stickyFaults;
    c_SparkMax_GetStickyFaults(ConvertToMotorControllerWrapper(handle), &stickyFaults);
    return (jint)stickyFaults;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1GetFault
 * Signature: (JI)Z
 */
JNIEXPORT jboolean JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1GetFault
  (JNIEnv*, jclass, jlong handle, jint faultId)
{
    uint8_t fault;
    c_SparkMax_GetFault(ConvertToMotorControllerWrapper(handle), (c_SparkMax_FaultID)faultId, &fault);
    return (jboolean)fault;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1GetStickyFault
 * Signature: (JI)Z
 */
JNIEXPORT jboolean JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1GetStickyFault
  (JNIEnv*, jclass, jlong handle, jint faultId)
{
    uint8_t stickyfault;
    c_SparkMax_GetStickyFault(ConvertToMotorControllerWrapper(handle), (c_SparkMax_FaultID)faultId, &stickyfault);
    return (jboolean)stickyfault;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1GetBusVoltage
 * Signature: (J)F
 */
JNIEXPORT jfloat JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1GetBusVoltage
  (JNIEnv*, jclass, jlong handle)
{
    float busVoltage;
    c_SparkMax_GetBusVoltage(ConvertToMotorControllerWrapper(handle), &busVoltage);
    return (jfloat)busVoltage;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1GetAppliedOutput
 * Signature: (J)F
 */
JNIEXPORT jfloat JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1GetAppliedOutput
  (JNIEnv*, jclass, jlong handle)
{
    float appliedOutput;
    c_SparkMax_GetAppliedOutput(ConvertToMotorControllerWrapper(handle), &appliedOutput);
    return (jfloat)appliedOutput;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1GetOutputCurrent
 * Signature: (J)F
 */
JNIEXPORT jfloat JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1GetOutputCurrent
  (JNIEnv*, jclass, jlong handle)
{
    float outputCurrent;
    c_SparkMax_GetOutputCurrent(ConvertToMotorControllerWrapper(handle), &outputCurrent);
    return (jfloat)outputCurrent;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1GetMotorTemperature
 * Signature: (J)F
 */
JNIEXPORT jfloat JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1GetMotorTemperature
  (JNIEnv*, jclass, jlong handle)
{
    float motorTemperature;
    c_SparkMax_GetMotorTemperature(ConvertToMotorControllerWrapper(handle), &motorTemperature);
    return (jfloat)motorTemperature;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1ClearFaults
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1ClearFaults
  (JNIEnv*, jclass, jlong handle)
{
    c_SparkMax_ErrorCode output = c_SparkMax_ClearFaults(ConvertToMotorControllerWrapper(handle));
    return (jint)output;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1BurnFlash
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1BurnFlash
  (JNIEnv*, jclass, jlong handle)
{
    c_SparkMax_ErrorCode output = c_SparkMax_BurnFlash(ConvertToMotorControllerWrapper(handle));
    return (jint)output;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1SetCANTimeout
 * Signature: (JI)I
 */
JNIEXPORT jint JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1SetCANTimeout
  (JNIEnv*, jclass, jlong handle, jint timeoutMs)
{
    c_SparkMax_ErrorCode output = c_SparkMax_SetCANTimeout(ConvertToMotorControllerWrapper(handle), timeoutMs);
    return (jint)output;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1EnableSoftLimit
 * Signature: (JIZ)I
 */
JNIEXPORT jint JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1EnableSoftLimit
  (JNIEnv*, jclass, jlong handle, jint dir, jboolean enable)
{
    c_SparkMax_ErrorCode output = c_SparkMax_EnableSoftLimit(ConvertToMotorControllerWrapper(handle), (c_SparkMax_LimitDirection)dir, enable);
    return (jint)output;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1IsSoftLimitEnabled
 * Signature: (JI)Z
 */
JNIEXPORT jboolean JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1IsSoftLimitEnabled
  (JNIEnv*, jclass, jlong handle, jint dir)
{
    uint8_t enabled;
    c_SparkMax_IsSoftLimitEnabled(ConvertToMotorControllerWrapper(handle), (c_SparkMax_LimitDirection)dir, &enabled);
    return (jboolean)enabled;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1SetSoftLimit
 * Signature: (JIF)I
 */
JNIEXPORT jint JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1SetSoftLimit
  (JNIEnv*, jclass, jlong handle, jint dir, jfloat limit)
{
    c_SparkMax_ErrorCode output = c_SparkMax_SetSoftLimit(ConvertToMotorControllerWrapper(handle), (c_SparkMax_LimitDirection)dir, limit);
    return (jint)output;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1GetSoftLimit
 * Signature: (JI)F
 */
JNIEXPORT jfloat JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1GetSoftLimit
  (JNIEnv*, jclass, jlong handle, jint dir)
{
    float limit;
    c_SparkMax_GetSoftLimit(ConvertToMotorControllerWrapper(handle), (c_SparkMax_LimitDirection)dir, &limit);
    return (jfloat)limit;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1SetSensorType
 * Signature: (JI)I
 */
JNIEXPORT jint JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1SetSensorType
  (JNIEnv*, jclass, jlong handle, jint sensorType)
{
    c_SparkMax_ErrorCode output = c_SparkMax_SetSensorType(ConvertToMotorControllerWrapper(handle), (c_SparkMax_EncoderType)sensorType);
    return (jint)output;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1SetLimitPolarity
 * Signature: (JII)I
 */
JNIEXPORT jint JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1SetLimitPolarity
  (JNIEnv*, jclass, jlong handle, jint sw, jint polarity)
{
    c_SparkMax_ErrorCode output = c_SparkMax_SetLimitPolarity(ConvertToMotorControllerWrapper(handle), (c_SparkMax_LimitDirection)sw, (c_SparkMax_LimitPolarity)polarity);
    return (jint)output;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1GetLimitPolarity
 * Signature: (JI)I
 */
JNIEXPORT jint JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1GetLimitPolarity
  (JNIEnv*, jclass, jlong handle, jint sw)
{
    c_SparkMax_LimitPolarity polarity;
    c_SparkMax_GetLimitPolarity(ConvertToMotorControllerWrapper(handle), (c_SparkMax_LimitDirection)sw, &polarity);
    return (jint)polarity;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1GetLimitSwitch
 * Signature: (JI)Z
 */
JNIEXPORT jboolean JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1GetLimitSwitch
  (JNIEnv*, jclass, jlong handle, jint sw)
{
    uint8_t limit;
    c_SparkMax_GetLimitSwitch(ConvertToMotorControllerWrapper(handle), (c_SparkMax_LimitDirection)sw, &limit);
    return (jboolean)limit;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1EnableLimitSwitch
 * Signature: (JIZ)I
 */
JNIEXPORT jint JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1EnableLimitSwitch
  (JNIEnv*, jclass, jlong handle, jint sw, jboolean enable)
{
    c_SparkMax_ErrorCode output = c_SparkMax_EnableLimitSwitch(ConvertToMotorControllerWrapper(handle), (c_SparkMax_LimitDirection)sw, enable);
    return (jint)output;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1IsLimitEnabled
 * Signature: (JI)Z
 */
JNIEXPORT jboolean JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1IsLimitEnabled
  (JNIEnv*, jclass, jlong handle, jint sw)
{
    uint8_t enabled;
    c_SparkMax_IsLimitEnabled(ConvertToMotorControllerWrapper(handle), (c_SparkMax_LimitDirection)sw, &enabled);
    return (jboolean)enabled;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1GetAnalogPosition
 * Signature: (J)F
 */
JNIEXPORT jfloat JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1GetAnalogPosition
  (JNIEnv*, jclass, jlong handle)
{
    float position;
    c_SparkMax_GetAnalogPosition(ConvertToMotorControllerWrapper(handle), &position);
    return (jfloat)position;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1GetAnalogVelocity
 * Signature: (J)F
 */
JNIEXPORT jfloat JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1GetAnalogVelocity
  (JNIEnv*, jclass, jlong handle)
{
    float velocity;
    c_SparkMax_GetAnalogVelocity(ConvertToMotorControllerWrapper(handle), &velocity);
    return (jfloat)velocity;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1GetAnalogVoltage
 * Signature: (J)F
 */
JNIEXPORT jfloat JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1GetAnalogVoltage
  (JNIEnv*, jclass, jlong handle)
{
    float voltage;
    c_SparkMax_GetAnalogVoltage(ConvertToMotorControllerWrapper(handle), &voltage);
    return (jfloat)voltage;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1SetAnalogPositionConversionFactor
 * Signature: (JF)I
 */
JNIEXPORT jint JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1SetAnalogPositionConversionFactor
  (JNIEnv*, jclass, jlong handle, jfloat conversion)
{
    c_SparkMax_ErrorCode output = c_SparkMax_SetAnalogPositionConversionFactor(ConvertToMotorControllerWrapper(handle), conversion);
    return (jint)output;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1SetAnalogVelocityConversionFactor
 * Signature: (JF)I
 */
JNIEXPORT jint JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1SetAnalogVelocityConversionFactor
  (JNIEnv*, jclass, jlong handle, jfloat conversion)
{
    c_SparkMax_ErrorCode output = c_SparkMax_SetAnalogVelocityConversionFactor(ConvertToMotorControllerWrapper(handle), conversion);
    return (jint)output;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1GetAnalogPositionConversionFactor
 * Signature: (J)F
 */
JNIEXPORT jfloat JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1GetAnalogPositionConversionFactor
  (JNIEnv*, jclass, jlong handle)
{
    float conversion;
    c_SparkMax_GetAnalogPositionConversionFactor(ConvertToMotorControllerWrapper(handle), &conversion);
    return (jfloat)conversion;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1GetAnalogVelocityConversionFactor
 * Signature: (J)F
 */
JNIEXPORT jfloat JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1GetAnalogVelocityConversionFactor
  (JNIEnv*, jclass, jlong handle)
{
    float conversion;
    c_SparkMax_GetAnalogVelocityConversionFactor(ConvertToMotorControllerWrapper(handle), &conversion);
    return (jfloat)conversion;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1SetAnalogInverted
 * Signature: (JZ)I
 */
JNIEXPORT jint JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1SetAnalogInverted
  (JNIEnv*, jclass, jlong handle, jboolean inverted)
{
    c_SparkMax_ErrorCode output = c_SparkMax_SetAnalogInverted(ConvertToMotorControllerWrapper(handle), inverted);
    return (jint)output;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1GetAnalogInverted
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1GetAnalogInverted
  (JNIEnv*, jclass, jlong handle)
{
    uint8_t inverted;
    c_SparkMax_GetAnalogInverted(ConvertToMotorControllerWrapper(handle), &inverted);
    return (jboolean)inverted;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1SetAnalogAverageDepth
 * Signature: (JI)I
 */
JNIEXPORT jint JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1SetAnalogAverageDepth
  (JNIEnv*, jclass, jlong handle, jint depth)
{
    c_SparkMax_ErrorCode output = c_SparkMax_SetAnalogAverageDepth(ConvertToMotorControllerWrapper(handle), depth);
    return (jint)output;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1GetAnalogAverageDepth
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1GetAnalogAverageDepth
  (JNIEnv*, jclass, jlong handle)
{
    uint32_t depth;
    c_SparkMax_GetAnalogAverageDepth(ConvertToMotorControllerWrapper(handle), &depth);
    return (jint)depth;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1SetAnalogMeasurementPeriod
 * Signature: (JI)I
 */
JNIEXPORT jint JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1SetAnalogMeasurementPeriod
  (JNIEnv*, jclass, jlong handle, jint samples)
{
    c_SparkMax_ErrorCode output = c_SparkMax_SetAnalogMeasurementPeriod(ConvertToMotorControllerWrapper(handle), samples);
    return (jint)output;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1GetAnalogMeasurementPeriod
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1GetAnalogMeasurementPeriod
  (JNIEnv*, jclass, jlong handle)
{
    uint32_t samples;
    c_SparkMax_GetAnalogMeasurementPeriod(ConvertToMotorControllerWrapper(handle), &samples);
    return (jint)samples;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1SetAnalogMode
 * Signature: (JI)I
 */
JNIEXPORT jint JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1SetAnalogMode
  (JNIEnv*, jclass, jlong handle, jint mode)
{
    c_SparkMax_ErrorCode output = c_SparkMax_SetAnalogMode(ConvertToMotorControllerWrapper(handle), (c_SparkMax_AnalogMode)mode);
    return (jint)output;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1GetAnalogMode
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1GetAnalogMode
  (JNIEnv*, jclass, jlong handle)
{
    c_SparkMax_AnalogMode mode;
    c_SparkMax_GetAnalogMode(ConvertToMotorControllerWrapper(handle), &mode);
    return (jint)mode;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1GetEncoderPosition
 * Signature: (J)F
 */
JNIEXPORT jfloat JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1GetEncoderPosition
  (JNIEnv*, jclass, jlong handle)
{
    float position;
    c_SparkMax_GetEncoderPosition(ConvertToMotorControllerWrapper(handle), &position);
    return (jfloat)position;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1GetEncoderVelocity
 * Signature: (J)F
 */
JNIEXPORT jfloat JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1GetEncoderVelocity
  (JNIEnv*, jclass, jlong handle)
{
    float velocity;
    c_SparkMax_GetEncoderVelocity(ConvertToMotorControllerWrapper(handle), &velocity);
    return (jfloat)velocity;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1SetPositionConversionFactor
 * Signature: (JF)I
 */
JNIEXPORT jint JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1SetPositionConversionFactor
  (JNIEnv*, jclass, jlong handle, jfloat conversion)
{
    c_SparkMax_ErrorCode output = c_SparkMax_SetPositionConversionFactor(ConvertToMotorControllerWrapper(handle), conversion);
    return (jint)output;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1SetVelocityConversionFactor
 * Signature: (JF)I
 */
JNIEXPORT jint JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1SetVelocityConversionFactor
  (JNIEnv*, jclass, jlong handle, jfloat conversion)
{
    c_SparkMax_ErrorCode output = c_SparkMax_SetVelocityConversionFactor(ConvertToMotorControllerWrapper(handle), conversion);
    return (jint)output;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1GetPositionConversionFactor
 * Signature: (J)F
 */
JNIEXPORT jfloat JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1GetPositionConversionFactor
  (JNIEnv*, jclass, jlong handle)
{
    float conversion;
    c_SparkMax_GetPositionConversionFactor(ConvertToMotorControllerWrapper(handle), &conversion);
    return (jfloat)conversion;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1GetVelocityConversionFactor
 * Signature: (J)F
 */
JNIEXPORT jfloat JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1GetVelocityConversionFactor
  (JNIEnv*, jclass, jlong handle)
{
    float conversion;
    c_SparkMax_GetVelocityConversionFactor(ConvertToMotorControllerWrapper(handle), &conversion);
    return (jfloat)conversion;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1SetAverageDepth
 * Signature: (JI)I
 */
JNIEXPORT jint JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1SetAverageDepth
  (JNIEnv*, jclass, jlong handle, jint depth)
{
    c_SparkMax_ErrorCode output = c_SparkMax_SetAverageDepth(ConvertToMotorControllerWrapper(handle), depth);
    return (jint)output;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1GetAverageDepth
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1GetAverageDepth
  (JNIEnv*, jclass, jlong handle)
{
    uint32_t depth;
    c_SparkMax_GetAverageDepth(ConvertToMotorControllerWrapper(handle), &depth);
    return (jint)depth;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1SetMeasurementPeriod
 * Signature: (JI)I
 */
JNIEXPORT jint JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1SetMeasurementPeriod
  (JNIEnv*, jclass, jlong handle, jint samples)
{
    c_SparkMax_ErrorCode output = c_SparkMax_SetMeasurementPeriod(ConvertToMotorControllerWrapper(handle), samples);
    return (jint)output;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1GetMeasurementPeriod
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1GetMeasurementPeriod
  (JNIEnv*, jclass, jlong handle)
{
    uint32_t samples;
    c_SparkMax_GetMeasurementPeriod(ConvertToMotorControllerWrapper(handle), &samples);
    return (jint)samples;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1SetCountsPerRevolution
 * Signature: (JI)I
 */
JNIEXPORT jint JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1SetCountsPerRevolution
  (JNIEnv*, jclass, jlong handle, jint cpr)
{
    c_SparkMax_ErrorCode output = c_SparkMax_SetCountsPerRevolution(ConvertToMotorControllerWrapper(handle), cpr);
    return (jint)output;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1GetCountsPerRevolution
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1GetCountsPerRevolution
  (JNIEnv*, jclass, jlong handle)
{
    uint32_t cpr;
    c_SparkMax_GetCountsPerRevolution(ConvertToMotorControllerWrapper(handle), &cpr);
    return (jint)cpr;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1SetEncoderInverted
 * Signature: (JZ)I
 */
JNIEXPORT jint JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1SetEncoderInverted
  (JNIEnv*, jclass, jlong handle, jboolean inverted)
{
    c_SparkMax_ErrorCode output = c_SparkMax_SetEncoderInverted(ConvertToMotorControllerWrapper(handle), inverted);
    return (jint)output;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1GetEncoderInverted
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1GetEncoderInverted
  (JNIEnv*, jclass, jlong handle)
{
    uint8_t inverted;
    c_SparkMax_GetEncoderInverted(ConvertToMotorControllerWrapper(handle), &inverted);
    return (jboolean)inverted;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1SetAltEncoderPosition
 * Signature: (JF)I
 */
JNIEXPORT jint JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1SetAltEncoderPosition
  (JNIEnv*, jclass, jlong handle, jfloat position)
{
    c_SparkMax_ErrorCode output = c_SparkMax_SetAltEncoderPosition(ConvertToMotorControllerWrapper(handle), position);
    return (jint)output;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1GetAltEncoderPosition
 * Signature: (J)F
 */
JNIEXPORT jfloat JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1GetAltEncoderPosition
  (JNIEnv*, jclass, jlong handle)
{
    float position;
    c_SparkMax_GetAltEncoderPosition(ConvertToMotorControllerWrapper(handle), &position);
    return (jfloat)position;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1GetAltEncoderVelocity
 * Signature: (J)F
 */
JNIEXPORT jfloat JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1GetAltEncoderVelocity
  (JNIEnv*, jclass, jlong handle)
{
    float velocity;
    c_SparkMax_GetAltEncoderVelocity(ConvertToMotorControllerWrapper(handle), &velocity);
    return (jfloat)velocity;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1SetAltEncoderPositionFactor
 * Signature: (JF)I
 */
JNIEXPORT jint JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1SetAltEncoderPositionFactor
  (JNIEnv*, jclass, jlong handle, jfloat conversion)
{
    c_SparkMax_ErrorCode output = c_SparkMax_SetAltEncoderPositionFactor(ConvertToMotorControllerWrapper(handle), conversion);
    return (jint)output;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1SetAltEncoderVelocityFactor
 * Signature: (JF)I
 */
JNIEXPORT jint JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1SetAltEncoderVelocityFactor
  (JNIEnv*, jclass, jlong handle, jfloat conversion)
{
    c_SparkMax_ErrorCode output = c_SparkMax_SetAltEncoderVelocityFactor(ConvertToMotorControllerWrapper(handle), conversion);
    return (jint)output;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1GetAltEncoderPositionFactor
 * Signature: (J)F
 */
JNIEXPORT jfloat JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1GetAltEncoderPositionFactor
  (JNIEnv*, jclass, jlong handle)
{
    float conversion;
    c_SparkMax_GetAltEncoderPositionFactor(ConvertToMotorControllerWrapper(handle), &conversion);
    return (jfloat)conversion;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1GetAltEncoderVelocityFactor
 * Signature: (J)F
 */
JNIEXPORT jfloat JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1GetAltEncoderVelocityFactor
  (JNIEnv*, jclass, jlong handle)
{
    float conversion;
    c_SparkMax_GetAltEncoderVelocityFactor(ConvertToMotorControllerWrapper(handle), &conversion);
    return (jfloat)conversion;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1SetAltEncoderAverageDepth
 * Signature: (JI)I
 */
JNIEXPORT jint JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1SetAltEncoderAverageDepth
  (JNIEnv*, jclass, jlong handle, jint depth)
{
    c_SparkMax_ErrorCode output = c_SparkMax_SetAltEncoderAverageDepth(ConvertToMotorControllerWrapper(handle), depth);
    return (jint)output;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1GetAltEncoderAverageDepth
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1GetAltEncoderAverageDepth
  (JNIEnv*, jclass, jlong handle)
{
    uint32_t depth;
    c_SparkMax_GetAltEncoderAverageDepth(ConvertToMotorControllerWrapper(handle), &depth);
    return (jint)depth;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1SetAltEncoderMeasurementPeriod
 * Signature: (JI)I
 */
JNIEXPORT jint JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1SetAltEncoderMeasurementPeriod
  (JNIEnv*, jclass, jlong handle, jint samples)
{
    c_SparkMax_ErrorCode output = c_SparkMax_SetAltEncoderMeasurementPeriod(ConvertToMotorControllerWrapper(handle), samples);
    return (jint)output;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1GetAltEncoderMeasurementPeriod
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1GetAltEncoderMeasurementPeriod
  (JNIEnv*, jclass, jlong handle)
{
    uint32_t samples;
    c_SparkMax_GetAltEncoderMeasurementPeriod(ConvertToMotorControllerWrapper(handle), &samples);
    return (jint)samples;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1SetAltEncoderCountsPerRevolution
 * Signature: (JI)I
 */
JNIEXPORT jint JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1SetAltEncoderCountsPerRevolution
  (JNIEnv*, jclass, jlong handle, jint cpr)
{
    c_SparkMax_ErrorCode output = c_SparkMax_SetAltEncoderCountsPerRevolution(ConvertToMotorControllerWrapper(handle), cpr);
    return (jint)output;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1GetAltEncoderCountsPerRevolution
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1GetAltEncoderCountsPerRevolution
  (JNIEnv*, jclass, jlong handle)
{
    uint32_t cpr;
    c_SparkMax_GetAltEncoderCountsPerRevolution(ConvertToMotorControllerWrapper(handle), &cpr);
    return (jint)cpr;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1SetAltEncoderInverted
 * Signature: (JZ)I
 */
JNIEXPORT jint JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1SetAltEncoderInverted
  (JNIEnv*, jclass, jlong handle, jboolean inverted)
{
    c_SparkMax_ErrorCode output = c_SparkMax_SetAltEncoderInverted(ConvertToMotorControllerWrapper(handle), inverted);
    return (jint)output;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1GetAltEncoderInverted
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1GetAltEncoderInverted
  (JNIEnv*, jclass, jlong handle)
{
    uint8_t inverted;
    c_SparkMax_GetAltEncoderInverted(ConvertToMotorControllerWrapper(handle), &inverted);
    return (jboolean)inverted;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1SetDataPortConfig
 * Signature: (JI)I
 */
JNIEXPORT jint JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1SetDataPortConfig
  (JNIEnv*, jclass, jlong handle, jint config)
{
    c_SparkMax_ErrorCode output = c_SparkMax_SetDataPortConfig(ConvertToMotorControllerWrapper(handle), (c_SparkMax_DataPortConfig)config);
    return (jint)output;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1SetP
 * Signature: (JIF)I
 */
JNIEXPORT jint JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1SetP
  (JNIEnv*, jclass, jlong handle, jint slotID, jfloat gain)
{
    c_SparkMax_ErrorCode output = c_SparkMax_SetP(ConvertToMotorControllerWrapper(handle), slotID, gain);
    return (jint)output;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1SetI
 * Signature: (JIF)I
 */
JNIEXPORT jint JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1SetI
  (JNIEnv*, jclass, jlong handle, jint slotID, jfloat gain)
{
    c_SparkMax_ErrorCode output = c_SparkMax_SetI(ConvertToMotorControllerWrapper(handle), slotID, gain);
    return (jint)output;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1SetD
 * Signature: (JIF)I
 */
JNIEXPORT jint JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1SetD
  (JNIEnv*, jclass, jlong handle, jint slotID, jfloat gain)
{
    c_SparkMax_ErrorCode output = c_SparkMax_SetD(ConvertToMotorControllerWrapper(handle), slotID, gain);
    return (jint)output;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1SetDFilter
 * Signature: (JIF)I
 */
JNIEXPORT jint JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1SetDFilter
  (JNIEnv*, jclass, jlong handle, jint slotID, jfloat gain)
{
    c_SparkMax_ErrorCode output = c_SparkMax_SetDFilter(ConvertToMotorControllerWrapper(handle), slotID, gain);
    return (jint)output;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1SetFF
 * Signature: (JIF)I
 */
JNIEXPORT jint JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1SetFF
  (JNIEnv*, jclass, jlong handle, jint slotID, jfloat gain)
{
    c_SparkMax_ErrorCode output = c_SparkMax_SetFF(ConvertToMotorControllerWrapper(handle), slotID, gain);
    return (jint)output;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1SetIZone
 * Signature: (JIF)I
 */
JNIEXPORT jint JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1SetIZone
  (JNIEnv*, jclass, jlong handle, jint slotID, jfloat IZone)
{
    c_SparkMax_ErrorCode output = c_SparkMax_SetIZone(ConvertToMotorControllerWrapper(handle), slotID, IZone);
    return (jint)output;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1SetOutputRange
 * Signature: (JIFF)I
 */
JNIEXPORT jint JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1SetOutputRange
  (JNIEnv*, jclass, jlong handle, jint slotID, jfloat min, jfloat max)
{
    c_SparkMax_ErrorCode output = c_SparkMax_SetOutputRange(ConvertToMotorControllerWrapper(handle), slotID, min, max);
    return (jint)output;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1GetP
 * Signature: (JI)F
 */
JNIEXPORT jfloat JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1GetP
  (JNIEnv*, jclass, jlong handle, jint slotID)
{
    float gain;
    c_SparkMax_GetP(ConvertToMotorControllerWrapper(handle), slotID, &gain);
    return (jfloat)gain;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1GetI
 * Signature: (JI)F
 */
JNIEXPORT jfloat JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1GetI
  (JNIEnv*, jclass, jlong handle, jint slotID)
{
    float gain;
    c_SparkMax_GetI(ConvertToMotorControllerWrapper(handle), slotID, &gain);
    return (jfloat)gain;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1GetD
 * Signature: (JI)F
 */
JNIEXPORT jfloat JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1GetD
  (JNIEnv*, jclass, jlong handle, jint slotID)
{
    float gain;
    c_SparkMax_GetD(ConvertToMotorControllerWrapper(handle), slotID, &gain);
    return (jfloat)gain;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1GetDFilter
 * Signature: (JI)F
 */
JNIEXPORT jfloat JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1GetDFilter
  (JNIEnv*, jclass, jlong handle, jint slotID)
{
    float gain;
    c_SparkMax_GetDFilter(ConvertToMotorControllerWrapper(handle), slotID, &gain);
    return (jfloat)gain;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1GetFF
 * Signature: (JI)F
 */
JNIEXPORT jfloat JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1GetFF
  (JNIEnv*, jclass, jlong handle, jint slotID)
{
    float gain;
    c_SparkMax_GetFF(ConvertToMotorControllerWrapper(handle), slotID, &gain);
    return (jfloat)gain;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1GetIZone
 * Signature: (JI)F
 */
JNIEXPORT jfloat JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1GetIZone
  (JNIEnv*, jclass, jlong handle, jint slotID)
{
    float IZone;
    c_SparkMax_GetIZone(ConvertToMotorControllerWrapper(handle), slotID, &IZone);
    return (jfloat)IZone;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1GetOutputMin
 * Signature: (JI)F
 */
JNIEXPORT jfloat JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1GetOutputMin
  (JNIEnv*, jclass, jlong handle, jint slotID)
{
    float min;
    c_SparkMax_GetOutputMin(ConvertToMotorControllerWrapper(handle), slotID, &min);
    return (jfloat)min;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1GetOutputMax
 * Signature: (JI)F
 */
JNIEXPORT jfloat JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1GetOutputMax
  (JNIEnv*, jclass, jlong handle, jint slotID)
{
    float max;
    c_SparkMax_GetOutputMax(ConvertToMotorControllerWrapper(handle), slotID, &max);
    return (jfloat)max;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1SetSmartMotionMaxVelocity
 * Signature: (JIF)I
 */
JNIEXPORT jint JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1SetSmartMotionMaxVelocity
  (JNIEnv*, jclass, jlong handle, jint slotID, jfloat maxVel)
{
    c_SparkMax_ErrorCode output = c_SparkMax_SetSmartMotionMaxVelocity(ConvertToMotorControllerWrapper(handle), slotID, maxVel);
    return (jint)output;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1SetSmartMotionMaxAccel
 * Signature: (JIF)I
 */
JNIEXPORT jint JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1SetSmartMotionMaxAccel
  (JNIEnv*, jclass, jlong handle, jint slotID, jfloat maxAccel)
{
    c_SparkMax_ErrorCode output = c_SparkMax_SetSmartMotionMaxAccel(ConvertToMotorControllerWrapper(handle), slotID, maxAccel);
    return (jint)output;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1SetSmartMotionMinOutputVelocity
 * Signature: (JIF)I
 */
JNIEXPORT jint JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1SetSmartMotionMinOutputVelocity
  (JNIEnv*, jclass, jlong handle, jint slotID, jfloat minVel)
{
    c_SparkMax_ErrorCode output = c_SparkMax_SetSmartMotionMinOutputVelocity(ConvertToMotorControllerWrapper(handle), slotID, minVel);
    return (jint)output;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1SetSmartMotionAccelStrategy
 * Signature: (JII)I
 */
JNIEXPORT jint JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1SetSmartMotionAccelStrategy
  (JNIEnv*, jclass, jlong handle, jint slotID, jint accelStrategy)
{
    c_SparkMax_ErrorCode output = c_SparkMax_SetSmartMotionAccelStrategy(ConvertToMotorControllerWrapper(handle), slotID, (c_SparkMax_AccelStrategy)accelStrategy);
    return (jint)output;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1SetSmartMotionAllowedClosedLoopError
 * Signature: (JIF)I
 */
JNIEXPORT jint JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1SetSmartMotionAllowedClosedLoopError
  (JNIEnv*, jclass, jlong handle, jint slotID, jfloat allowedError)
{
    c_SparkMax_ErrorCode output = c_SparkMax_SetSmartMotionAllowedClosedLoopError(ConvertToMotorControllerWrapper(handle), slotID, allowedError);
    return (jint)output;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1GetSmartMotionMaxVelocity
 * Signature: (JI)F
 */
JNIEXPORT jfloat JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1GetSmartMotionMaxVelocity
  (JNIEnv*, jclass, jlong handle, jint slotID)
{
    float maxVel;
    c_SparkMax_GetSmartMotionMaxVelocity(ConvertToMotorControllerWrapper(handle), slotID, &maxVel);
    return (jfloat)maxVel;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1GetSmartMotionMaxAccel
 * Signature: (JI)F
 */
JNIEXPORT jfloat JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1GetSmartMotionMaxAccel
  (JNIEnv*, jclass, jlong handle, jint slotID)
{
    float maxAccel;
    c_SparkMax_GetSmartMotionMaxAccel(ConvertToMotorControllerWrapper(handle), slotID, &maxAccel);
    return (jfloat)maxAccel;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1GetSmartMotionMinOutputVelocity
 * Signature: (JI)F
 */
JNIEXPORT jfloat JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1GetSmartMotionMinOutputVelocity
  (JNIEnv*, jclass, jlong handle, jint slotID)
{
    float minVel;
    c_SparkMax_GetSmartMotionMinOutputVelocity(ConvertToMotorControllerWrapper(handle), slotID, &minVel);
    return (jfloat)minVel;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1GetSmartMotionAccelStrategy
 * Signature: (JI)I
 */
JNIEXPORT jint JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1GetSmartMotionAccelStrategy
  (JNIEnv*, jclass, jlong handle, jint slotID)
{
    c_SparkMax_AccelStrategy accelStrategy;
    c_SparkMax_GetSmartMotionAccelStrategy(ConvertToMotorControllerWrapper(handle), slotID, &accelStrategy);
    return (jint)accelStrategy;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1GetSmartMotionAllowedClosedLoopError
 * Signature: (JI)F
 */
JNIEXPORT jfloat JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1GetSmartMotionAllowedClosedLoopError
  (JNIEnv*, jclass, jlong handle, jint slotID)
{
    float allowedError;
    c_SparkMax_GetSmartMotionAllowedClosedLoopError(ConvertToMotorControllerWrapper(handle), slotID, &allowedError);
    return (jfloat)allowedError;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1SetIMaxAccum
 * Signature: (JIF)I
 */
JNIEXPORT jint JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1SetIMaxAccum
  (JNIEnv*, jclass, jlong handle, jint slotID, jfloat iMaxAccum)
{
    c_SparkMax_ErrorCode output = c_SparkMax_SetIMaxAccum(ConvertToMotorControllerWrapper(handle), slotID, iMaxAccum);
    return (jint)output;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1GetIMaxAccum
 * Signature: (JI)F
 */
JNIEXPORT jfloat JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1GetIMaxAccum
  (JNIEnv*, jclass, jlong handle, jint slotID)
{
    float iMaxAccum;
    c_SparkMax_GetIMaxAccum(ConvertToMotorControllerWrapper(handle), slotID, &iMaxAccum);
    return (jfloat)iMaxAccum;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1SetIAccum
 * Signature: (JF)I
 */
JNIEXPORT jint JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1SetIAccum
  (JNIEnv*, jclass, jlong handle, jfloat iAccum)
{
    c_SparkMax_ErrorCode output = c_SparkMax_SetIAccum(ConvertToMotorControllerWrapper(handle), iAccum);
    return (jint)output;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1GetIAccum
 * Signature: (J)F
 */
JNIEXPORT jfloat JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1GetIAccum
  (JNIEnv*, jclass, jlong handle)
{
    float iAccum;
    c_SparkMax_GetIAccum(ConvertToMotorControllerWrapper(handle), &iAccum);
    return (jfloat)iAccum;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1SetFeedbackDevice
 * Signature: (JI)I
 */
JNIEXPORT jint JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1SetFeedbackDevice
  (JNIEnv*, jclass, jlong handle, jint sensorID)
{
    c_SparkMax_ErrorCode output = c_SparkMax_SetFeedbackDevice(ConvertToMotorControllerWrapper(handle), sensorID);
    return (jint)output;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1SetFeedbackDeviceRange
 * Signature: (JFF)I
 */
JNIEXPORT jint JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1SetFeedbackDeviceRange
  (JNIEnv*, jclass, jlong handle, jfloat min, jfloat max)
{
    c_SparkMax_ErrorCode output = c_SparkMax_SetFeedbackDeviceRange(ConvertToMotorControllerWrapper(handle), min, max);
    return (jint)output;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1GetFeedbackDeviceID
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1GetFeedbackDeviceID
  (JNIEnv*, jclass, jlong handle)
{
    uint32_t id;
    c_SparkMax_GetFeedbackDeviceID(ConvertToMotorControllerWrapper(handle), &id);
    return (jint)id;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1GetAPIMajorRevision
 * Signature: ()I
 */
JNIEXPORT jint JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1GetAPIMajorRevision
  (JNIEnv*, jclass)
{
    return c_SparkMax_GetAPIVersion().Major;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1GetAPIMinorRevision
 * Signature: ()I
 */
JNIEXPORT jint JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1GetAPIMinorRevision
  (JNIEnv*, jclass)
{
    return c_SparkMax_GetAPIVersion().Minor;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1GetAPIBuildRevision
 * Signature: ()I
 */
JNIEXPORT jint JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1GetAPIBuildRevision
  (JNIEnv*, jclass)
{
    return c_SparkMax_GetAPIVersion().Build;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1GetAPIVersion
 * Signature: ()I
 */
JNIEXPORT jint JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1GetAPIVersion
  (JNIEnv*, jclass)
{
    return c_SparkMax_GetAPIVersion().Version;
}
/*
 * Class:     com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax
 * Method:    1GetLastError
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL
Java_com_revrobotics_jni_CANSparkMaxJNI_c_1SparkMax_1GetLastError
  (JNIEnv*, jclass, jlong handle)
{
    c_SparkMax_ErrorCode output = c_SparkMax_GetLastError(ConvertToMotorControllerWrapper(handle));
    return (jint)output;
}

} // extern "C"
