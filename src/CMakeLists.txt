# Copyright (c) 2020 - Shubham Kamble

# Set path to all the Find.cmake files
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

# Set SFML_DIR so that find_package() will find SFMLConfig.cmake there
set(SFML_DIR ${PROJECT_BINARY_DIR}/vendor/sfml/)

# SFML related stuff
# If you want to link statically to sfml uncomment this line
set(SFML_STATIC_LIBRARIES TRUE)

# This section is not needed now, because SFML and SQlite will be build from scratch.
############################################################################
# SFML has changed the way to find sfml from 2.5 and onwards.
# FindSFML.cmake present in cmake_modules will not work.
# If you have SFML 2.5 or late remove the Detect and add SFML section 
# and uncomment the below line.
# find_package(SFML 2.5 COMPONENTS graphics window system)

# Detect and add Sqlite3
# find_package(SQLITE3 REQUIRED)
############################################################################

# All header will be in ./include/
set(include_dir ${PROJECT_SOURCE_DIR}/include)

include_directories(
                        ${include_dir}
                         ${PROJECT_SOURCE_DIR}/vendor/sfml/include 
                         ${PROJECT_SOURCE_DIR}/vendor/sqlite
                         ${PROJECT_SOURCE_DIR}/vendor/tgui/include
                    )

# Main target
add_executable(sqlite-sfml 
                ${include_dir}/DatabaseManager.hpp 
                ${include_dir}/Task.hpp
                ${include_dir}/Application.hpp
                ${include_dir}/CommonStrings.hpp
                main.cpp 
                DatabaseManager.cpp
                Task.cpp
                Application.cpp
                CommonStrings.cpp
                )

# Link with required libraries
target_link_libraries(sqlite-sfml sfml-graphics sfml-window sfml-system sqlite3 tgui)