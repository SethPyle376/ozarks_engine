cmake_minimum_required(VERSION 3.16)
project(ozarks_engine)

set(CMAKE_CXX_STANDARD 14)

find_package(SDL2 REQUIRED)

include_directories(include)

if (UNIX)
find_library(BGFX_LIB libbgfx-shared-libRelease.so HINTS ${CMAKE_SOURCE_DIR}/external/bgfx/.build/linux64_gcc/bin)
endif(UNIX)

include_directories(external/bgfx/include)
include_directories(external/bx/include)
include_directories(external/glm)
include_directories(external/rapidjson/include)
include_directories(${SDL2_INCLUDE_DIRS})

file(GLOB BIMGSOURCES external/bimg/src/*.cpp)
file(GLOB MAINSOURCES src/*.cpp)
file(GLOB SUBSOURCES src/*/*.cpp)
file(GLOB SUBSUBSOURCES src/*/*/*.cpp)

set(SOURCE_FILES ${MAINSOURCES} ${SUBSOURCES} ${SUBSUBSOURCES} src/core/config/CentralConfig.cpp include/renderer/utils/RenderUtils.h src/renderer/utils/RenderUtils.cpp include/runtime/scene/GLTFSceneLoader.h src/runtime/scene/GLTFSceneLoader.cpp)

add_subdirectory(external)

include_directories(external/bimg/3rdparty)
include_directories(external/bimg/3rdparty/astc-codec/include)
include_directories(external/bimg/3rdparty/iqa/include)
add_library( bimg STATIC ${BIMGSOURCES} )

add_executable(ozarks_engine ${SOURCE_FILES})

target_link_libraries(ozarks_engine ${SDL2_LIBRARIES} ${BGFX_LIB} assimp)