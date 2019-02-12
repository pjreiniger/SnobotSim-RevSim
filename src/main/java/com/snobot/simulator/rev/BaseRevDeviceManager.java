package com.snobot.simulator.rev;

import java.nio.ByteBuffer;
import java.nio.ByteOrder;
import java.util.HashMap;
import java.util.Map;

import org.apache.logging.log4j.Level;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

public abstract class BaseRevDeviceManager
{
    private static final Logger sLOGGER = LogManager.getLogger(BaseRevDeviceManager.class);

    private final RevCallback mRevCallback = new RevCallback()
    {
        @Override
        public int sendCallback(String aName, int aMessageId, ByteBuffer aData, int aDataSize, int aPeriod)
        {
            int deviceId = aMessageId & 0x3F;
            int apiId = (aMessageId >> 6) & 0x3FF;
            int manufacturer = (aMessageId >> 16) & 0xFF;
            int deviceType = (aMessageId >> 24) & 0x1F;

            sLOGGER.log(Level.TRACE,
                    "Getting send: Message ID: 0x" + Integer.toHexString(aMessageId) + " -> Device ID: " + deviceId + ", API Id: " + apiId
                            + ", Manufacturer: " + manufacturer + ", Device Type: " + deviceType);

            return handleSend(deviceId, apiId, aData);
        }

        @Override
        public int readCallback(String aName, int aMessageId, ByteBuffer aBuffer)
        {
            int deviceId = aMessageId & 0x3F;
            int apiId = (aMessageId >> 6) & 0x3FF;
            int manufacturer = (aMessageId >> 16) & 0xFF;
            int deviceType = (aMessageId >> 24) & 0x1F;

            sLOGGER.log(Level.TRACE, "Getting read: Message ID: 0x" + Integer.toHexString(aMessageId) + " -> Device ID: " + deviceId + ", API Id: "
                    + apiId + ", Manufacturer: " + manufacturer + ", Device Type: " + deviceType);

            return handleRead(deviceId, apiId, aBuffer);
        }
    };

    private final Map<Integer, String> mArbIdLookup;

