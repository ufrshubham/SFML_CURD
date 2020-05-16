# SFML CURD

## A simple CURD app using Sqlite and SFML

---

### Dependencies
1. [SFML](https://www.sfml-dev.org/)
    - `sudo apt install libsfml-dev`
2. [SQlite3](https://sqlite.org/)
    - `sudo apt install libsqlite3-dev`

### Build instructions

1. Install dependencies using your default package manager. If on Windows or Mac, you are on your own.

2. Clone this repository using `git clone https://github.com/ufrshubham/SFML_CURD.git`

3. Change directory to cloned folder. For most cases this will be 
    - `cd SFML_CURD`

4. Changed directory to build folder. Note that this step is totally optional. You can run the cmake command directly from the project root. But this will fill the root with many cmake specific stuff which is of no use to you.
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
    - `git clone https://github.com/ufrshubham/SFML_CURD.git`
    - `code SFML_CURD/`

4. Open command palette (Ctrl + Shift + P) and run **CMake Configure**. This will make necessary configurations for cmake.

5. Open command palette (Ctrl + Shift + P) and run **CMake Build**. This will build the project.

6. Open command palette (Ctrl + Shift + P) and run **CMake Debug**. This will run the project in debug mode.

### Note

- Right now **SFML** and **SQLite** link dynamically to **sfml-sqlite**. As a result of this, to run the generated executable libsqlite3.so, libsfml-graphics.so, libsfml-window.so and libsfml-system.so needs to be placed in the same directory as the executable.

- In future the linking will be changed to static so that the **sfml-sqlite** becomes independednt.

---

- Files under *cmake_modules/* are not covered under license for this project.
- This project is actively developed and tested on 64-bit Linux platform (Linux Mint to be precise) with Visual Studio Code.
- For more queries about this repo feel free to shoot an email on ufrshubham@gmail.com
- For more details about SFML head over to their [offical webpage](https://www.sfml-dev.org/).
- For more details about SQlite head over to their [offical webpage](https://sqlite.org/).

---
