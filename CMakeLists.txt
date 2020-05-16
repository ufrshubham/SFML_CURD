# Copyright (c) 2020 - Shubham Kamble

cmake_minimum_required(VERSION 3.17.2)
project(Sfml-Sqlite VERSION 1.0.0)

set (CMAKE_CXX_STANDARD 17)
message(STATUS "Using C++17")

# All header will be in ./include/
set(include_dir ${PROJECT_SOURCE_DIR}/include)
message(STATUS "Setting include dir as ${include_dir}")
include_directories(${include_dir})

# Add all the subdirectories
add_subdirectory(src)
