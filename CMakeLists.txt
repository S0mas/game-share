cmake_minimum_required(VERSION 3.21.1)

set(PROJECT gameShare)
project(${PROJECT} LANGUAGES CXX)

#BUILD FLAGS ####################################################################
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(loguru)
add_subdirectory(dbIf)
add_subdirectory(dbImpl_qt_sql)
add_subdirectory(db)
add_subdirectory(gui)
add_subdirectory(backend)