    @SuppressWarnings("PMD")
    public BaseRevDeviceManager()
    {
        RevSimJni.registerRevCallback(mRevCallback);

        mArbIdLookup = new HashMap<>();
        mArbIdLookup.put(2, "SetpointOut");
        mArbIdLookup.put(96, "getAppliedOutput");
        mArbIdLookup.put(97, "getPeriodicStatus1");
        mArbIdLookup.put(98, "getPeriodicStatus2");
        mArbIdLookup.put(110, "clearFaults");
        mArbIdLookup.put(114, "burnFlash");
        mArbIdLookup.put(115, "follow");
        mArbIdLookup.put(146, "heartbeat");
        mArbIdLookup.put(152, "getFirmwareVersion");

        mArbIdLookup.put(768, "getParamterCore(kCanID)");
        mArbIdLookup.put(769, "getParamterCore(kInputMode)");
        mArbIdLookup.put(770, "getParamterCore(kMotorType)");
        mArbIdLookup.put(771, "getParamterCore(kCommAdvance)");
        mArbIdLookup.put(772, "getParamterCore(kSensorType)");
        mArbIdLookup.put(773, "getParamterCore(kCtrlType)");
        mArbIdLookup.put(774, "getParamterCore(kIdleMode)");
        mArbIdLookup.put(775, "getParamterCore(kInputDeadband)");
        mArbIdLookup.put(776, "getParamterCore(kFirmwareVer)");
        mArbIdLookup.put(777, "getParamterCore(kHallOffset)");
        mArbIdLookup.put(778, "getParamterCore(kPolePairs)");
        mArbIdLookup.put(779, "getParamterCore(kCurrentChop)");
        mArbIdLookup.put(780, "getParamterCore(kCurrentChopCycles)");
        mArbIdLookup.put(781, "getParamterCore(kP_0)");
        mArbIdLookup.put(782, "getParamterCore(kI_0)");
        mArbIdLookup.put(783, "getParamterCore(kD_0)");
        mArbIdLookup.put(784, "getParamterCore(kF_0)");
        mArbIdLookup.put(785, "getParamterCore(kIZone_0)");
        mArbIdLookup.put(786, "getParamterCore(kDFilter_0)");
        mArbIdLookup.put(787, "getParamterCore(kOutputMin_0)");
        mArbIdLookup.put(788, "getParamterCore(kOutputMax_0)");
        mArbIdLookup.put(789, "getParamterCore(kP_1)");
        mArbIdLookup.put(790, "getParamterCore(kI_1)");
        mArbIdLookup.put(791, "getParamterCore(kD_1)");
        mArbIdLookup.put(792, "getParamterCore(kF_1)");
        mArbIdLookup.put(793, "getParamterCore(kIZone_1)");
        mArbIdLookup.put(794, "getParamterCore(kDFilter_1)");
        mArbIdLookup.put(795, "getParamterCore(kOutputMin_1)");
        mArbIdLookup.put(796, "getParamterCore(kOutputMax_1)");
        mArbIdLookup.put(797, "getParamterCore(kP_2)");
        mArbIdLookup.put(798, "getParamterCore(kI_2)");
        mArbIdLookup.put(799, "getParamterCore(kD_2)");
        mArbIdLookup.put(800, "getParamterCore(kF_2)");
        mArbIdLookup.put(801, "getParamterCore(kIZone_2)");
        mArbIdLookup.put(802, "getParamterCore(kDFilter_2)");
        mArbIdLookup.put(803, "getParamterCore(kOutputMin_2)");
        mArbIdLookup.put(804, "getParamterCore(kOutputMax_2)");
        mArbIdLookup.put(805, "getParamterCore(kP_3)");
        mArbIdLookup.put(806, "getParamterCore(kI_3)");
        mArbIdLookup.put(807, "getParamterCore(kD_3)");
        mArbIdLookup.put(808, "getParamterCore(kF_3)");
        mArbIdLookup.put(809, "getParamterCore(kIZone_3)");
        mArbIdLookup.put(810, "getParamterCore(kDFilter_3)");
        mArbIdLookup.put(811, "getParamterCore(kOutputMin_3)");
        mArbIdLookup.put(812, "getParamterCore(kOutputMax_3)");
        mArbIdLookup.put(813, "getParamterCore(kReserved)");
        mArbIdLookup.put(814, "getParamterCore(kOutputRatio)");
        mArbIdLookup.put(815, "getParamterCore(kSerialNumberLow)");
        mArbIdLookup.put(816, "getParamterCore(kSerialNumberMid)");
        mArbIdLookup.put(817, "getParamterCore(kSerialNumberHigh)");
        mArbIdLookup.put(818, "getParamterCore(kLimitSwitchFwdPolarity)");
        mArbIdLookup.put(819, "getParamterCore(kLimitSwitchRevPolarity)");
        mArbIdLookup.put(820, "getParamterCore(kHardLimitFwdEn)");
        mArbIdLookup.put(821, "getParamterCore(kHardLimitRevEn)");
        mArbIdLookup.put(822, "getParamterCore(kSoftLimitFwdEn)");
        mArbIdLookup.put(823, "getParamterCore(kSoftLimitRevEn)");
        mArbIdLookup.put(824, "getParamterCore(kRampRate)");
        mArbIdLookup.put(825, "getParamterCore(kFollowerID)");
        mArbIdLookup.put(826, "getParamterCore(kFollowerConfig)");
        mArbIdLookup.put(827, "getParamterCore(kSmartCurrentStallLimit)");
        mArbIdLookup.put(828, "getParamterCore(kSmartCurrentFreeLimit)");
        mArbIdLookup.put(829, "getParamterCore(kSmartCurrentConfig)");
        mArbIdLookup.put(830, "getParamterCore(kSmartCurrentReserved)");
        mArbIdLookup.put(831, "getParamterCore(kMotorKv)");
        mArbIdLookup.put(832, "getParamterCore(kMotorR)");
        mArbIdLookup.put(833, "getParamterCore(kMotorL)");
        mArbIdLookup.put(834, "getParamterCore(kMotorRsvd1)");
        mArbIdLookup.put(835, "getParamterCore(kMotorRsvd2)");
        mArbIdLookup.put(836, "getParamterCore(kMotorRsvd3)");
        mArbIdLookup.put(837, "getParamterCore(kEncoderCountsPerRev)");
        mArbIdLookup.put(838, "getParamterCore(kEncoderAverageDepth)");
        mArbIdLookup.put(839, "getParamterCore(kEncoderSampleDelta)");

        // for (ConfigParameter paramter : ConfigParameter.values())
        // {
        // int key = 768 + paramter.value;
        // mArbIdLookup.put(key, "getParamterCore(" + paramter + ")");
        // System.out.println(" mArbIdLookup.put(" + key + ",
        // \"getParamterCore(" + paramter + ")\");");
        // }
    }

