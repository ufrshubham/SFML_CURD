# SFML CURD

## A simple CURD app using Sqlite and SFML

---

### Setting up your Visual Studio project

1. Clone this repository using `git clone https://github.com/ufrshubham/SFML_CURD.git`

2. Download the SFML libs from [SFML download page.](https://www.sfml-dev.org/download/sfml/2.5.1/) If you are on 64-bit windows platform download **Visual C++ 15 (2017) - 64-bit** version.

3. Extract the downloaded _**sfml-version-platform-ide-arch-bit.zip**_ at some location which does not require administrator rights. Prefer _Extract here_ option.

4. Add a new environment variable named **SFML_PATH** to user variables and set its value as path to the extracted folder from step 3.

5. Copy the *.dll files from the extracted folder to **SFML_CURD/CURD_Sqlite/**

6. From the cloned SFML_CURD folder Launch the **CURD_Sqlite.sln** and build it.

---

### Facing Errors while setting up

1. Applicaiton builds without errors but crashes while running.
    - Make sure that you have copied the dll files from downloaded SFML zip to **SFML_CURD/CURD_Sqlite/**

2. Build errors.
    - Make sure that you have set the SFML_PATH variable correctly. It should be the path to folder which contains _**bin, doc, examples, include and lib**_ folder after extracting the downloaded SFML zip.

    - Make sure that you have set the correct architecture(_x64 or x86_) as the downloaded SFML libs.

---

- This project is actively developed and tested on win-64 platform with Visual Studio 2019.
- For mroe queries about this repo feel free to shoot an email on ufrshubham@gmail.com
- For more details about SFML head over to their [offical webpage](https://www.sfml-dev.org/).

---
