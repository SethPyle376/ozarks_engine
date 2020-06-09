//
// Created by seth on 6/9/20.
//

#ifndef OZARKS_ENGINE_COMPONENTMANAGER_H
#define OZARKS_ENGINE_COMPONENTMANAGER_H

#include <string>
#include <unordered_map>
#include <vector>

#include "GameObjectManager.h"
#include "core/components/ActorComponent.h"
#include "util/ErrorTypes.h"

class ComponentManager {
  private:
      static ComponentManager *instance;
      std::unordered_map<std::string, std::unordered_map<uint32_t, ActorComponent*>> componentMap;
  public:
      static ComponentManager *getInstance();
      ERROR_TYPE registerComponent(ActorComponent* component);
      ERROR_TYPE deregisterComponent(uint32_t id);
      ERROR_TYPE deregisterComponent(ActorComponent* component);
};

#endif//OZARKS_ENGINE_COMPONENTMANAGER_H
