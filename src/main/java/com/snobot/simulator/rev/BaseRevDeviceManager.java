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

            sLOGGER.log(Level.TRACE, "Getting send: Message ID: 0x" + Integer.toHexString(aMessageId) + " -> Device ID: " + deviceId + ", API Id: "
                    + apiId + ", Manufacturer: " + manufacturer + ", Device Type: " + deviceType);

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

    protected final Map<Integer, String> mArbIdLookup;

    @SuppressWarnings("PMD")
    public BaseRevDeviceManager()
    {
        RevSimJni.registerRevCallback(mRevCallback);

        mArbIdLookup = new HashMap<>();
        mArbIdLookup.put(2, "SetpointOut");
        mArbIdLookup.put(96, "getPeriodicStatus0");
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
        mArbIdLookup.put(824, "getParamterCore(kOpenLoopRampRate)");
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
        mArbIdLookup.put(840, "getParamterCore(kEncoderRsvd0)");
        mArbIdLookup.put(841, "getParamterCore(kEncoderRsvd1)");
        mArbIdLookup.put(842, "getParamterCore(kVoltageCompMode)");
        mArbIdLookup.put(843, "getParamterCore(kCompensatedNominalVoltage)");
        mArbIdLookup.put(844, "getParamterCore(kSmartMotionMaxVelocity_0)");
        mArbIdLookup.put(845, "getParamterCore(kSmartMotionMaxAccel_0)");
        mArbIdLookup.put(846, "getParamterCore(kSmartMotionMinVelOutput_0)");
        mArbIdLookup.put(847, "getParamterCore(kSmartMotionAllowedClosedLoopError_0)");
        mArbIdLookup.put(848, "getParamterCore(kSmartMotionAccelStrategy_0)");
        mArbIdLookup.put(849, "getParamterCore(kSmartMotionMaxVelocity_1)");
        mArbIdLookup.put(850, "getParamterCore(kSmartMotionMaxAccel_1)");
        mArbIdLookup.put(851, "getParamterCore(kSmartMotionMinVelOutput_1)");
        mArbIdLookup.put(852, "getParamterCore(kSmartMotionAllowedClosedLoopError_1)");
        mArbIdLookup.put(853, "getParamterCore(kSmartMotionAccelStrategy_1)");
        mArbIdLookup.put(854, "getParamterCore(kSmartMotionMaxVelocity_2)");
        mArbIdLookup.put(855, "getParamterCore(kSmartMotionMaxAccel_2)");
        mArbIdLookup.put(856, "getParamterCore(kSmartMotionMinVelOutput_2)");
        mArbIdLookup.put(857, "getParamterCore(kSmartMotionAllowedClosedLoopError_2)");
        mArbIdLookup.put(858, "getParamterCore(kSmartMotionAccelStrategy_2)");
        mArbIdLookup.put(859, "getParamterCore(kSmartMotionMaxVelocity_3)");
        mArbIdLookup.put(860, "getParamterCore(kSmartMotionMaxAccel_3)");
        mArbIdLookup.put(861, "getParamterCore(kSmartMotionMinVelOutput_3)");
        mArbIdLookup.put(862, "getParamterCore(kSmartMotionAllowedClosedLoopError_3)");
        mArbIdLookup.put(863, "getParamterCore(kSmartMotionAccelStrategy_3)");
        mArbIdLookup.put(864, "getParamterCore(kIMaxAccum_0)");
        mArbIdLookup.put(865, "getParamterCore(kSlot3Placeholder1_0)");
        mArbIdLookup.put(866, "getParamterCore(kSlot3Placeholder2_0)");
        mArbIdLookup.put(867, "getParamterCore(kSlot3Placeholder3_0)");
        mArbIdLookup.put(868, "getParamterCore(kIMaxAccum_1)");
        mArbIdLookup.put(869, "getParamterCore(kSlot3Placeholder1_1)");
        mArbIdLookup.put(870, "getParamterCore(kSlot3Placeholder2_1)");
        mArbIdLookup.put(871, "getParamterCore(kSlot3Placeholder3_1)");
        mArbIdLookup.put(872, "getParamterCore(kIMaxAccum_2)");
        mArbIdLookup.put(873, "getParamterCore(kSlot3Placeholder1_2)");
        mArbIdLookup.put(874, "getParamterCore(kSlot3Placeholder2_2)");
        mArbIdLookup.put(875, "getParamterCore(kSlot3Placeholder3_2)");
        mArbIdLookup.put(876, "getParamterCore(kIMaxAccum_3)");
        mArbIdLookup.put(877, "getParamterCore(kSlot3Placeholder1_3)");
        mArbIdLookup.put(878, "getParamterCore(kSlot3Placeholder2_3)");
        mArbIdLookup.put(879, "getParamterCore(kSlot3Placeholder3_3)");
        mArbIdLookup.put(880, "getParamterCore(kPositionConversionFactor)");
        mArbIdLookup.put(881, "getParamterCore(kVelocityConversionFactor)");
        mArbIdLookup.put(882, "getParamterCore(kClosedLoopRampRate)");

//         for (ConfigParameter paramter : ConfigParameter.values())
//         {
//            int key = 768 + paramter.value;
//            mArbIdLookup.put(key, "getParamterCore(" + paramter + ")");
//            System.out.println(" mArbIdLookup.put(" + key + ",\"getParamterCore(" + paramter + ")\");");
//         }
    }

    protected void writeFirmwareVersion(ByteBuffer aBuffer)
    {
        sLOGGER.log(Level.DEBUG, "Getting firmware version");
        aBuffer.order(ByteOrder.BIG_ENDIAN);
        aBuffer.rewind();
        aBuffer.putInt(0x101001C); // Major, Minor, Patch
        aBuffer.put((byte) 0); // Debug
        aBuffer.put((byte) 191); // Hardware Revision
    }

    protected abstract int handleRead(int aDeviceId, int aApiId, ByteBuffer aBuffer);

    protected abstract int handleSend(int aDeviceId, int aApiId, ByteBuffer aData);
}
