import os
import platform
import subprocess

REG_FILE_NAME = "vscommondir.reg"

def is_64_bit():
    # On linux wine is 32bit
    #return platform.system() == "Windows" and platform.machine() == "AMD64" or platform.machine() == "x86_64"
    return True

def create_reg_file():
    #print(f"architecture: {platform.machine()}")

    CURRENT_DIRECTORY = os.path.dirname(os.path.abspath(__file__))

    # set up the registry key that is required by cmake to detect the compiler
    strKey = ""
    if is_64_bit():
        strKey = "[HKEY_LOCAL_MACHINE\\SOFTWARE\\Wow6432Node\\Microsoft\\VisualStudio\\6.0\\Setup]"
    else:
        strKey = "[HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\VisualStudio\\6.0\\Setup]"
    print(CURRENT_DIRECTORY)
    if CURRENT_DIRECTORY[0] == '/':
        CURRENT_DIRECTORY = "Z:" + CURRENT_DIRECTORY
    print(CURRENT_DIRECTORY)
    vs_common_dir = CURRENT_DIRECTORY + "\\3rdParty" + "\\gta2_re_compile_tools" + "\\Common"
    vs_common_dir = vs_common_dir.replace("/", "\\")
    vs_common_dir = vs_common_dir.replace("\\", "\\\\")

    #print(f"Setting VsCommonDir to: {vs_common_dir}")

    with open(REG_FILE_NAME, "w") as f:
        f.write("Windows Registry Editor Version 5.00\n\n")
        f.write(strKey + "\n")
        f.write("\"VsCommonDir\"=\"" + vs_common_dir + "\"")
        f.write("\n\n")

def import_reg_file():
    if platform.system() == "Windows":
        result = subprocess.run(["reg", "import", REG_FILE_NAME], shell=True, check=True)
    elif platform.system() == "Linux":
        result = subprocess.run(f"wine cmd /c \"reg import {REG_FILE_NAME}\"", shell=True)

    if result.returncode != 0:
        print(f"Failed to import {REG_FILE_NAME}")
    else:
        print(f"Successfully imported {REG_FILE_NAME}")

def main():
    create_reg_file()
    import_reg_file()

if __name__ == "__main__":
    main()
