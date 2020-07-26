########################################################################
# @file perform_initial_setup.py
# @author Shubham Kamble (ufrshubham@gmail.com)
# @brief This script is created for those who do not want to follow the
#        long and complex process of setting up the development environment.
#        When called, this script will clone the SFML submodule under sfml/
#        if not done already, else it will simple pull the latest changes for it.
#        Additionally, it also installs required libs for building this project.
#        This will most be required for Linux and Mac. Right now, only Linux
#        is supported(mostly because I don't access to a Mac) for auto-install of libs.
#        On top of this, only distros with 'apt' are supported.
# @version 0.1
# @date 2020-07-23
# Copyright (c) 2020 Shubham Kamble
########################################################################

import os
import platform
import subprocess
from pathlib import Path

def main():
    my_path = Path(os.path.abspath(__file__)).parent

    if my_path.joinpath('.do_not_delete').exists():
        print('\ngit submodule update --recursive --remote')
        subprocess.call(["git", "submodule", "update", "--recursive", "--remote"])
    else:
        print('\ngit submodule update --init --recursive --remote')
        subprocess.call(["git", "submodule", "update", "--init", "--recursive", "--remote"])
    
    if platform.system() == 'Linux':
        try:
            print("\nsudo apt install libudev-dev libopenal-dev libvorbis-dev libflac-dev libxrandr-dev libfreetype6-dev")
            subprocess.call(["sudo", "apt", "install", "libudev-dev", "libopenal-dev", "libvorbis-dev", "libflac-dev", "libxrandr-dev", "libfreetype6-dev"])
        except Exception:
            print('\nOnly apt package manager is supported right now.')
    
    lines_to_write = []
    with open(my_path.parent.joinpath('sfml/CMakeLists.txt'), 'r') as cmake_file:
        for line in cmake_file.readlines():
            if 'sfml_set_option(BUILD_SHARED_LIBS TRUE BOOL' in line:
                lines_to_write.append(line.replace('TRUE BOOL', 'FALSE BOOL'))
            else:
                lines_to_write.append(line)

    with open(my_path.parent.joinpath('sfml/CMakeLists.txt'), 'w') as cmake_file:
        print('\nModifying CMakeLists.txt for SFML to build static libs.')
        cmake_file.writelines(lines_to_write)
    
    lines_to_write = []
    with open(my_path.parent.joinpath('tgui/CMakeLists.txt'), 'r') as cmake_file:
        for line in cmake_file.readlines():
            if 'tgui_set_option(TGUI_SHARED_LIBS TRUE BOOL' in line:
                lines_to_write.append(line.replace('TRUE BOOL', 'FALSE BOOL'))
            else:
                lines_to_write.append(line)

    with open(my_path.parent.joinpath('tgui/CMakeLists.txt'), 'w') as cmake_file:
        print('\nModifying CMakeLists.txt for TGUI to build static libs.')
        cmake_file.writelines(lines_to_write)
    
    if not my_path.parent.joinpath('build').exists():
        print('\nCreating build directory.')
        my_path.parent.joinpath('build').mkdir()

    print("\nNow cd into build directory and run 'cmake ..' without quotes.")


if __name__ == '__main__':
    main()
