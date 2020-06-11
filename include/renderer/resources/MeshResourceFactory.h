//
// Created by seth on 6/11/20.
//

#ifndef OZARKS_ENGINE_MESHRESOURCEFACTORY_H
#define OZARKS_ENGINE_MESHRESOURCEFACTORY_H

#include "core/resources/ResourceFactory.h"
#include "renderer/resources/MeshResource.h"
#include <rapidjson/document.h>

class MeshResourceFactory : public ResourceFactory {
  public:
      MeshResourceFactory() {
        this->type = "mesh_resource";
      }

      Resource* loadResource(rapidjson::Document& document);
};

#endif//OZARKS_ENGINE_MESHRESOURCEFACTORY_H
