

#ifndef SNOBOTSIM_REVSIM_SRC_MAIN_NATIVE_INCLUDE_REVSIMMOCKS_REVDEVICEWRAPPER_H_
#define SNOBOTSIM_REVSIM_SRC_MAIN_NATIVE_INCLUDE_REVSIMMOCKS_REVDEVICEWRAPPER_H_

#include <string>

#include "RevSimMocks/BaseRevWrapper.h"
#include "RevSimMocks/RevMockUtilities.h"

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
};

} // namespace SnobotSim

#endif // SNOBOTSIM_REVSIM_SRC_MAIN_NATIVE_INCLUDE_REVSIMMOCKS_REVDEVICEWRAPPER_H_
