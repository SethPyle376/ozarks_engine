//
// Created by seth on 6/10/20.
//

#include <core/managers/ComponentManager.h>

ActorComponent::ActorComponent(std::string name) {
  this->name = name;
  GameObjectManager::getInstance()->registerObject(this);
  ComponentManager::getInstance()->registerComponent(this);
}

ActorComponent::~ActorComponent() {
  ComponentManager::getInstance()->deregisterComponent(this);
  GameObjectManager::getInstance()->deregisterObject(this);
}