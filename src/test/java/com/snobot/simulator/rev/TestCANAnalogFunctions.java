package com.snobot.simulator.rev;

import java.nio.ByteBuffer;

import org.junit.Before;
import org.junit.Test;

import com.revrobotics.CANAnalog;
import com.revrobotics.CANAnalog.AnalogMode;
import com.revrobotics.CANSparkMax;
import com.revrobotics.CANSparkMaxLowLevel.MotorType;

public class TestCANAnalogFunctions
{
    private final RevCallback mRevCallback = new RevCallback()
    {
        @Override
        public void callback(String aName, int aDeviceId, ByteBuffer aBuffer, int aCount)
        {
            System.out.println("Getting CANAnalog callback '" + aName + "'"); // NOPMD
        }
    };

    @Before
    public void initialize()
    {
        System.loadLibrary("SparkMaxDriver");

        RevSimJni.registerRevCallback(mRevCallback);
    }

    @Test
    public void testAnnalogFunctions()
    {
        CANSparkMax sc = new CANSparkMax(11, MotorType.kBrushless);

        for (AnalogMode analogType : AnalogMode.values())
        {
            CANAnalog analog = sc.getAnalog(analogType);
            analog.getVoltage();
            analog.getPosition();
            analog.getVelocity();
            analog.setPositionConversionFactor(0);
            analog.setVelocityConversionFactor(0);
            analog.getPositionConversionFactor();
            analog.getVelocityConversionFactor();
            analog.setInverted(false);
            analog.getInverted();
        }
    }
}
