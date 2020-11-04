# Copyright (c) 2020 - Shubham Kamble

set(TODO_PLUS_PLUS_SOURCE_FILES
    Application.cpp
    CommonStrings.cpp
    DatabaseManager.cpp
    main.cpp
    Task.cpp)

set(TODO_PLUS_PLUS_HEADER_FILES
    ../include/Application.hpp
    ../include/CommonStrings.hpp
    ../include/DatabaseManager.hpp
    ../include/Task.hpp)

add_executable(Todo-Plus-Plus ${TODO_PLUS_PLUS_SOURCE_FILES} ${TODO_PLUS_PLUS_HEADER_FILES})

set_target_properties(Todo-Plus-Plus PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED YES)

target_include_directories(Todo-Plus-Plus PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include/  
                                               ${CMAKE_CURRENT_SOURCE_DIR}/../vendor/elements/lib/include/
                                               ${CMAKE_CURRENT_SOURCE_DIR}/../vendor/sqlite/)

target_link_libraries(Todo-Plus-Plus elements sqlite3)
