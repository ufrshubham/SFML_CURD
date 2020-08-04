# Copyright (c) 2020 - Shubham Kamble

cmake_minimum_required(VERSION 3.10.0)
project(Sqlite-Sfml VERSION 1.0.0)
set (CMAKE_CXX_STANDARD 17)
message(STATUS "Using C++17")

# Add all the subdirectories
add_subdirectory(vendor/sfml)
add_subdirectory(vendor/sqlite)
add_subdirectory(vendor/tgui)
add_subdirectory(src)
