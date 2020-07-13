# SFML CURD

## A simple CURD app using Sqlite and SFML

---

### Dependencies

1. [SFML](https://www.sfml-dev.org/)

2. [SQlite3](https://sqlite.org/)

3. libudev-dev

4. libopenal-dev

5. libvorbis-dev

6. libflac-dev

7. libxrandr-dev

8. libfreetype6-dev

### Build instructions

1. Clone this repository using `git clone --recurse-submodules https://github.com/ufrshubham/SFML_CURD.git`

2. Change directory to cloned folder. For most cases this will be 
    - `cd SFML_CURD`

3. Make sure that SFML build generates static libs. For this go to **CMakeLists.txt** located under sfml directory (SFML_CURD/sfml/) and set **BUILD_SHARED_LIBS** to FALSE. Like so,
    - `sfml_set_option(BUILD_SHARED_LIBS FALSE BOOL "TRUE to build SFML as shared libraries, FALSE to build it as static libraries")`

4. Change directory to build folder (create if not already present using `mkdir build`). Note that this step is totally optional. You can run the cmake command directly from the project root. But this will fill the root with many cmake specific stuff which is of no use to you.
    - `cd build`

5. Run `cmake ..` to generate makefile. Don't forget the `..`
    - You can also use cmake generator to generate project file for your IDE using `cmake -G <generator-name>`. To check the avaliable generators run `cmake -h`

6. Run `make` command to generate the executable named **sfml-sqlite** under **build/src/**

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

4. Make sure that SFML build generates static libs. For this go to **CMakeLists.txt** located under sfml directory (SFML_CURD/sfml/) and set **BUILD_SHARED_LIBS** to FALSE. Like so,
    - `sfml_set_option(BUILD_SHARED_LIBS FALSE BOOL "TRUE to build SFML as shared libraries, FALSE to build it as static libraries")`

5. Open command palette (Ctrl + Shift + P) and run **CMake Configure**. This will make necessary configurations for cmake.

6. Open command palette (Ctrl + Shift + P) and run **CMake Build**. This will build the project.

7. Open command palette (Ctrl + Shift + P) and run **CMake Debug**. This will run the project in debug mode.

### Note

- I am still new to CMake, so there is a good chance that above step will not work.

---

- Files under *cmake_modules/* and all the submodules are not covered under license for this project.
- This project is actively developed and tested on 64-bit Linux platform (Linux Mint to be precise) with Visual Studio Code.
- For more queries about this repo feel free to shoot an email on ufrshubham@gmail.com
- For more details about SFML head over to their [offical webpage](https://www.sfml-dev.org/).
- For more details about SQlite head over to their [offical webpage](https://sqlite.org/).

---
