# Copyright (c) 2020 - Shubham Kamble

# SFML related stuff
# If you wan to link statically to sfmlm uncomment this line
# set(SFML_STATIC_LIBRARIES TRUE)

# SFML has changed the way to find sfml from 2.5 and onwards.
# FindSFML.cmake present in cmake_modules will not work.
# If you have SFML 2.5 or late remove the Detect and add SFML section 
# and uncomment the below line.
# find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

# Set path to all the Find.cmake files
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

# Detect and add SFML
find_package(SFML 2.4 REQUIRED system window graphics network audio)

# Detect and add Sqlite3
find_package(SQLITE3 REQUIRED)

# Main target
add_executable(sfml-sqlite
                ${include_dir}/DatabaseManager.hpp 
                main.cpp 
                DatabaseManager.cpp)

# Link with required libraries
target_link_libraries(sfml-sqlite sfml-graphics sfml-window sfml-system sqlite3)