//
// Created by seth on 6/13/20.
//

#ifndef OZARKS_ENGINE_SHADERUTILS_H
#define OZARKS_ENGINE_SHADERUTILS_H

#include <string>

#include "bgfx/bgfx.h"
#include "SDL.h"

const bgfx::Memory* loadProgramIntoMemory(std::string filename);
bgfx::ShaderHandle loadShader(std::string filename);

#endif//OZARKS_ENGINE_SHADERUTILS_H
