cmake_minimum_required(VERSION 3.16)
project(ozarks_engine)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

file(GLOB MAINSOURCES src/*.cpp)
file(GLOB SUBSOURCES src/*/*.cpp)

set(SOURCE_FILES ${MAINSOURCES} ${SUBSOURCES})

add_executable(ozarks_engine src/main.cpp include/core/GameObject.h include/util/Types.h include/core/managers/GameObjectManager.h include/util/ErrorTypes.h src/core/managers/GameObjectManager.cpp src/core/GameObject.cpp)