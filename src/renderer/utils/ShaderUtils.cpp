//
// Created by seth on 6/13/20.
//

#include "renderer/utils/ShaderUtils.h"

const bgfx::Memory* loadProgramIntoMemory(std::string filename) {
  SDL_RWops *file = SDL_RWFromFile(filename.c_str(), "r");
  uint32_t size = static_cast<uint32_t>(SDL_RWsize(file));

  const bgfx::Memory* mem = bgfx::alloc(size + 1);

  SDL_RWread(file, mem->data, size, 1);
  SDL_RWclose(file);

  mem->data[mem->size - 1] = '\0';

  return mem;
}

bgfx::ShaderHandle loadShader(std::string filename) {
  bgfx::ShaderHandle handle = bgfx::createShader(loadProgramIntoMemory(filename));
  return handle;
}