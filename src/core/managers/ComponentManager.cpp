//
// Created by seth on 6/9/20.
//

#include "core/managers/ComponentManager.h"

ComponentManager *ComponentManager::instance = nullptr;

ERROR_TYPE ComponentManager::registerComponent(ActorComponent *component) {
  componentMap[component->name][component->getId()] = component;
  return SUCCESS;
}

ERROR_TYPE ComponentManager::deregisterComponent(ActorComponent *component) {
  componentMap[component->name].erase(component->getId());
  return SUCCESS;
}

ComponentManager *ComponentManager::getInstance() {
  if (instance == nullptr) {
    instance = new ComponentManager();
  }

  return instance;
}
