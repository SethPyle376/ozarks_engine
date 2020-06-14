//
// Created by seth on 6/13/20.
//

#include "renderer/resources/ProgramResourceFactory.h"

ProgramResourceFactory::ProgramResourceFactory() {
  this->type = "shader_program_resource";
}

Resource* ProgramResourceFactory::loadResource(rapidjson::Document &document) {
  std::string vertexPath = std::string("assets/") + document["vertexPath"].GetString();
  std::string fragmentPath = std::string("assets/") + document["fragmentPath"].GetString();

  std::string apiString = CentralConfig::getInstance()->document["renderOptions"]["rendererType"].GetString();

  vertexPath = std::regex_replace(vertexPath, std::regex("\\$API"), apiString);
  fragmentPath = std::regex_replace(fragmentPath, std::regex("\\$API"), apiString);

  return loadProgram(vertexPath, fragmentPath);
}

ProgramResource* ProgramResourceFactory::loadProgram(std::string vertPath, std::string fragPath) {
  bgfx::ShaderHandle vsh = loadShader(vertPath);
  bgfx::ShaderHandle fsh = BGFX_INVALID_HANDLE;

  if (NULL != fragPath.c_str()) {
    fsh = loadShader(fragPath);
  }

  ProgramResource* programResource = new ProgramResource();
  programResource->programHandle = bgfx::createProgram(vsh, fsh, true);

  return programResource;
}

