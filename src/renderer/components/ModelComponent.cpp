//
// Created by seth on 6/12/20.
//

#include "renderer/components/ModelComponent.h"

ModelComponent::ModelComponent(std::string name, std::string modelResourcePath) : ActorComponent(name) {
  modelResource = ResourceManager::getInstance()->getResource(modelResourcePath);
}

ModelComponent::ModelComponent(std::string name, ResourceHandle resourceHandle) : ActorComponent(name) {
  modelResource = resourceHandle;
}
