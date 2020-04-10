import subprocess
import os
import re
import collections
import shutil


def create_tests(jar_path):
    output_dir = "build/tempCreateTests"
    if os.path.exists(output_dir):
        shutil.rmtree(output_dir)
        
    os.makedirs(output_dir)
    os.chdir(output_dir)
    
    print(jar_path)

    classes = collections.defaultdict(list)
    classes["analog"].append(("com/revrobotics/CANAnalog.class", ANALOG_HEADER))
    classes["digitalInput"].append(("com/revrobotics/CANDigitalInput.class", DIGITAL_INPUT_HEADER))
    classes["encoder"].append(("com/revrobotics/CANEncoder.class", ENCODER_HEADER))
    classes["spark"].append(("com/revrobotics/CANSparkMax.class", SPARK_HEADER))
    classes["spark"].append(("com/revrobotics/CANSparkMaxLowLevel.class", SPARK_LOW_LEVEL_HEADER))
    classes["pid"].append(("com/revrobotics/CANPIDController.class", CAN_PID_HEADER))

    unzip_args = []
    unzip_args.append(JAVA_PATH + r'\bin\jar')
    unzip_args.append("xf")
    unzip_args.append(jar_path)

    for class_list in classes.values():
        for clazz, _ in class_list:
            unzip_args.append(clazz)

    print subprocess.call(unzip_args)
    
    known_classes = ["ExternalFollower", "CANSparkMax",]

    for key in classes:
        for clazz, header_template in classes[key]:
            run_javap(key, clazz, known_classes, header_template)


def prepare_variable_name(in_name):

    outname = in_name.replace("LED", "led")
    outname = outname.replace("CAN", "can")

    lower_first_char = lambda s: s[:1].lower() + s[1:] if s else ''
    outname = lower_first_char(outname)

    return outname


def run_javap(objName, class_file, known_classes, header_template):
    
    print("File %s ---------------------" % class_file)
    output_file = "Test%sFunctions" % class_file.split('/')[-1][:-6]
    output_file = os.path.join("%s/src/test/java/com/snobot/simulator/rev/%s.java" % (os.path.dirname(os.path.realpath(__file__)), output_file))
    print(class_file)
    print(output_file)

    javap_args = []
    javap_args.append(JAVA_PATH + r'\bin\javap')
    javap_args.append(class_file)
    print(" ".join(javap_args))
    p = subprocess.Popen(javap_args, stdout=subprocess.PIPE, stderr=subprocess.PIPE)

    stdout, stderr = p.communicate()
    if p.returncode != 0:
        raise Exception("Failed to parse library %s" % stderr)
    print(stderr)
    print("Returned with %s" % p.returncode)

    tests = ""

    for line in stdout.split("\n"):
        matches = re.findall("  public .* (.*)\((.*)\)", line)
        if len(matches) != 0:
            matches = matches[0]
            func = matches[0]
            args = matches[1].split(",")
            arg_replacement = []

            enumerations = []

            if type(args) == list:
                for a in args:
                    a = a.strip()
                    if a == "int" or a == "double":
                        arg_replacement.append("0")
                    elif a == "boolean":
                        arg_replacement.append("false")
                    elif a != "":
                        stripped_name = a[a.rfind(".") + 1:]
                        if "$" in stripped_name:
                            stripped_name = stripped_name[stripped_name.rfind("$") + 1:]

                        if stripped_name in known_classes:
                            arg_replacement.append("new %s()" % stripped_name)
                        else:
                            enumerations.append(stripped_name)
                            arg_replacement.append(prepare_variable_name(stripped_name))

            if len(enumerations) == 0:
                tests += "        %s.%s(%s);\n" % (objName, func, ", ".join(arg_replacement))
            else:
                indent = "        "
                tests += dump_enemerate(iter(enumerations), indent, ", ".join(arg_replacement), objName, func, arg_replacement)


    with(open(output_file, 'w')) as f:
        f.write(header_template)
        f.write(tests) 
        f.write("\n}\n")
#     print tests

