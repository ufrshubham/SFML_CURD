########################################################################
# @file install_dep.py
# @author Shubham Kamble (ufrshubham@gmail.com)
# @brief This script installs all the required dependencies for this project.
#        Right now it only works on Linux platform with apt package manager.
# @version 0.1
# @date 2020-08-03
# Copyright (c) 2020 Shubham Kamble
########################################################################

import platform
import subprocess

def main():
    if platform.system() == 'Linux':
        try:
            print("\nsudo apt install libudev-dev libopenal-dev libvorbis-dev libflac-dev libxrandr-dev libfreetype6-dev libx11-dev")
            subprocess.call(["sudo", "apt", "install", "libudev-dev", "libopenal-dev", "libvorbis-dev", "libflac-dev", "libxrandr-dev", "libfreetype6-dev", "libx11-dev"])
        except Exception:
            print('\nOnly apt package manager is supported right now.')

if __name__ == '__main__':
    main()
