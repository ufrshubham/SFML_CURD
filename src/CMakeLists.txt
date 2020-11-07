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

# target_link_directories(Todo-Plus-Plus PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../vendor/elements/lib/external/)

if (CMAKE_SIZEOF_VOID_P EQUAL 8) # 64 bits?
set(CAIRO_DLL ${CMAKE_CURRENT_SOURCE_DIR}/../vendor/elements/lib/external/cairo/lib/x64/cairo.dll)
set(FREETYPE_DLL ${CMAKE_CURRENT_SOURCE_DIR}/../vendor/elements/lib/external/freetype/win64/freetype.dll)
set(FONTCONFIG_DLL ${CMAKE_CURRENT_SOURCE_DIR}/../vendor/elements/lib/external/fontconfig/x64/fontconfig.dll)
set(ICONV_DLL ${CMAKE_CURRENT_SOURCE_DIR}/../vendor/elements/lib/external/fontconfig/x64/libiconv.dll)
set(XML2 ${CMAKE_CURRENT_SOURCE_DIR}/../vendor/elements/lib/external/fontconfig/x64/libxml2.dll)
else()
set(CAIRO_DLL ${CMAKE_CURRENT_SOURCE_DIR}/../vendor/elements/lib/external/cairo/lib/x86/cairo.dll)
set(FREETYPE_DLL ${CMAKE_CURRENT_SOURCE_DIR}/../vendor/elements/lib/external/freetype/win32/freetype.dll)
set(FONTCONFIG_DLL ${CMAKE_CURRENT_SOURCE_DIR}/../vendor/elements/lib/external/fontconfig/x86/fontconfig.dll)
set(ICONV_DLL ${CMAKE_CURRENT_SOURCE_DIR}/../vendor/elements/lib/external/fontconfig/x86/libiconv.dll)
set(XML2 ${CMAKE_CURRENT_SOURCE_DIR}/../vendor/elements/lib/external/fontconfig/x86/libxml2.dll)
endif()

if(MSVC)
    file(COPY ${CAIRO_DLL} DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/Debug/")
    file(COPY ${FREETYPE_DLL} DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/Debug/")
    file(COPY ${FONTCONFIG_DLL} DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/Debug/")
    file(COPY ${ICONV_DLL} DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/Debug/")
    file(COPY ${XML2} DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/Debug/")

    file(COPY ${CAIRO_DLL} DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/Release/")
    file(COPY ${FREETYPE_DLL} DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/Release/")
    file(COPY ${FONTCONFIG_DLL} DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/Release/")
    file(COPY ${ICONV_DLL} DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/Release/")
    file(COPY ${XML2} DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/Release/")

    file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/../resources" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/Debug/")
    file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/../resources" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/Release/")
else()
    file(COPY ${CAIRO_DLL} DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/")
    file(COPY ${FREETYPE_DLL} DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/")
    file(COPY ${FONTCONFIG_DLL} DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/")
    file(COPY ${ICONV_DLL} DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/")
    file(COPY ${XML2} DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/")

    file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/../resources" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/")
endif()
