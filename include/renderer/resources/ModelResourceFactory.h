//
// Created by seth on 6/11/20.
//

#ifndef OZARKS_ENGINE_MODELRESOURCEFACTORY_H
#define OZARKS_ENGINE_MODELRESOURCEFACTORY_H

#include "renderer/resources/ModelResource.h"
#include "core/resources/ResourceFactory.h"
#include "core/resources/ResourceManager.h"

class ModelResourceFactory : public ResourceFactory {
  public:
      ModelResourceFactory() {
        type = "model_resource";
      }

      Resource* loadResource(rapidjson::Document& document);
};

#endif//OZARKS_ENGINE_MODELRESOURCEFACTORY_H
