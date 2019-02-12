package com.snobot.simulator.rev;

import java.nio.ByteBuffer;

public interface RevCallback
{
    int sendCallback(String aName, int aMessageId, ByteBuffer aData, int aDataSize, int aPeriodMs);

    int readCallback(String aName, int aMessageId, ByteBuffer aBuffer);
}
