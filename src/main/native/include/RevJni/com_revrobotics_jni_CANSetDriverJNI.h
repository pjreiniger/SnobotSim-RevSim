/* DO NOT EDIT THIS std::FILE - it is machine generated */
#include <jni.h>

/* Header for class com_revrobotics_jni_CANSetDriverJNI */

#ifndef SPARKMAXSIM_SRC_MAIN_NATIVE_INCLUDE_REVJNI_COM_REVROBOTICS_JNI_CANSETDRIVERJNI_H_
#define SPARKMAXSIM_SRC_MAIN_NATIVE_INCLUDE_REVJNI_COM_REVROBOTICS_JNI_CANSETDRIVERJNI_H_
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_revrobotics_jni_CANSetDriverJNI
 * Method:    SetDriverInit
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_revrobotics_jni_CANSetDriverJNI_SetDriverInit(JNIEnv*, jclass);

/*
 * Class:     com_revrobotics_jni_CANSetDriverJNI
 * Method:    RunSetDriver
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_com_revrobotics_jni_CANSetDriverJNI_RunSetDriver(JNIEnv*, jclass);

/*
 * Class:     com_revrobotics_jni_CANSetDriverJNI
 * Method:    SetDriverSet4
 * Signature: (IFIBS)V
 */
JNIEXPORT void JNICALL Java_com_revrobotics_jni_CANSetDriverJNI_SetDriverSet4(JNIEnv*, jclass, jint, jfloat, jint, jbyte, jshort);

/*
 * Class:     com_revrobotics_jni_CANSetDriverJNI
 * Method:    SetDriverSetCtrlFramePeriodMs
 * Signature: (II)V
 */
JNIEXPORT void JNICALL Java_com_revrobotics_jni_CANSetDriverJNI_SetDriverSetCtrlFramePeriodMs(JNIEnv*, jclass, jint, jint);

#ifdef __cplusplus
} // extern "C"
#endif
#endif // SPARKMAXSIM_SRC_MAIN_NATIVE_INCLUDE_REVJNI_COM_REVROBOTICS_JNI_CANSETDRIVERJNI_H_
