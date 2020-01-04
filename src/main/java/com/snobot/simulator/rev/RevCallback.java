package com.snobot.simulator.rev;

import java.nio.ByteBuffer;

public interface RevCallback
{
    void callback(String aName, int aDeviceId, ByteBuffer aBuffer, int aCount);
}
