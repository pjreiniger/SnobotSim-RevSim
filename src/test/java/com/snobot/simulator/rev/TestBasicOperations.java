package com.snobot.simulator.rev;

import java.nio.ByteBuffer;

import org.junit.Before;
import org.junit.Test;

import com.revrobotics.AlternateEncoderType;
import com.revrobotics.CANAnalog;
import com.revrobotics.CANAnalog.AnalogMode;
import com.revrobotics.CANDigitalInput;
import com.revrobotics.CANDigitalInput.LimitSwitchPolarity;
import com.revrobotics.CANEncoder;
import com.revrobotics.CANPIDController;
import com.revrobotics.CANPIDController.AccelStrategy;
import com.revrobotics.CANPIDController.ArbFFUnits;
import com.revrobotics.CANSparkMax;
import com.revrobotics.CANSparkMax.ExternalFollower;
import com.revrobotics.CANSparkMax.FaultID;
import com.revrobotics.CANSparkMax.IdleMode;
import com.revrobotics.CANSparkMax.SoftLimitDirection;
import com.revrobotics.CANSparkMaxLowLevel.MotorType;
import com.revrobotics.ControlType;
import com.revrobotics.EncoderType;

public class TestBasicOperations
{
    private final RevCallback mRevCallback = new RevCallback()
    {
        @Override
        public void callback(String aName, int aDeviceId, ByteBuffer aBuffer, int aCount)
        {
            System.out.println("Getting BasicOperation callback '" + aName + "' with size of " + aBuffer.capacity() + ", " + aCount); // NOPMD
        }
    };

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
        // encoder.setInverted(false);
        encoder.getInverted();
    }

    @SuppressWarnings("PMD.NcssCount")
    @Test
    public void testPidFunctions()
    {
        CANSparkMax sc = new CANSparkMax(12, MotorType.kBrushless);
        CANPIDController pid = new CANPIDController(sc);

        for (ControlType controlType : ControlType.values())
        {
            pid.setReference(0, controlType);
        }
        for (ControlType controlType : ControlType.values())
        {
            pid.setReference(0, controlType, 0);
        }
        for (ControlType controlType : ControlType.values())
        {
            pid.setReference(0, controlType, 0, 0);
        }
        for (ControlType controlType : ControlType.values())
        {
            pid.setReference(0, controlType, 0, 0, ArbFFUnits.kVoltage);
            pid.setReference(0, controlType, 0, 0, ArbFFUnits.kPercentOut);
        }
        pid.setP(0);
        pid.setP(0, 0);
        pid.setI(0);
        pid.setI(0, 0);
        pid.setD(0);
        pid.setD(0, 0);
        pid.setDFilter(0);
        pid.setDFilter(0, 0);
        pid.setFF(0);
        pid.setFF(0, 0);
        pid.setIZone(0);
        pid.setIZone(0, 0);
        pid.setOutputRange(0, 0);
        pid.setOutputRange(0, 0, 0);
        pid.getP();
        pid.getP(0);
        pid.getI();
        pid.getI(0);
        pid.getD();
        pid.getD(0);
        pid.getDFilter(0);
        pid.getFF();
        pid.getFF(0);
        pid.getIZone();
        pid.getIZone(0);
        pid.getOutputMin();
        pid.getOutputMin(0);
        pid.getOutputMax();
        pid.getOutputMax(0);
        pid.setSmartMotionMaxVelocity(0, 0);
        pid.setSmartMotionMaxAccel(0, 0);
        pid.setSmartMotionMinOutputVelocity(0, 0);
        pid.setSmartMotionAllowedClosedLoopError(0, 0);
        for (AccelStrategy accelStrategy : AccelStrategy.values())
        {
            pid.setSmartMotionAccelStrategy(accelStrategy, 0);
        }
        pid.getSmartMotionMaxVelocity(0);
        pid.getSmartMotionMaxAccel(0);
        pid.getSmartMotionMinOutputVelocity(0);
        pid.getSmartMotionAllowedClosedLoopError(0);
        pid.getSmartMotionAccelStrategy(0);
        pid.setIMaxAccum(0, 0);
        pid.getIMaxAccum(0);
        pid.setIAccum(0);
        pid.getIAccum();

        CANEncoder sensor = sc.getEncoder();
        pid.setFeedbackDevice(sensor);
    }

    @Before
    public void initialize()
    {
        // System.loadLibrary("wpiutil");
        // System.loadLibrary("wpiHal");
        // System.loadLibrary("wpiHaljni");
        //
        // HAL.initialize(0, 0);

        System.loadLibrary("SparkMaxDriver");

        RevSimJni.registerRevCallback(mRevCallback);

    }
}
