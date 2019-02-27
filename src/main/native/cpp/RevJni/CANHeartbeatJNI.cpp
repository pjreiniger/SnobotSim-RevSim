
#include <jni.h>

#include "RevJni/com_revrobotics_jni_CANHeartbeatJNI.h"

extern "C" {

/*
 * Class:     com_revrobotics_jni_CANHeartbeatJNI
 * Method:    HeartbeatInit
 * Signature: ()V
 */
JNIEXPORT void JNICALL
Java_com_revrobotics_jni_CANHeartbeatJNI_HeartbeatInit
  (JNIEnv*, jclass)
{
}

/*
 * Class:     com_revrobotics_jni_CANHeartbeatJNI
 * Method:    RunHeartbeat
 * Signature: ()I
 */
JNIEXPORT jint JNICALL
Java_com_revrobotics_jni_CANHeartbeatJNI_RunHeartbeat
  (JNIEnv*, jclass)
{
    return 0;
}

/*
 * Class:     com_revrobotics_jni_CANHeartbeatJNI
 * Method:    RegisterDevice
 * Signature: (I)V
 */
JNIEXPORT void JNICALL
Java_com_revrobotics_jni_CANHeartbeatJNI_RegisterDevice
  (JNIEnv*, jclass, jint)
{
}

/*
 * Class:     com_revrobotics_jni_CANHeartbeatJNI
 * Method:    UnregisterDevice
 * Signature: (I)V
 */
JNIEXPORT void JNICALL
Java_com_revrobotics_jni_CANHeartbeatJNI_UnregisterDevice
  (JNIEnv*, jclass, jint)
{
}

} // extern "C"
