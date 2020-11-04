add_library(sqlite3 STATIC sqlite3.h sqlite3.c)

if(UNIX AND NOT APPLE)
    target_link_libraries(sqlite3 dl)
endif()