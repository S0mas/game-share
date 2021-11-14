cmake_minimum_required(VERSION 3.18.8)

set(PROJECT loguru)
project(${PROJECT} LANGUAGES CXX)

#BUILD FLAGS ####################################################################
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_compile_options("/std:c++latest")

#PREPARING HEADER FILES ################################
file(GLOB_RECURSE EXTERNAL_HEADERS include/*.h include/*.hpp)

add_library(${PROJECT} src/loguru.cpp ${EXTERNAL_HEADERS})

target_include_directories(${PROJECT}
    PRIVATE src
    PUBLIC include
)
