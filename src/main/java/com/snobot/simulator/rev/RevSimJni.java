package com.snobot.simulator.rev;

public final class RevSimJni
{
    private RevSimJni()
    {

    }

    public static native void registerRevCallback(RevCallback aCallback);

    public static native void cancelRevCallback();

}
