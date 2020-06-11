//
// Created by seth on 6/9/20.
//

#include "core/resources/ResourceManager.h"

ResourceManager *ResourceManager::instance = nullptr;

void ResourceManager::registerFactory(ResourceFactory *factory) {
  this->resourceFactoryMap[factory->type] = factory;
}

Resource* ResourceManager::loadResource(std::string path) {
  SDL_RWops *sdlFile = SDL_RWFromFile((assetPath + path).c_str(), "rb");

  if (sdlFile == nullptr) {
    // TODO: ERROR
  }

  int size = SDL_RWsize(sdlFile);
  std::vector<char> buffer(size);
  SDL_RWread(sdlFile, buffer.data(), size, 1);
  SDL_RWclose(sdlFile);

  std::string resourceData(buffer.begin(), buffer.end());

  rapidjson::Document document;
  document.Parse(resourceData.c_str());

  std::string resourceType = document["type"].GetString();

  Resource* resource = resourceFactoryMap[resourceType]->loadResource(document);

  return resource;
}

ResourceHandle ResourceManager::getResource(std::string path) {
  std::unordered_map<std::string, Resource*>::const_iterator iter = resourceMap.find(path);

  if(iter == resourceMap.end()) {
    resourceMap[path] = loadResource(path);
  }

  ResourceHandle handle;
  handle.resource = resourceMap[path];
  handle.path = path;
  handle.type = resourceMap[path]->type;

  refCounter.incrementResourceCount(path);

  return handle;
}

ResourceManager* ResourceManager::getInstance() {
  if (instance == nullptr) {
    instance = new ResourceManager();
  }

  return instance;
}

void ResourceManager::destroyResource(ResourceHandle* handle) {
  CounterResult result = refCounter.decrementResourceCount(handle->path);

  if (result == RESOURCE_NEEDS_DELETED) {
    resourceMap.erase(handle->path);
    delete handle->resource;
  }
}
