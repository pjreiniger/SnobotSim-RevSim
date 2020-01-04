//
//#include <jni.h>
//
//#include <iostream>
//
//#include "RevSimMocks/CanSetDriverSim.h"
//#include "com_snobot_simulator_rev_RevSimJni.h"
//#include "mockdata/CanData.h"
//
//namespace SnobotSimRev
//{
//
//JavaVM* sRevJvm = NULL;
//static jclass sRevCallbackClazz;
//
//static jobject sRevCallbackObject;
//static jmethodID sRevCanSendCallback;
//static jmethodID sRevCanReadCallback;
//
//} // namespace SnobotSimRev
//
//extern "C" {
//
//JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* reserved)
//{
//    SnobotSimRev::sRevJvm = vm;
//
//    JNIEnv* env;
//    if (vm->GetEnv(reinterpret_cast<void**>(&env), JNI_VERSION_1_6) != JNI_OK)
//    {
//        return JNI_ERR;
//    }
//
//    jclass localCallbackClazz = env->FindClass("com/snobot/simulator/rev/RevCallback");
//    SnobotSimRev::sRevCallbackClazz = static_cast<jclass>(env->NewGlobalRef(localCallbackClazz));
//    env->DeleteLocalRef(localCallbackClazz);
//
//    if (!SnobotSimRev::sRevCallbackClazz)
//    {
//        return JNI_ERR;
//    }
//
//    SnobotSimRev::sRevCanSendCallback = env->GetMethodID(SnobotSimRev::sRevCallbackClazz, "sendCallback", "(Ljava/lang/String;ILjava/nio/ByteBuffer;II)I");
//    if (!SnobotSimRev::sRevCanSendCallback)
//    {
//        std::cout << "NO SEND CALLBACK" << std::endl;
//        return JNI_ERR;
//    }
//
//    SnobotSimRev::sRevCanReadCallback = env->GetMethodID(SnobotSimRev::sRevCallbackClazz, "readCallback", "(Ljava/lang/String;ILjava/nio/ByteBuffer;)I");
//    if (!SnobotSimRev::sRevCanReadCallback)
//    {
//        std::cout << "NO READ CALLBACK" << std::endl;
//        return JNI_ERR;
//    }
//
//    return JNI_VERSION_1_6;
//}
//
//JNIEXPORT void JNICALL JNI_OnUnload(JavaVM* vm, void* reserved)
//{
//    JNIEnv* env;
//    if (vm->GetEnv(reinterpret_cast<void**>(&env), JNI_VERSION_1_6) != JNI_OK)
//    {
//        return;
//    }
//
//    SnobotSimRev::sRevJvm = NULL;
//}
//
///*
// * Class:     com_snobot_simulator_rev_RevSimJni
// * Method:    registerRevCallback
// * Signature: (Ljava/lang/Object;)V
// */
//JNIEXPORT void JNICALL
//Java_com_snobot_simulator_rev_RevSimJni_registerRevCallback
//  (JNIEnv* aEnv, jclass, jobject callback)
//{
//    using namespace SnobotSimRev;
//
//    sRevCallbackObject = aEnv->NewGlobalRef(callback);
//
//    static int dataPtr = 0;
//
//    auto sendCallbackFunc = [](const char* name, void* param,
//                                    uint32_t messageID, const uint8_t* data,
//                                    uint8_t dataSize, int32_t periodMs, int32_t* status) {
//        JavaVMAttachArgs args = { JNI_VERSION_1_6, 0, 0 };
//        JNIEnv* env;
//        sRevJvm->AttachCurrentThread(reinterpret_cast<void**>(&env), &args);
//
//        jobject dataBuffer = env->NewDirectByteBuffer(const_cast<uint8_t*>(data), static_cast<uint32_t>(dataSize));
//        jstring nameString = env->NewStringUTF(name);
//
//        if (sRevCanSendCallback)
//        {
//            *status = env->CallIntMethod(sRevCallbackObject, sRevCanSendCallback,
//                    nameString, messageID, dataBuffer, dataSize, periodMs);
//        }
//        else
//        {
//            std::cout << "No send callback" << std::endl;
//        }
//    };
//
//    SnobotSim::SetSendCallback(sendCallbackFunc);
//
//    auto readCallbackFunc = [](const char* name, void* param,
//                                    uint32_t* messageID, uint32_t messageIDMask,
//                                    uint8_t* data, uint8_t* dataSize,
//                                    uint32_t* timeStamp, int32_t* status) {
//        JavaVMAttachArgs args = { JNI_VERSION_1_6, 0, 0 };
//        JNIEnv* env;
//        sRevJvm->AttachCurrentThread(reinterpret_cast<void**>(&env), &args);
//
//        jobject dataBuffer = env->NewDirectByteBuffer(const_cast<uint8_t*>(data), static_cast<uint32_t>(8));
//        jstring nameString = env->NewStringUTF(name);
//
//        if (sRevCanReadCallback)
//        {
//            env->CallIntMethod(sRevCallbackObject, sRevCanReadCallback,
//                    nameString, *messageID, dataBuffer);
//
//            *dataSize = 8;
//        }
//        else
//        {
//            std::cout << "No read callback" << std::endl;
//        }
//    };
//
//    auto openStreamCallbackFunc = [](
//                                          const char* name, void* param,
//                                          uint32_t* sessionHandle, uint32_t messageID,
//                                          uint32_t messageIDMask, uint32_t maxMessages,
//                                          int32_t* status) {
//        std::cout << "Open Stream Message" << std::endl;
//    };
//
//    auto closeStreamCallbackFunc = [](
//                                           const char* name, void* param,
//                                           uint32_t sessionHandle) {
//        std::cout << "Close Stream Message" << std::endl;
//    };
//
//    auto readStreamCallbackFunc = [](
//                                          const char* name, void* param,
//                                          uint32_t sessionHandle,
//                                          struct HAL_CANStreamMessage* messages,
//                                          uint32_t messagesToRead, uint32_t* messagesRead,
//                                          int32_t* status) {
//        std::cout << "Read Stream Message" << std::endl;
//    };
//
//    auto getCanStatusCallbackFunc = [](
//                                            const char* name, void* param,
//                                            float* percentBusUtilization, uint32_t* busOffCount,
//                                            uint32_t* txFullCount, uint32_t* receiveErrorCount,
//                                            uint32_t* transmitErrorCount, int32_t* status) {
//        std::cout << "Get Status Message" << std::endl;
//    };
//
//    HALSIM_ResetCanData();
//
//    // Initialize
//    HALSIM_RegisterCanSendMessageCallback(sendCallbackFunc, &dataPtr);
//    HALSIM_RegisterCanReceiveMessageCallback(readCallbackFunc, &dataPtr);
//    HALSIM_RegisterCanOpenStreamCallback(openStreamCallbackFunc, &dataPtr);
//    HALSIM_RegisterCanCloseStreamCallback(closeStreamCallbackFunc, &dataPtr);
//    HALSIM_RegisterCanReadStreamCallback(readStreamCallbackFunc, &dataPtr);
//    HALSIM_RegisterCanGetCANStatusCallback(getCanStatusCallbackFunc, &dataPtr);
//}
//
///*
// * Class:     com_snobot_simulator_rev_RevSimJni
// * Method:    cancelRevCallback
// * Signature: ()V
// */
//JNIEXPORT void JNICALL
//Java_com_snobot_simulator_rev_RevSimJni_cancelRevCallback
//  (JNIEnv* aEnv, jclass)
//{
//    std::cout << "Not Supported" << std::endl;
//}
//
//} // extern "C"