def dump_enemerate(enumeration_iter, indent, args, objName, func, arg_replacement):
    
    def safe_get_next(enumeration_iter):
        try:
            n = next(enumeration_iter)
            return True, n
        except StopIteration:
            return False, None
    
    tests = ""
    valid, enum = safe_get_next(enumeration_iter)
    if valid:
        print(indent, "DUMPING ENUM ", enum, args)
        var_name = prepare_variable_name(enum)
        tests += "{indent}for ({enum} {var_name} : {enum}.values())".format(**locals()) 
        tests += "\n%s{\n" % indent
        tests += dump_enemerate(enumeration_iter, indent + "    ", args, objName, func, arg_replacement)
        tests += "{indent}}}\n".format(**locals())
    else:
        tests += "%s%s.%s(%s);\n" % (indent, objName, func, ", ".join(arg_replacement))
        
    return tests

def dump_single_test(indent, objName, func, arg_replacement, enumerations):
    tests = ""
    args=", ".join(arg_replacement)
    if len(enumerations) == 0:
        tests += "        {objName}.{func}({args});\n".format(**locals())
    else:
        
        enumeration_iter = iter(enumerations)
        dump_enemerate(enumeration_iter, indent, args, objName, func, arg_replacement)
        
    return tests


JAVA_PATH = r'C:\Users\Public\wpilib\2020\jdk'
LIB_VERSION = "1.5.0"
LIB_HASH = "ba053d9ffd562952235ddee363545b2c702c6bb8"
ARTIFACT_PACKAGE = "com.revrobotics.frc"
ARTIFACT_NAME = "SparkMax-java"
M2_DIRECTORY = r'C:\Users\PJ\.gradle\caches\modules-2\files-2.1'

ANALOG_HEADER = """package com.snobot.simulator.rev;

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
            // Nothing to do
        }
    };

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

    @Test
    public void testAnnalogFunctions()
    {
        CANSparkMax sc = new CANSparkMax(11, MotorType.kBrushless);

"""

DIGITAL_INPUT_HEADER = """package com.snobot.simulator.rev;

import java.nio.ByteBuffer;

import org.junit.Before;
import org.junit.Test;

import com.revrobotics.CANDigitalInput;
import com.revrobotics.CANDigitalInput.LimitSwitchPolarity;
import com.revrobotics.CANSparkMax;
import com.revrobotics.CANSparkMaxLowLevel.MotorType;

public class TestCANDigitalInputFunctions
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
        // System.loadLibrary("wpiutil");
        // System.loadLibrary("wpiHal");
        // System.loadLibrary("wpiHaljni");
        //
        // HAL.initialize(0, 0);

        System.loadLibrary("SparkMaxDriver");

        RevSimJni.registerRevCallback(mRevCallback);

    }

    @Test
    public void testLimitSwitchFunctions()
    {
        CANSparkMax sc = new CANSparkMax(11, MotorType.kBrushless);

"""

ENCODER_HEADER = """package com.snobot.simulator.rev;

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
            // Nothing to do
        }
    };

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

    @Test
    public void testEncoderFunctions()
    {
        CANSparkMax sc = new CANSparkMax(12, MotorType.kBrushless);
        CANEncoder encoder = sc.getEncoder();
"""

SPARK_HEADER = """package com.snobot.simulator.rev;

import java.nio.ByteBuffer;

import org.junit.Before;
import org.junit.Test;

import com.revrobotics.AlternateEncoderType;
import com.revrobotics.CANAnalog.AnalogMode;
import com.revrobotics.CANDigitalInput.LimitSwitchPolarity;
import com.revrobotics.CANSparkMax;
import com.revrobotics.CANSparkMax.ExternalFollower;
import com.revrobotics.CANSparkMax.FaultID;
import com.revrobotics.CANSparkMax.IdleMode;
import com.revrobotics.CANSparkMax.SoftLimitDirection;
import com.revrobotics.CANSparkMaxLowLevel.MotorType;
import com.revrobotics.EncoderType;

public class TestCANSparkMax
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
        // System.loadLibrary("wpiutil");
        // System.loadLibrary("wpiHal");
        // System.loadLibrary("wpiHaljni");
        //
        // HAL.initialize(0, 0);

        System.loadLibrary("SparkMaxDriver");

        RevSimJni.registerRevCallback(mRevCallback);

    }

    @SuppressWarnings({ "PMD.NcssCount", "PMD.DataflowAnomalyAnalysis", "PMD.ExcessiveMethodLength", "PMD.CyclomaticComplexity", "PMD.NPathComplexity" })
    @Test
    public void testUnsupportedOperations()
    {
        CANSparkMax spark = new CANSparkMax(10, MotorType.kBrushless);
        CANSparkMax follower = new CANSparkMax(11, MotorType.kBrushed);
        ExternalFollower externalFollower = new ExternalFollower(15, 0);


       
        spark
"""

