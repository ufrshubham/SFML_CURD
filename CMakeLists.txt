# Copyright (c) 2020 - Shubham Kamble

<<<<<<< HEAD
cmake_minimum_required(VERSION 3.10.0)
project(Sqlite-Sfml VERSION 1.0.0)
=======
cmake_minimum_required(VERSION 3.17.0)
project(Sfml-Sqlite VERSION 1.0.0)
>>>>>>> 00394366a5f0ce2250d1ec310bf6585da314820b

set (CMAKE_CXX_STANDARD 17)
message(STATUS "Using C++17")

# Add all the subdirectories
add_subdirectory(sfml)
add_subdirectory(sqlite)
add_subdirectory(src)
