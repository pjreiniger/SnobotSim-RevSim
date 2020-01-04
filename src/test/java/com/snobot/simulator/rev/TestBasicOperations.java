package com.snobot.simulator.rev;

import static org.junit.Assert.fail;

import java.nio.ByteBuffer;

import org.junit.Before;
import org.junit.Test;

import com.revrobotics.AlternateEncoderType;
import com.revrobotics.CANAnalog.AnalogMode;
import com.revrobotics.CANDigitalInput;
import com.revrobotics.CANDigitalInput.LimitSwitchPolarity;
import com.revrobotics.CANEncoder;
import com.revrobotics.CANSparkMax;
import com.revrobotics.CANSparkMax.ExternalFollower;
import com.revrobotics.CANSparkMax.FaultID;
import com.revrobotics.CANSparkMax.IdleMode;
import com.revrobotics.CANSparkMax.SoftLimitDirection;
import com.revrobotics.CANSparkMaxLowLevel.MotorType;
import com.revrobotics.EncoderType;

import edu.wpi.first.hal.HAL;

public class TestBasicOperations
{
    private class TestableDeviceManager extends BaseRevDeviceManager
    {
        @Override
        protected int handleRead(int aDeviceId, int aApiId, ByteBuffer aBuffer)
        {
            String arbAsString = mArbIdLookup.get(aApiId);
            if (arbAsString == null)
            {
                fail("Unknown lookup for id " + aApiId);
                return 1;
            }

            if ("getFirmwareVersion".equals(arbAsString))
            {
                writeFirmwareVersion(aBuffer);
            }
            else
            {
                for (int i = 0; i < aBuffer.capacity(); ++i)
                {
                    aBuffer.put(i, (byte) 0);
                }
            }

            return 0;
        }

        @Override
        protected int handleSend(int aDeviceId, int aApiId, ByteBuffer aData)
        {
            String arbAsString = mArbIdLookup.get(aApiId);
            if (arbAsString == null)
            {
                fail("Unknown lookup for id " + aApiId);
                return 1;
            }

            return 0;
        }
    }

    @SuppressWarnings({ "PMD.NcssCount", "PMD.DataflowAnomalyAnalysis", "PMD.ExcessiveMethodLength", "PMD.CyclomaticComplexity", "PMD.NPathComplexity" })
    @Test
    public void testUnsupportedOperations()
    {
        CANSparkMax spark = new CANSparkMax(10, MotorType.kBrushless);
        CANSparkMax follower = new CANSparkMax(11, MotorType.kBrushed);
        ExternalFollower externalFollower = new ExternalFollower(15, 0);


       
        spark.set(0);
        spark.get();
        spark.setInverted(false);
        spark.getInverted();
        spark.disable();
        spark.stopMotor();
        spark.pidWrite(0);
        spark.getEncoder();
        for (EncoderType encoderType : EncoderType.values())
        {
            spark.getEncoder(encoderType, 0);
        }
        spark.getAlternateEncoder();
        for (AlternateEncoderType alternateEncoderType : AlternateEncoderType.values())
        {
            spark.getAlternateEncoder(alternateEncoderType, 0);
        }
        for (AnalogMode analogMode : AnalogMode.values())
        {
            spark.getAnalog(analogMode);
        }
        spark.getPIDController();
        for (LimitSwitchPolarity limitSwitchPolarity : LimitSwitchPolarity.values())
        {
            spark.getForwardLimitSwitch(limitSwitchPolarity);
        }
        for (LimitSwitchPolarity limitSwitchPolarity : LimitSwitchPolarity.values())
        {
            spark.getReverseLimitSwitch(limitSwitchPolarity);
        }
        spark.setSmartCurrentLimit(0);
        spark.setSmartCurrentLimit(0, 0);
        spark.setSmartCurrentLimit(0, 0, 0);
        spark.setSecondaryCurrentLimit(0);
        spark.setSecondaryCurrentLimit(0, 0);
        for (IdleMode idleMode : IdleMode.values())
        {
            spark.setIdleMode(idleMode);
        }
        spark.getIdleMode();
        spark.enableVoltageCompensation(0);
        spark.disableVoltageCompensation();
        spark.getVoltageCompensationNominalVoltage();
        spark.setOpenLoopRampRate(0);
        spark.setClosedLoopRampRate(0);
        spark.getOpenLoopRampRate();
        spark.getClosedLoopRampRate();

        spark.follow(follower);
        spark.follow(follower, false);
        spark.follow(externalFollower, 0);
        spark.follow(externalFollower, 0, false);
        spark.isFollower();
        spark.getFaults();
        spark.getStickyFaults();
        for (FaultID faultID : FaultID.values())
        {
            spark.getFault(faultID);
        }
        for (FaultID faultID : FaultID.values())
        {
            spark.getStickyFault(faultID);
        }
        spark.getBusVoltage();
        spark.getAppliedOutput();
        spark.getOutputCurrent();
        spark.getMotorTemperature();
        spark.clearFaults();
        spark.burnFlash();
        spark.setCANTimeout(0);
        for (SoftLimitDirection softLimitDirection : SoftLimitDirection.values())
        {
            spark.enableSoftLimit(softLimitDirection, false);
        }
        for (SoftLimitDirection softLimitDirection : SoftLimitDirection.values())
        {
            spark.setSoftLimit(softLimitDirection, 0);
        }
        for (SoftLimitDirection softLimitDirection : SoftLimitDirection.values())
        {
            spark.getSoftLimit(softLimitDirection);
        }
        for (SoftLimitDirection softLimitDirection : SoftLimitDirection.values())
        {
            spark.isSoftLimitEnabled(softLimitDirection);
        }
        spark.getLastError();
        
        spark.close();
    }

    @Test
    public void testLimitSwitchFunctions()
    {
        CANSparkMax sc = new CANSparkMax(11, MotorType.kBrushless);

        for (LimitSwitchPolarity polarity : LimitSwitchPolarity.values())
        {
            CANDigitalInput reverseSwitch = sc.getReverseLimitSwitch(polarity);
            CANDigitalInput fowrardSwitch = sc.getForwardLimitSwitch(polarity);

            reverseSwitch.enableLimitSwitch(false);
            reverseSwitch.enableLimitSwitch(true);
            reverseSwitch.get();
            reverseSwitch.isLimitSwitchEnabled();

            fowrardSwitch.enableLimitSwitch(false);
            fowrardSwitch.enableLimitSwitch(true);
            fowrardSwitch.get();
            fowrardSwitch.isLimitSwitchEnabled();
        }

    }

    @Test
    public void testEncoderFunctions()
    {
        CANSparkMax sc = new CANSparkMax(12, MotorType.kBrushless);
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

    @Before
    public void initialize()
    {
        System.loadLibrary("wpiutil");
        System.loadLibrary("wpiHal");
        System.loadLibrary("wpiHaljni");

        HAL.initialize(0, 0);

        System.loadLibrary("SparkMaxDriver");

        new TestableDeviceManager();
        HAL.initialize(0, 0);

    }
}
