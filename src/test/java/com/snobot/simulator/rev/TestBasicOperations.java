package com.snobot.simulator.rev;

import static org.junit.Assert.fail;

import java.nio.ByteBuffer;

import org.junit.Before;
import org.junit.Test;

import com.revrobotics.CANDigitalInput;
import com.revrobotics.CANDigitalInput.LimitSwitchPolarity;
import com.revrobotics.CANEncoder;
import com.revrobotics.CANSparkMax;
import com.revrobotics.CANSparkMax.ExternalFollower;
import com.revrobotics.CANSparkMax.FaultID;
import com.revrobotics.CANSparkMax.IdleMode;
import com.revrobotics.CANSparkMaxLowLevel.ConfigParameter;
import com.revrobotics.CANSparkMaxLowLevel.MotorType;
import com.revrobotics.CANSparkMaxLowLevel.ParameterType;
import com.revrobotics.CANSparkMaxLowLevel.PeriodicFrame;

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
        CANSparkMax sc = new CANSparkMax(10, MotorType.kBrushless);
        CANSparkMax follower = new CANSparkMax(11, MotorType.kBrushed);
        ExternalFollower externalFollower = new ExternalFollower(15, 0);


        sc.set(0);
        sc.get();
        sc.setInverted(false);
        sc.getInverted();
        sc.disable();
        sc.stopMotor();
        sc.pidWrite(0);
        sc.getEncoder();
        sc.getPIDController();
        for (LimitSwitchPolarity limitSwitchPolarity : LimitSwitchPolarity.values())
        {
            sc.getForwardLimitSwitch(limitSwitchPolarity);
        }
        for (LimitSwitchPolarity limitSwitchPolarity : LimitSwitchPolarity.values())
        {
            sc.getReverseLimitSwitch(limitSwitchPolarity);
        }
        sc.setSmartCurrentLimit(0);
        sc.setSmartCurrentLimit(0, 0);
        sc.setSmartCurrentLimit(0, 0, 0);
        sc.setSecondaryCurrentLimit(0);
        sc.setSecondaryCurrentLimit(0, 0);
        for (IdleMode idleMode : IdleMode.values())
        {
            sc.setIdleMode(idleMode);
        }
        sc.getIdleMode();
        sc.enableVoltageCompensation(0);
        sc.disableVoltageCompensation();
        sc.getVoltageCompensationNominalVoltage();
        sc.setOpenLoopRampRate(0);
        sc.setClosedLoopRampRate(0);
        sc.getOpenLoopRampRate();
        sc.getClosedLoopRampRate();
        sc.follow(follower);
        sc.follow(follower, true);
        sc.follow(externalFollower, 11);
        sc.follow(externalFollower, 12, true);
        sc.isFollower();
        sc.getFaults();
        sc.getStickyFaults();
        for (FaultID faultID : FaultID.values())
        {
            sc.getFault(faultID);
        }
        for (FaultID faultID : FaultID.values())
        {
            sc.getStickyFault(faultID);
        }
        sc.getBusVoltage();
        sc.getAppliedOutput();
        sc.getOutputCurrent();
        sc.getMotorTemperature();
        sc.clearFaults();
        sc.burnFlash();
        sc.setCANTimeout(0);

        sc.getFirmwareVersion();
        sc.setControlFramePeriodMs(0);
        sc.getFirmwareString();
        sc.getSerialNumber();
        sc.getDeviceId();
        for (MotorType motorType : MotorType.values())
        {
            sc.setMotorType(motorType);
        }
        sc.getMotorType();
        for (PeriodicFrame periodicFrame : PeriodicFrame.values())
        {
            sc.setPeriodicFramePeriod(periodicFrame, 0);
        }
        for (ConfigParameter configParameter : ConfigParameter.values())
        {
            sc.setParameter(configParameter, 0);
        }
        for (ConfigParameter configParameter : ConfigParameter.values())
        {
            sc.setParameter(configParameter, 0);
        }
        for (ConfigParameter configParameter : ConfigParameter.values())
        {
            sc.setParameter(configParameter, false);
        }
        for (ConfigParameter configParameter : ConfigParameter.values())
        {
            sc.getParameterDouble(configParameter);
        }
        for (ConfigParameter configParameter : ConfigParameter.values())
        {
            sc.getParameterInt(configParameter);
        }
        for (ConfigParameter configParameter : ConfigParameter.values())
        {
            sc.getParameterBoolean(configParameter);
        }
        sc.getSafeFloat(1.5f);
        sc.setEncPosition(0);
        sc.setIAccum(0);
        sc.restoreFactoryDefaults();
        sc.restoreFactoryDefaults(false);
        for (ConfigParameter configParameter : ConfigParameter.values())
        {
            for (ParameterType type : ParameterType.values())
            {
                sc.getParameterCore(configParameter, type);
                sc.setParameterCore(configParameter, type, 1);
            }
        }

        for (ConfigParameter configParameter : ConfigParameter.values())
        {
            sc.getParameterType(configParameter);
        }

        sc.close();
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
