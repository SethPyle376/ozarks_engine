//
// Created by seth on 6/11/20.
//

#include "renderer/resources/MeshResourceFactory.h"

Resource * MeshResourceFactory::loadResource(rapidjson::Document& document) {
  // TODO: ALLOCATE WITH CUSTOM ALLOCATOR
  MeshResource* meshResource = new MeshResource();
  return meshResource;
}