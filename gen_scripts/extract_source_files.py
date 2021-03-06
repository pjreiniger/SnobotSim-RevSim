import os
import requests
from zipfile import ZipFile

URL_BASE = "https://www.revrobotics.com/content/sw/max/sdk/maven/com/revrobotics/frc/"


def extract_source_files(version, original_source_dir, redownload=False):
    __extract_cci_files(version, original_source_dir, redownload)
    __extract_java_files(version, original_source_dir, redownload)
    __extract_java_test_files(version, original_source_dir, redownload)


def __download_file(url, output_file, redownload):
    myfile = requests.get(url)
    if not os.path.exists(output_file) or redownload:
        print("Downloading {} to {}".format(url, output_file))
        open(output_file, 'wb').write(myfile.content)

    return output_file


def __extract_java_files(version, original_source_dir, redownload):

    print("Extracting java...")
    local_zip_file = __download_file(URL_BASE + "/SparkMax-java/%s/SparkMax-java-%s-sources.jar" % (version, version), "../build/java_zip.jar", redownload)

    files_of_interest = []
    files_of_interest.append("com/revrobotics/jni/RevJNIWrapper.java")

    with ZipFile(local_zip_file, 'r') as zib_obj:
        listOfFileNames = zib_obj.namelist()
        for file_in_zip in listOfFileNames:
            should_unzip = False
            if file_in_zip.endswith("JNI.java"):
                print(file_in_zip)
                should_unzip = True
            elif file_in_zip in files_of_interest:
                should_unzip = True

            if should_unzip:
                zib_obj.extract(file_in_zip, os.path.join(original_source_dir, "java/"))


def __extract_java_test_files(version, original_source_dir, redownload):

    print("Extracting test java...")
    local_zip_file = __download_file(URL_BASE + "/SparkMax-java/%s/SparkMax-java-%s-sources.jar" % (version, version), "../build/java_zip.jar", redownload)

    files_of_interest = []
    files_of_interest.append("com/revrobotics/CANAnalog.java")
    files_of_interest.append("com/revrobotics/CANDigitalInput.java")
    files_of_interest.append("com/revrobotics/CANEncoder.java")
    files_of_interest.append("com/revrobotics/CANSparkMax.java")
    files_of_interest.append("com/revrobotics/CANSparkMaxLowLevel.java")
    files_of_interest.append("com/revrobotics/CANPIDController.java",)

    with ZipFile(local_zip_file, 'r') as zib_obj:
        listOfFileNames = zib_obj.namelist()
        for file_in_zip in listOfFileNames:
            should_unzip = file_in_zip in files_of_interest

            if should_unzip:
                print(file_in_zip)
                zib_obj.extract(file_in_zip, os.path.join(original_source_dir, "../build/tmp/test_files/"))


def __extract_cci_files(version, original_source_dir, redownload=False):

    print("Extracting CCI files")
    local_zip_file = __download_file(URL_BASE + "SparkMax-driver/%s/SparkMax-driver-%s-headers.zip" % (version, version), "../build/cci_zip.jar", redownload)

    files_of_interest = []

    with ZipFile(local_zip_file, 'r') as zib_obj:
        listOfFileNames = zib_obj.namelist()
        for file_in_zip in listOfFileNames:
            zib_obj.extract(file_in_zip, os.path.join(original_source_dir, "native/include/"))
