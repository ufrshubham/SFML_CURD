########################################################################
# @file perform_initial_setup.py
# @author Shubham Kamble (ufrshubham@gmail.com)
# @brief This will help init/update all the submodules required for this project.
#        Additionally it also makes changes to the CMakeLists.txt files of these
#        submodules to link them statically.
#        Make sure to run CMake::Configure after running this script.
# @version 0.1
# @date 2020-07-23
# Copyright (c) 2020 Shubham Kamble
########################################################################

import os
import subprocess
from pathlib import Path

def main():
    my_path = Path(os.path.abspath(__file__)).parent

    if my_path.joinpath('.do_not_delete').exists():
        print("\ngit pull --recurse-submodules")
        subprocess.call([
            "git",
            "pull",
            "--recurse-submodules"
        ])

        print("\ngit submodule foreach git fetch origin; git checkout $(git rev-parse --abbrev-ref HEAD); git reset --hard origin/$(git rev-parse --abbrev-ref HEAD); git submodule update --recursive; git clean -dfx")
        subprocess.call([
            "git",
            "submodule",
            "foreach",
            "git fetch origin; git checkout $(git rev-parse --abbrev-ref HEAD); git reset --hard origin/$(git rev-parse --abbrev-ref HEAD); git submodule update --recursive; git clean -dfx"
        ])
    else:
        print('\ngit submodule update --init --recursive --remote')
        subprocess.call(["git", "submodule", "update", "--init", "--recursive", "--remote"])
        my_path.joinpath('.do_not_delete').open('w').close()
    
    lines_to_write = []
    with open(my_path.parent.joinpath('vendor/sfml/CMakeLists.txt'), 'r') as cmake_file:
        for line in cmake_file.readlines():
            if 'sfml_set_option(BUILD_SHARED_LIBS TRUE BOOL' in line:
                lines_to_write.append(line.replace('TRUE BOOL', 'FALSE BOOL'))
            else:
                lines_to_write.append(line)

    with open(my_path.parent.joinpath('vendor/sfml/CMakeLists.txt'), 'w') as cmake_file:
        print('\nModifying CMakeLists.txt for SFML to build static libs.')
        cmake_file.writelines(lines_to_write)
        print(lines_to_write)
    
    lines_to_write = []
    with open(my_path.parent.joinpath('vendor/tgui/CMakeLists.txt'), 'r') as cmake_file:
        for line in cmake_file.readlines():
            if 'tgui_set_option(TGUI_SHARED_LIBS TRUE BOOL' in line:
                lines_to_write.append(line.replace('TRUE BOOL', 'FALSE BOOL'))
            elif 'tgui_set_option(TGUI_CXX_STANDARD "14" STRING' in line:
                lines_to_write.append(line.replace('"14"', '"17"'))
            else:
                lines_to_write.append(line)

    with open(my_path.parent.joinpath('vendor/tgui/CMakeLists.txt'), 'w') as cmake_file:
        print('\nModifying CMakeLists.txt for TGUI to build static libs.')
        cmake_file.writelines(lines_to_write)
        print(lines_to_write)
    
    if not my_path.parent.joinpath('build').exists():
        print('\nCreating build directory.')
        my_path.parent.joinpath('build').mkdir()

    print("\nNow cd into build directory and run 'cmake ..' without quotes.")


if __name__ == '__main__':
    main()
