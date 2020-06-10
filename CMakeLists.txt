cmake_minimum_required(VERSION 3.16)
project(ozarks_engine)

set(CMAKE_CXX_STANDARD 14)

find_package(SDL2 REQUIRED)

include_directories(include)

include_directories(external/glm)
include_directories(external/rapidjson/include)
include_directories(${SDL2_INCLUDE_DIRS})

file(GLOB MAINSOURCES src/*.cpp)
file(GLOB SUBSOURCES src/*/*.cpp)
file(GLOB SUBSUBSOURCES src/*/*/*.cpp)

set(SOURCE_FILES ${MAINSOURCES} ${SUBSOURCES} ${SUBSUBSOURCES} include/core/managers/ComponentManager.h src/core/managers/ComponentManager.cpp include/core/resources/ResourceHandle.h include/core/resources/ResourceManager.h src/core/resources/ResourceManager.cpp include/core/resources/ResourceFactory.h include/core/resources/Resource.h include/core/resources/test/TestResource.h include/core/resources/test/TestResourceFactory.h include/core/resources/ResourceRefCounter.h src/core/resources/ResourceRefCounter.cpp include/core/resources/ResourceManagerBridge.h src/core/resources/ResourceHandle.cpp)

add_executable(ozarks_engine ${SOURCE_FILES})

target_link_libraries(ozarks_engine ${SDL2_LIBRARIES})