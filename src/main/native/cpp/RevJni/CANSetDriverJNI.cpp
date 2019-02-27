
#include <jni.h>

#include <iostream>
#include <vector>

#include "RevJni/com_revrobotics_jni_CANSetDriverJNI.h"
#include "RevSimMocks/CanSetDriverSim.h"

std::vector<SnobotSim::Rev_SendCallbackFunc> gRevCallbacks;

void SnobotSim::SetSendCallback(
        SnobotSim::Rev_SendCallbackFunc callback)
{
    gRevCallbacks.clear();
    gRevCallbacks.push_back(callback);
}

static SnobotSim::RevSimulator sRevSimulator;

SnobotSim::RevSimulator::RevSimulator()
{
}
void SnobotSim::RevSimulator::Receive(const std::string& aName, uint8_t* aBuffer, int aSize)
{
}

void SnobotSim::RevSimulator::Send(const std::string& aName, uint8_t* aBuffer, int aSize)
{
    if (!gRevCallbacks.empty())
    {
        void* param = NULL;
        int32_t unused = 0;

        gRevCallbacks[0](aName.c_str(), param, 0xFF01, aBuffer, aSize, 0, &unused);
    }
    else
    {
        LOG_UNSUPPORTED_CAN_FUNC("Callback " << aName << " not registered");
    }
}

extern "C" {

/*
 * Class:     com_revrobotics_jni_CANSetDriverJNI
 * Method:    SetDriverInit
 * Signature: ()V
 */
JNIEXPORT void JNICALL
Java_com_revrobotics_jni_CANSetDriverJNI_SetDriverInit
  (JNIEnv*, jclass)
{
    //    LOG_UNSUPPORTED_CAN_FUNC("");
}

/*
 * Class:     com_revrobotics_jni_CANSetDriverJNI
 * Method:    RunSetDriver
 * Signature: ()I
 */
JNIEXPORT jint JNICALL
Java_com_revrobotics_jni_CANSetDriverJNI_RunSetDriver
  (JNIEnv*, jclass)
{
    //    LOG_UNSUPPORTED_CAN_FUNC("");
    return 0;
}

/*
 * Class:     com_revrobotics_jni_CANSetDriverJNI
 * Method:    SetDriverSet4
 * Signature: (IFIBS)V
 */
JNIEXPORT void JNICALL
Java_com_revrobotics_jni_CANSetDriverJNI_SetDriverSet4
  (JNIEnv* env, jclass, jint deviceID, jfloat value, jint apiId, jbyte pidSlot,
   jshort arbFF)
{
    int length = 8;
    uint8_t buffer[8];
    void* paramData = NULL;

    sRevSimulator.Send("SetDriverSet4", deviceID, value, apiId, pidSlot, arbFF);
}

/*
 * Class:     com_revrobotics_jni_CANSetDriverJNI
 * Method:    SetDriverSetCtrlFramePeriodMs
 * Signature: (II)V
 */
JNIEXPORT void JNICALL
Java_com_revrobotics_jni_CANSetDriverJNI_SetDriverSetCtrlFramePeriodMs
  (JNIEnv*, jclass, jint deviceID, jint periodMs)
{
    //    LOG_UNSUPPORTED_CAN_FUNC(" " << deviceID << ", " << periodMs);
}

} // extern "C"
