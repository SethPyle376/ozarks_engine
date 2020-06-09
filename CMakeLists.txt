cmake_minimum_required(VERSION 3.16)
project(ozarks_engine)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)
include_directories(external/glm)

file(GLOB MAINSOURCES src/*.cpp)
file(GLOB SUBSOURCES src/*/*.cpp)

set(SOURCE_FILES ${MAINSOURCES} ${SUBSOURCES})

add_executable(ozarks_engine src/main.cpp include/core/types/GameObject.h include/util/Types.h include/core/managers/GameObjectManager.h include/util/ErrorTypes.h src/core/managers/GameObjectManager.cpp src/core/types/GameObject.cpp include/core/types/Actor.h src/core/types/Actor.cpp include/core/components/ActorComponent.h)