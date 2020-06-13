//
// Created by seth on 6/12/20.
//

#ifndef OZARKS_ENGINE_MODELCOMPONENT_H
#define OZARKS_ENGINE_MODELCOMPONENT_H

#include "core/components/ActorComponent.h"
#include "core/resources/ResourceHandle.h"

#include "core/resources/ResourceManager.h"

class ModelComponent : public ActorComponent {
  public:
      ModelComponent(std::string name, std::string modelResourcePath);
      ModelComponent(std::string name, ResourceHandle resourceHandle);
      ResourceHandle modelResource;

      void tick(float delta) override {};
};

#endif//OZARKS_ENGINE_MODELCOMPONENT_H
