/* DO NOT EDIT THIS std::FILE - it is machine generated */
#include <jni.h>

/* Header for class com_revrobotics_jni_CANHeartbeatJNI */

#ifndef SPARKMAXSIM_SRC_MAIN_NATIVE_INCLUDE_REVJNI_COM_REVROBOTICS_JNI_CANHEARTBEATJNI_H_
#define SPARKMAXSIM_SRC_MAIN_NATIVE_INCLUDE_REVJNI_COM_REVROBOTICS_JNI_CANHEARTBEATJNI_H_
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_revrobotics_jni_CANHeartbeatJNI
 * Method:    HeartbeatInit
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_revrobotics_jni_CANHeartbeatJNI_HeartbeatInit(JNIEnv*, jclass);

/*
 * Class:     com_revrobotics_jni_CANHeartbeatJNI
 * Method:    RunHeartbeat
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_com_revrobotics_jni_CANHeartbeatJNI_RunHeartbeat(JNIEnv*, jclass);

/*
 * Class:     com_revrobotics_jni_CANHeartbeatJNI
 * Method:    RegisterDevice
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_com_revrobotics_jni_CANHeartbeatJNI_RegisterDevice(JNIEnv*, jclass, jint);

/*
 * Class:     com_revrobotics_jni_CANHeartbeatJNI
 * Method:    UnregisterDevice
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_com_revrobotics_jni_CANHeartbeatJNI_UnregisterDevice(JNIEnv*, jclass, jint);

#ifdef __cplusplus
} // extern "C"
#endif
#endif // SPARKMAXSIM_SRC_MAIN_NATIVE_INCLUDE_REVJNI_COM_REVROBOTICS_JNI_CANHEARTBEATJNI_H_
