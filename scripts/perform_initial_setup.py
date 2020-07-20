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
    
    if not my_path.parent.joinpath('build').exists():
        print('\nCreating build directory.')
        my_path.parent.joinpath('build').mkdir()

    print("\nNow cd into build directory and run 'cmake ..' without quotes.")


if __name__ == '__main__':
    main()
