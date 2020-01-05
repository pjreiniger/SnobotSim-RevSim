

#include "RevSimMocks/RevDeviceWrapper.h"

#include <vector>

#include "RevSimMocks/MockHooks.h"


std::vector<SnobotSim::REV_CallbackFunc> gRevCallbacks;

namespace SnobotSim
{
void SetSparkMaxDriverCallback(REV_CallbackFunc callback)
{
	gRevCallbacks.clear();
	gRevCallbacks.push_back(callback);
}

}

SnobotSim::RevSimulator::RevSimulator(int aDeviceId, const std::string& aName) :
	mDeviceId(aDeviceId)
{
	Send(aName);
}
void SnobotSim::RevSimulator::Receive(const std::string& aName, uint8_t* aBuffer, int aSize)
{
    if (!gRevCallbacks.empty())
    {
    	gRevCallbacks[0](aName.c_str(), mDeviceId, aBuffer, aSize);
    }
    else
    {
        LOG_UNSUPPORTED_CAN_FUNC("Callback " << aName << " not registered");
    }
}

void SnobotSim::RevSimulator::Send(const std::string& aName, uint8_t* aBuffer, int aSize)
{
    if (!gRevCallbacks.empty())
    {
    	gRevCallbacks[0](aName.c_str(), mDeviceId, aBuffer, aSize);
    }
    else
    {
        LOG_UNSUPPORTED_CAN_FUNC("Callback " << aName << " not registered");
    }
}
