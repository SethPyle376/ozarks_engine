//
// Created by seth on 6/11/20.
//

#include "renderer/resources/ModelResourceFactory.h"

Resource* ModelResourceFactory::loadResource(rapidjson::Document &document) {
  std::string meshPath = document["meshPath"].GetString();
  // std::string materialPath = document["materialPath"].GetString();

  ModelResource* modelResource = new ModelResource();

  ResourceManager::getInstance()->getResource(meshPath, "mesh_resource", modelResource->meshHandle);
  // modelResource->materialHandle = ResourceManager::getInstance()->getResource(materialPath, "material_resource");

  return modelResource;
}