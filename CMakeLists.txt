cmake_minimum_required(VERSION 3.16)
project(ozarks_engine)

set(CMAKE_CXX_STANDARD 14)

include_directories(external/bitsery/include)

include_directories(include)

file(GLOB MAINSOURCES src/*.cpp)
file(GLOB SUBSOURCES src/*/*.cpp)

set(SOURCE_FILES ${MAINSOURCES} ${SUBSOURCES})

add_executable(ozarks_engine src/main.cpp include/core/GameObject.h include/util/Types.h)