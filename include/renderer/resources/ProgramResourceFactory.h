//
// Created by seth on 6/13/20.
//

#ifndef OZARKS_ENGINE_PROGRAMRESOURCEFACTORY_H
#define OZARKS_ENGINE_PROGRAMRESOURCEFACTORY_H

#include <string>
#include <regex>

#include "core/config/CentralConfig.h"
#include "core/resources/ResourceFactory.h"
#include "renderer/resources/ProgramResource.h"
#include "renderer/utils/ShaderUtils.h"

#include "SDL.h"

class ProgramResourceFactory : public ResourceFactory {
  private:
      ProgramResource *loadProgram(std::string vertPath, std::string fragPath);
  public:
      ProgramResourceFactory();
      Resource* loadResource(rapidjson::Document& document);
};

#endif//OZARKS_ENGINE_PROGRAMRESOURCEFACTORY_H
