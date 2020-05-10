package com.snobot.simulator.rev;

import java.nio.ByteBuffer;

import org.junit.Before;
import org.junit.Test;

import com.revrobotics.CANEncoder;
import com.revrobotics.CANSparkMax;
import com.revrobotics.CANSparkMaxLowLevel.MotorType;

public class TestCANEncoderFunctions
{
    private final RevCallback mRevCallback = new RevCallback()
    {
        @Override
        public void callback(String aName, int aDeviceId, ByteBuffer aBuffer, int aCount)
        {
            System.out.println("Getting CANEncoder callback '" + aName + "' with size of " + aBuffer.capacity() + ", " + aCount); // NOPMD
        }
    };

    @Before
    public void initialize()
    {
        System.loadLibrary("SparkMaxDriver");

        RevSimJni.registerRevCallback(mRevCallback);

    }

    @Test
    public void testEncoderFunctions()
    {
        CANSparkMax sc = new CANSparkMax(12, MotorType.kBrushed);
        CANEncoder encoder = sc.getEncoder();

        encoder.getPosition();
        encoder.getVelocity();
        encoder.setPosition(0);
        encoder.setPositionConversionFactor(0);
        encoder.setVelocityConversionFactor(0);
        encoder.getPositionConversionFactor();
        encoder.getVelocityConversionFactor();
        encoder.setAverageDepth(0);
        encoder.getAverageDepth();
        encoder.setMeasurementPeriod(0);
        encoder.getMeasurementPeriod();
        encoder.getCPR();
        encoder.getCountsPerRevolution();
        encoder.setInverted(false);
        encoder.getInverted();
    }
}
