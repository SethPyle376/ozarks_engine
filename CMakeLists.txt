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

set(SOURCE_FILES ${MAINSOURCES} ${SUBSOURCES} ${SUBSUBSOURCES} include/renderer/resources/MeshResourceFactory.h include/renderer/VertexLayout.h src/renderer/resources/MeshResourceFactory.cpp include/renderer/resources/ModelResource.h include/renderer/resources/ModelResourceFactory.h src/renderer/resources/ModelResourceFactory.cpp include/renderer/components/ModelComponent.h src/renderer/components/ModelComponent.cpp include/renderer/Renderer.h include/renderer/forward/ForwardRenderer.h src/renderer/forward/ForwardRenderer.cpp include/renderer/resources/ProgramResource.h include/renderer/resources/ProgramResourceFactory.h src/renderer/resources/ProgramResourcefactory.cpp include/renderer/utils/ShaderUtils.h src/renderer/utils/ShaderUtils.cpp include/renderer/RenderContext.h include/renderer/bgfx/BGFXRenderContext.h include/core/config/CentralConfig.h include/core/platform/RenderWindow.h)

include_directories(external/bimg/3rdparty)
include_directories(external/bimg/3rdparty/astc-codec/include)
include_directories(external/bimg/3rdparty/iqa/include)
add_library( bimg STATIC ${BIMGSOURCES} )

add_executable(ozarks_engine ${SOURCE_FILES})

target_link_libraries(ozarks_engine ${SDL2_LIBRARIES} ${BGFX_LIB})