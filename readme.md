# SFML CURD

## A simple CURD app using Sqlite and SFML

---

### Third Party Libraries

1. [SFML](https://www.sfml-dev.org/) : A simple and fast multimedia library

2. [TGUI](https://github.com/texus/TGUI/) : An easy to use cross-platform c++ GUI for SFML

3. [SQlite3](https://sqlite.org/) : A small, fast, self-contained, high-reliability, full-featured, SQL database engine.

### Dependencies

1. libudev-dev

2. libopenal-dev

3. libvorbis-dev

4. libflac-dev

5. libxrandr-dev

6. libfreetype6-dev

### Automated initial setup

- Note if you have already cloned this repo without reading these instructions you can run **perform_initial_setup.py** located under scripts/ directory to pull the sub-modules.
- To install all the dependencies, run **install_dep.py** located under scripts/ directory. This script is tested only on Linux platform with apt.
- If this script works for you, then you will only have to run `cmake ..` from build directory to build this project.

### Build instructions 

1. Clone this repository using `git clone --recurse-submodules https://github.com/ufrshubham/SFML_CURD.git`

2. Change directory to cloned folder. For most cases this will be 
    - `cd SFML_CURD`

3. Ignore this step if you have already used **perform_initial_setup.py** located under scripts/ directory. Make sure that SFML build generates static libs. For this go to **CMakeLists.txt** located under sfml directory (SFML_CURD/sfml/) and set **BUILD_SHARED_LIBS** to FALSE. Like so,
    - `sfml_set_option(BUILD_SHARED_LIBS FALSE BOOL "TRUE to build SFML as shared libraries, FALSE to build it as static libraries")`

4. Ignore this step if you have already used **perform_initial_setup.py** located under scripts/ directory. Make sure that TGUI build generates static libs. For this go to **CMakeLists.txt** located under tgui directory (SFML_CURD/tgui/) and set **TGUI_SHARED_LIBS** to FALSE. Like so,
    - `tgui_set_option(TGUI_SHARED_LIBS FALSE BOOL "TRUE to build TGUI as a shared library, FALSE to build it as a static library")`

5. If you are on Windows platform, make sure that you are compiling TGUI with C++17. This can be done by setting TGUI_CXX_STANDARD to "17" in **tgui/CMakeLists.txt**. Like this,
    - `tgui_set_option(TGUI_CXX_STANDARD "17" STRING "C++ standard version to build TGUI with. Possible values: 14, 17 or 20. Projects using TGUI must use a version equal or higher to this")`

6. Change directory to build folder (create if not already present using `mkdir build`). Note that this step is totally optional. You can run the cmake command directly from the project root. But this will fill the root with many cmake specific stuff which is of no use to you.
    - `cd build`

7. Run `cmake ..` to generate makefile. Don't forget the `..`
    - You can also use cmake generator to generate project file for your IDE using `cmake -G <generator-name>`. To check the avaliable generators run `cmake -h`

8. Run `make` command to generate the executable named **sfml-sqlite** under **build/src/**

### Setting up development environment

1. Download [VS Code](https://code.visualstudio.com/)

2. Install these extensions

    - [C/C++](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools) Launch VS Code Quick Open (Ctrl+P), paste the following command, and press enter.
        - `ext install ms-vscode.cpptools`

    - [CMake Tools](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools) Launch VS Code Quick Open (Ctrl+P), paste the following command, and press enter.
        - `ext install ms-vscode.cmake-tools`

3. Now clone this repository and open it in VS Code.
    - `git clone --recurse-submodules https://github.com/ufrshubham/SFML_CURD.git`
    - `code SFML_CURD/`

4. Ignore this step if you have already used **perform_initial_setup.py** located under scripts/ directory. Make sure that SFML build generates static libs. For this go to **CMakeLists.txt** located under sfml directory (SFML_CURD/sfml/) and set **BUILD_SHARED_LIBS** to FALSE. Like so,
    - `sfml_set_option(BUILD_SHARED_LIBS FALSE BOOL "TRUE to build SFML as shared libraries, FALSE to build it as static libraries")`

5. Ignore this step if you have already used **perform_initial_setup.py** located under scripts/ directory. Make sure that TGUI build generates static libs. For this go to **CMakeLists.txt** located under tgui directory (SFML_CURD/tgui/) and set **TGUI_SHARED_LIBS** to FALSE. Like so,
    - `tgui_set_option(TGUI_SHARED_LIBS FALSE BOOL "TRUE to build TGUI as a shared library, FALSE to build it as a static library")`

6. If you are on Windows platform, make sure that you are compiling TGUI with C++17. This can be done by setting TGUI_CXX_STANDARD to "17" in **tgui/CMakeLists.txt**. Like this,
    - `tgui_set_option(TGUI_CXX_STANDARD "17" STRING "C++ standard version to build TGUI with. Possible values: 14, 17 or 20. Projects using TGUI must use a version equal or higher to this")`

7. Open command palette (Ctrl + Shift + P) and run **CMake Configure**. This will make necessary configurations for cmake.

8. Open command palette (Ctrl + Shift + P) and run **CMake Build**. This will build the project.

9. Open command palette (Ctrl + Shift + P) and run **CMake Debug**. This will run the project in debug mode.

### Note

- I am still new to CMake, so there is a good chance that above step will not work.

---

- Files under *cmake_modules/* and all the submodules are not covered under license for this project.
- This project is actively developed and tested on 64-bit Linux platform (Linux Mint to be precise) with Visual Studio Code.
- For more queries about this repo feel free to shoot an email on ufrshubham@gmail.com
- For more details about SFML head over to their [offical webpage](https://www.sfml-dev.org/).
- For more details about TGUI head over to their [GitHub page](https://github.com/texus/TGUI/).
- For more details about SQlite head over to their [offical webpage](https://sqlite.org/).

---
