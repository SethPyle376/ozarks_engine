//
// Created by seth on 6/9/20.
//

#ifndef OZARKS_ENGINE_RESOURCE_H
#define OZARKS_ENGINE_RESOURCE_H

#include <string>
#include <cstdint>

class ResourceManager;

class Resource {
  public:
      virtual ~Resource() = default;
      std::string type;
};
#endif//OZARKS_ENGINE_RESOURCE_H
