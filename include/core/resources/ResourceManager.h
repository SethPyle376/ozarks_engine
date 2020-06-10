//
// Created by seth on 6/9/20.
//

#ifndef OZARKS_ENGINE_RESOURCEMANAGER_H
#define OZARKS_ENGINE_RESOURCEMANAGER_H

#include <unordered_map>
#include <string>
#include <vector>

#include "SDL.h"
#include "rapidjson/document.h"

#include "ResourceFactory.h"
#include "core/resources/ResourceHandle.h"
#include "core/resources/ResourceRefCounter.h"

const std::string assetPath = "assets/";

class ResourceManager {
  private:
      static ResourceManager* instance;
      std::unordered_map<std::string, ResourceFactory*> resourceFactoryMap;
      std::unordered_map<std::string, Resource*> resourceMap;

      ResourceRefCounter refCounter;

      Resource* loadResource(std::string path);
  public:
      static ResourceManager* getInstance();
      void registerFactory(ResourceFactory *factory);
      ResourceHandle getResource(std::string path);
      void destroyResource(ResourceHandle* handle);
};

#endif//OZARKS_ENGINE_RESOURCEMANAGER_H