SPARK_LOW_LEVEL_HEADER = """package com.snobot.simulator.rev;

import java.nio.ByteBuffer;

import org.junit.Before;
import org.junit.Test;

import com.revrobotics.AlternateEncoderType;
import com.revrobotics.CANAnalog.AnalogMode;
import com.revrobotics.CANDigitalInput.LimitSwitchPolarity;
import com.revrobotics.CANSparkMax;
import com.revrobotics.CANSparkMax.ExternalFollower;
import com.revrobotics.CANSparkMax.FaultID;
import com.revrobotics.CANSparkMax.IdleMode;
import com.revrobotics.CANSparkMax.SoftLimitDirection;
import com.revrobotics.CANSparkMaxLowLevel.MotorType;
import com.revrobotics.EncoderType;

public class TestCANSparkMaxLowLevel
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
        // System.loadLibrary("wpiutil");
        // System.loadLibrary("wpiHal");
        // System.loadLibrary("wpiHaljni");
        //
        // HAL.initialize(0, 0);

        System.loadLibrary("SparkMaxDriver");

        RevSimJni.registerRevCallback(mRevCallback);

    }

    @SuppressWarnings({ "PMD.NcssCount", "PMD.DataflowAnomalyAnalysis", "PMD.ExcessiveMethodLength", "PMD.CyclomaticComplexity", "PMD.NPathComplexity" })
    @Test
    public void testUnsupportedOperations()
    {
        CANSparkMax spark = new CANSparkMax(10, MotorType.kBrushless);
        CANSparkMax follower = new CANSparkMax(11, MotorType.kBrushed);
        ExternalFollower externalFollower = new ExternalFollower(15, 0);


"""

CAN_PID_HEADER = """package com.snobot.simulator.rev;

import java.nio.ByteBuffer;

import org.junit.Before;
import org.junit.Test;

import com.revrobotics.CANEncoder;
import com.revrobotics.CANPIDController;
import com.revrobotics.CANPIDController.AccelStrategy;
import com.revrobotics.CANPIDController.ArbFFUnits;
import com.revrobotics.CANSparkMax;
import com.revrobotics.CANSparkMaxLowLevel.MotorType;
import com.revrobotics.ControlType;

public class TestCANPIDController
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
        // System.loadLibrary("wpiutil");
        // System.loadLibrary("wpiHal");
        // System.loadLibrary("wpiHaljni");
        //
        // HAL.initialize(0, 0);

        System.loadLibrary("SparkMaxDriver");

        RevSimJni.registerRevCallback(mRevCallback);

    }

    @SuppressWarnings("PMD.NcssCount")
    @Test
    public void testPidFunctions()
    {
        CANSparkMax sc = new CANSparkMax(12, MotorType.kBrushless);
        CANPIDController pid = new CANPIDController(sc);

"""

# classes["analog"].append("com/revrobotics/CANAnalog.class")
# classes["digitalInput"].append("com/revrobotics/CANDigitalInput.class")
# classes["encoder"].append("com/revrobotics/CANEncoder.class")
# classes["spark"].append("com/revrobotics/CANSparkMax.class")
# classes["spark"].append("com/revrobotics/CANSparkMaxLowLevel.class")
# classes["pid"].append("com/revrobotics/CANPIDController.class")

create_tests(
    r'{m2_dir}\{artifact_package}\{artifact_name}\{lib_version}\{lib_hash}/{artifact_name}-{lib_version}.jar'.
    format(
        lib_hash=LIB_HASH,
        lib_version=LIB_VERSION,
        m2_dir=M2_DIRECTORY,
        artifact_package=ARTIFACT_PACKAGE,
        artifact_name=ARTIFACT_NAME))
