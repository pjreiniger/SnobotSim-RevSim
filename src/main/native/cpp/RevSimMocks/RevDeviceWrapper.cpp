

#include "RevSimMocks/RevDeviceWrapper.h"

SnobotSim::RevSimulator::RevSimulator(int aDeviceId, const std::string& aName) :
	mDeviceId(aDeviceId)
{
	Send(aName);
}
void SnobotSim::RevSimulator::Receive(const std::string& aName, uint8_t* aBuffer, int aSize)
{
}

void SnobotSim::RevSimulator::Send(const std::string& aName, uint8_t* aBuffer, int aSize)
{
    if (false) //!gRevCallbacks.empty())
    {
        void* param = NULL;
        int32_t unused = 0;

//        gRevCallbacks[0](aName.c_str(), param, 0xFF01, aBuffer, aSize, 0, &unused);
    }
    else
    {
        LOG_UNSUPPORTED_CAN_FUNC("Callback " << aName << " not registered");
    }
}
