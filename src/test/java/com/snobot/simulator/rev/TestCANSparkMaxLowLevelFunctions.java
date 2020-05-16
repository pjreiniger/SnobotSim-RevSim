package com.snobot.simulator.rev;

import java.nio.ByteBuffer;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import com.revrobotics.CANSparkMax;
import com.revrobotics.CANSparkMaxLowLevel.MotorType;
import com.revrobotics.CANSparkMaxLowLevel.PeriodicFrame;
import com.snobot.test.utilities.SimDeviceDumpHelper;

import edu.wpi.first.hal.HAL;
import edu.wpi.first.hal.sim.SimDeviceSim;
import edu.wpi.first.hal.sim.mockdata.SimulatorJNI;

public class TestCANSparkMaxLowLevelFunctions
{
    private final RevCallback mRevCallback = new RevCallback()
    {
        @Override
        public void callback(String aName, int aDeviceId, ByteBuffer aBuffer, int aCount)
        {
            System.out.println("Getting CANSparkMaxLowLevel callback '" + aName + "' with size of " + aBuffer.capacity() + ", " + aCount); // NOPMD
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

    @SuppressWarnings({ "PMD.NcssCount", "PMD.DataflowAnomalyAnalysis", "PMD.ExcessiveMethodLength", "PMD.CyclomaticComplexity", "PMD.NPathComplexity" })
    @Test
    public void testUnsupportedOperations()
    {
        CANSparkMax spark = new CANSparkMax(10, MotorType.kBrushless);
        SimDeviceDumpHelper.dumpSimDevices();


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
        spark.getSafeFloat(0);
        spark.restoreFactoryDefaults();
        spark.restoreFactoryDefaults(false);
    }
}
