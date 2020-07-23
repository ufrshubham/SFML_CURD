########################################################################
# @file create_new_class.py
# @author Shubham Kamble (ufrshubham@gmail.com)
# @brief This script takes an command line argument as class name and
#        creates required .cpp and .hpp file. It also modifies the 
#        src/CMakeLists.txt so that these new files will be added to build.
#        It is designed to be called by 'Create new class' defined in task.json,
#        but can also be called explicitly if needed.
#        If files with given name already exist it will be a no-op.
# @version 0.1
# @date 2020-07-23
# Copyright (c) 2020 Shubham Kamble
########################################################################

import os
import sys
from pathlib import Path

def create_class(class_name : str):
    my_path = Path(os.path.abspath(__file__)).parent

    class_name_cpp = my_path.parent.joinpath(f'src/{class_name}.cpp')
    class_name_hpp = my_path.parent.joinpath(f'include/{class_name}.hpp')

    if class_name_hpp.exists():
        print(f'{class_name_hpp} already exists. Try a different class name.')
    elif class_name_cpp.exists():
        print(f'{class_name_cpp} already exists. Try a different class name.')
    else:
        my_path.parent.joinpath(f'include/{class_name}.hpp').touch()
        print(f'Created include/{class_name}.hpp')

        my_path.parent.joinpath(f'src/{class_name}.cpp').touch()
        print(f'Created src/{class_name}.cpp')

        write_lines = []
        hpp_line_number = 0
        cpp_line_number = 0

        with my_path.parent.joinpath('src/CMakeLists.txt').open('r') as cmake_file:
            lines = cmake_file.readlines()
            for i in range(len(lines)):
                line = lines[i]
                write_lines.append(line)
                if '.hpp' in line:
                    hpp_line_number = i
                elif '.cpp' in line:
                    cpp_line_number = i

        with my_path.parent.joinpath('src/CMakeLists.txt').open('w') as cmake_file:
            for i in range(len(write_lines) + 2):
                if i == hpp_line_number:
                    write_lines.insert(hpp_line_number+1, f"                ${{include_dir}}/{class_name}.hpp\n")
                    print(f'Added {class_name}.hpp in CMakeLists.txt')
                elif i == cpp_line_number:
                    write_lines.insert(cpp_line_number+2, f"                {class_name}.cpp\n")
                    print(f'Added {class_name}.cpp in CMakeLists.txt')

                cmake_file.write(write_lines[i])


if __name__ == '__main__':
    if len(sys.argv) == 2:
        create_class(sys.argv[1])