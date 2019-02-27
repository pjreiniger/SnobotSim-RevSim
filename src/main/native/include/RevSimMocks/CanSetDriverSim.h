

#ifndef SPARKMAXSIM_SRC_MAIN_NATIVE_INCLUDE_REVSIMMOCKS_CANSETDRIVERSIM_H_
#define SPARKMAXSIM_SRC_MAIN_NATIVE_INCLUDE_REVSIMMOCKS_CANSETDRIVERSIM_H_

#include <string>

#include "RevSimMocks/BaseRevWrapper.h"
#include "RevSimMocks/RevMockUtilities.h"

namespace SnobotSim
{

typedef void (*Rev_SendCallbackFunc)(const char* name, void* param,
        uint32_t messageID, const uint8_t* data,
        uint8_t dataSize, int32_t periodMs, int32_t* status);

typedef void (*Rev_ReadCallbackFunc)(const char* name, void* param,
        uint32_t* messageID, uint32_t messageIDMask,
        uint8_t* data, uint8_t* dataSize,
        uint32_t* timeStamp, int32_t* status);

void EXPORT_ SetSendCallback(Rev_SendCallbackFunc callback);

class RevSimulator : public BaseRevWrapper
{
public:
    using BaseRevWrapper::Send;

    RevSimulator();

    void Receive(const std::string& aName, uint8_t* aBuffer, int aSize);
    void Send(const std::string& aName, uint8_t* aBuffer, int aSize);
};

} // namespace SnobotSim

#endif // SPARKMAXSIM_SRC_MAIN_NATIVE_INCLUDE_REVSIMMOCKS_CANSETDRIVERSIM_H_
