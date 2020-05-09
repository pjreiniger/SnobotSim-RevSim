
import os
import requests
from zipfile import ZipFile

URL_BASE = "https://www.revrobotics.com/content/sw/max/sdk/maven/com/revrobotics/frc/"

def extract_source_files(version, ctre_source_dir, redownload=False):
    __extract_cci_files(version, ctre_source_dir, redownload)
    __extract_java_files(version, ctre_source_dir, redownload)
#     __extract_java_test_files(version, ctre_source_dir, redownload)
    

def __download_file(url, output_file, redownload):
    myfile = requests.get(url)
    if not os.path.exists(output_file) or redownload:
        print("Downloading {} to {}".format(url, output_file))
        open(output_file, 'wb').write(myfile.content)
        
    return output_file
    
def __extract_java_files(version, ctre_source_dir, redownload):

    print("Extracting java...")
    local_zip_file = __download_file(URL_BASE + "/SparkMax-java/%s/SparkMax-java-%s-sources.jar" % (version, version), "../build/java_zip.jar", redownload)

    files_of_interest = []
        
    with ZipFile(local_zip_file, 'r') as zib_obj:
        listOfFileNames = zib_obj.namelist()
        for file_in_zip in listOfFileNames:
            if file_in_zip.endswith("JNI.java") or file_in_zip == "com/revrobotics/jni/RevJNIWrapper.java":
                print(file_in_zip)
                zib_obj.extract(file_in_zip, os.path.join(ctre_source_dir, "java/"))

def __extract_cci_files(version, ctre_source_dir, redownload=False):
    
    print("Extracting CCI files")
    local_zip_file = __download_file(URL_BASE + "SparkMax-driver/%s/SparkMax-driver-%s-headers.zip" % (version, version), "../build/cci_zip.jar", redownload)

    files_of_interest = []

    with ZipFile(local_zip_file, 'r') as zib_obj:
        listOfFileNames = zib_obj.namelist()
        for file_in_zip in listOfFileNames:
            zib_obj.extract(file_in_zip, os.path.join(ctre_source_dir, "native/include/"))

