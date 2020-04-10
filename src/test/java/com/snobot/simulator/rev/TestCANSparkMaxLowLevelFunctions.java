package com.snobot.simulator.rev;

import java.nio.ByteBuffer;

import org.junit.Before;
import org.junit.Test;

import com.revrobotics.CANSparkMax;
import com.revrobotics.CANSparkMaxLowLevel.MotorType;
import com.revrobotics.CANSparkMaxLowLevel.PeriodicFrame;

public class TestCANSparkMaxLowLevelFunctions
{
    private final RevCallback mRevCallback = new RevCallback()
    {
        @Override
        public void callback(String aName, int aDeviceId, ByteBuffer aBuffer, int aCount)
        {
            // Nothing to do
        }
    };

    @Before
    public void initialize()
    {
        System.loadLibrary("SparkMaxDriver");

        RevSimJni.registerRevCallback(mRevCallback);

    }

    @SuppressWarnings({ "PMD.NcssCount", "PMD.DataflowAnomalyAnalysis", "PMD.ExcessiveMethodLength", "PMD.CyclomaticComplexity", "PMD.NPathComplexity" })
    @Test
    public void testUnsupportedOperations()
    {
        CANSparkMax spark = new CANSparkMax(10, MotorType.kBrushless);


        spark.getFirmwareVersion();
        spark.setControlFramePeriodMs(0);
        spark.getFirmwareString();
        spark.getSerialNumber();
        spark.getDeviceId();
        spark.getInitialMotorType();
        for (MotorType motorType : MotorType.values())
        {
            spark.setMotorType(motorType);
        }
        spark.getMotorType();
        for (PeriodicFrame periodicFrame : PeriodicFrame.values())
        {
            spark.setPeriodicFramePeriod(periodicFrame, 0);
        }
        spark.enableExternalUSBControl(false);
        spark.getSafeFloat(0.0f);
        spark.restoreFactoryDefaults();
        spark.restoreFactoryDefaults(false);
    }
}
