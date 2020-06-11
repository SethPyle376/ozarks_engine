//
// Created by seth on 6/9/20.
//

#ifndef OZARKS_ENGINE_RESOURCEFACTORY_H
#define OZARKS_ENGINE_RESOURCEFACTORY_H

#include "Resource.h"
#include "rapidjson/document.h"
#include <string>

class ResourceFactory {
  public:
      std::string type;

      virtual Resource* loadResource(std::string path) { return new Resource; };
      virtual Resource* loadResource(rapidjson::Document& document) = 0;
};

#endif//OZARKS_ENGINE_RESOURCEFACTORY_H
