# Copyright (c) 2020 - Shubham Kamble
cmake_minimum_required(VERSION 3.10.0)
project(Todo-Plus-Plus VERSION 1.0.0)

add_compile_definitions(SFML_STATIC)

option(ELEMENTS_BUILD_EXAMPLES "build Elements library examples" ON)

# Add all the subdirectories
add_subdirectory(vendor/elements)
add_subdirectory(vendor/sqlite)
add_subdirectory(src)
