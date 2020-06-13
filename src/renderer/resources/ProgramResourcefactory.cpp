//
// Created by seth on 6/13/20.
//

#include "renderer/resources/ProgramResourceFactory.h"

ProgramResourceFactory::ProgramResourceFactory() {
  this->type = "shader_program_resource";
}

Resource* ProgramResourceFactory::loadResource(rapidjson::Document &document) {
  return loadProgram(document["vertexPath"].GetString(), document["fragmentPath"].GetString());
}

ProgramResource* ProgramResourceFactory::loadProgram(std::string vertPath, std::string fragPath) {
  bgfx::ShaderHandle vsh = loadShader(vertPath);
  bgfx::ShaderHandle fsh = BGFX_INVALID_HANDLE;

  if (NULL != fragPath.c_str()) {
    fsh = loadShader(fragPath);
  }

  ProgramResource* programResource = new ProgramResource();
  programResource->programHandle = bgfx::createProgram(vsh, fsh, true);
}