    @SuppressWarnings("PMD")
    protected int handleSend(int aDeviceId, int aApiId, ByteBuffer aData)
    {
        int output = 0;

        String arbAsString = mArbIdLookup.get(aApiId);
        if (arbAsString == null)
        {
            sLOGGER.log(Level.ERROR, "Unknown API Id " + aApiId);
            return 1;
        }

        switch (arbAsString)
        {
        case "heartbeat":
        {
            sLOGGER.log(Level.TRACE, "Hearbeat not supported");
            break;
        }

        case "SetpointOut":
        {
            if (aData.capacity() == 0)
            {
                return output;
            }

            aData.order(ByteOrder.LITTLE_ENDIAN);
            float setpoint = aData.getFloat();
            short auxSetpoint = aData.getShort();
            byte pidSlot = aData.get();
            byte rsvd = aData.get();

            set(aDeviceId, setpoint, auxSetpoint, pidSlot, rsvd);
            break;
        }
        // Firmware Revision
        case "getFirmwareVersion":
        {
            // Assume this only happens when starting a thing.
            createSim(aDeviceId);
            break;
        }
        default:
            sLOGGER.log(Level.DEBUG, "Unsupported option " + arbAsString + "(" + aApiId + ")");
            break;
        }

        return output;
    }

    protected int handleRead(int aDeviceId, int aApiId, ByteBuffer aBuffer)
    {
        int output = 0;

        String arbAsString = mArbIdLookup.get(aApiId);
        if (arbAsString == null)
        {
            sLOGGER.log(Level.ERROR, "Unknown API Id " + aApiId);
            return 1;
        }

        switch (arbAsString) // NOPMD
        {
        // Firmware Revision
        case "getFirmwareVersion":
        {
            sLOGGER.log(Level.DEBUG, "Getting firmware version");
            aBuffer.order(ByteOrder.BIG_ENDIAN);
            aBuffer.rewind();
            aBuffer.put((byte) 1); // Major
            aBuffer.put((byte) 0); // Minor
            aBuffer.putShort((short) 385); // Patch
            aBuffer.put((byte) 0); // Debug
            aBuffer.put((byte) 191); // Hardware Revision
            break;
        }
        default:
            sLOGGER.log(Level.DEBUG, "Unsupported option " + arbAsString + "(" + aApiId + ")");
            break;
        }

        return output;
    }

    protected abstract void createSim(int aDeviceId);

    @SuppressWarnings("PMD.AvoidUsingShortType")
    protected void set(int aDeviceId, float aSetpoint, short aAuxSetpoint, byte aPidSlot, byte aRsvd)
    {
        sLOGGER.log(Level.DEBUG, "Setting " + aAuxSetpoint + ", " + aPidSlot + ", " + aRsvd + ", " + aSetpoint);
    }


}