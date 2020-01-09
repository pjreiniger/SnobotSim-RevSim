
#include <jni.h>

#include <iostream>

#include "RevSimMocks/MockHooks.h"
#include "com_snobot_simulator_rev_RevSimJni.h"

namespace SnobotSimRev
{

JavaVM* sRevJvm = NULL;
static jclass sRevCallbackClazz;
static jmethodID sRevBufferCallbackCallback;
static jobject sRevCallbackObject = NULL;

} // namespace SnobotSimRev

extern "C" {

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* reserved)
{
    SnobotSimRev::sRevJvm = vm;

    JNIEnv* env;
    if (vm->GetEnv(reinterpret_cast<void**>(&env), JNI_VERSION_1_6) != JNI_OK)
    {
        return JNI_ERR;
    }

    jclass localCallbackClazz = env->FindClass("com/snobot/simulator/rev/RevCallback");
    SnobotSimRev::sRevCallbackClazz = static_cast<jclass>(env->NewGlobalRef(localCallbackClazz));
    env->DeleteLocalRef(localCallbackClazz);

    if (!SnobotSimRev::sRevCallbackClazz)
    {
        return JNI_ERR;
    }

    SnobotSimRev::sRevBufferCallbackCallback = env->GetMethodID(SnobotSimRev::sRevCallbackClazz, "callback", "(Ljava/lang/String;ILjava/nio/ByteBuffer;I)V");
    if (!SnobotSimRev::sRevBufferCallbackCallback)
    {
        std::cout << "NO SEND CALLBACK" << std::endl;
        return JNI_ERR;
    }

    return JNI_VERSION_1_6;
}

JNIEXPORT void JNICALL JNI_OnUnload(JavaVM* vm, void* reserved)
{
    JNIEnv* env;
    if (vm->GetEnv(reinterpret_cast<void**>(&env), JNI_VERSION_1_6) != JNI_OK)
    {
        return;
    }

    SnobotSimRev::sRevJvm = NULL;
}

/*
 * Class:     com_snobot_simulator_rev_RevSimJni
 * Method:    registerRevCallback
 * Signature: (Ljava/lang/Object;)V
 */
JNIEXPORT void JNICALL
Java_com_snobot_simulator_rev_RevSimJni_registerRevCallback
  (JNIEnv* aEnv, jclass, jobject callback)
{
    using namespace SnobotSimRev;

    sRevCallbackObject = aEnv->NewGlobalRef(callback);

    auto callbackFunc = [](const char* name,
                                uint32_t messageId,
                                uint8_t* buffer,
                                int length) {
        JavaVMAttachArgs args = { JNI_VERSION_1_6, 0, 0 };
        JNIEnv* env;
        SnobotSimRev::sRevJvm->AttachCurrentThread(reinterpret_cast<void**>(&env), &args);

        jobject dataBuffer = env->NewDirectByteBuffer(const_cast<uint8_t*>(buffer), static_cast<uint32_t>(length));
        jstring nameString = env->NewStringUTF(name);

        if (SnobotSimRev::sRevCallbackObject)
        {
            env->CallVoidMethod(SnobotSimRev::sRevCallbackObject, SnobotSimRev::sRevBufferCallbackCallback, nameString,
                    messageId, dataBuffer, length);
        }
    };

    SnobotSim::SetSparkMaxDriverCallback(callbackFunc);
}

/*
 * Class:     com_snobot_simulator_rev_RevSimJni
 * Method:    cancelRevCallback
 * Signature: ()V
 */
JNIEXPORT void JNICALL
Java_com_snobot_simulator_rev_RevSimJni_cancelRevCallback
  (JNIEnv* aEnv, jclass)
{
    std::cout << "Not Supported" << std::endl;
}

} // extern "C"
