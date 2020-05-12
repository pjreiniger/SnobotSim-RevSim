package com.snobot.simulator.rev;

import java.nio.ByteBuffer;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import com.revrobotics.CANAnalog;
import com.revrobotics.CANAnalog.AnalogMode;
import com.revrobotics.CANSparkMax;
import com.revrobotics.CANSparkMaxLowLevel.MotorType;
import com.snobot.test.utilities.SimDeviceDumpHelper;

import edu.wpi.first.hal.HAL;
import edu.wpi.first.hal.sim.SimDeviceSim;
import edu.wpi.first.hal.sim.mockdata.SimulatorJNI;

public class TestCANAnalogFunctions
{
    private final RevCallback mRevCallback = new RevCallback()
    {
        @Override
        public void callback(String aName, int aDeviceId, ByteBuffer aBuffer, int aCount)
        {
            System.out.println("Getting CANAnalog callback '" + aName + "' with size of " + aBuffer.capacity() + ", " + aCount); // NOPMD
        }
    };

    @BeforeEach
    public void initialize()
    {
        HAL.initialize(0, 0);
        System.loadLibrary("SparkMaxDriver");

        SimulatorJNI.resetHandles();
        SimDeviceSim.resetData();
        RevSimJni.registerRevCallback(mRevCallback);
    }

    @Test
    public void testAnnalogFunctions()
    {
        CANSparkMax sc = new CANSparkMax(11, MotorType.kBrushless);
        SimDeviceDumpHelper.dumpSimDevices();

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
