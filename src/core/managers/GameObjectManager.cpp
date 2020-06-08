//
// Created by seth on 6/8/20.
//

#include "core/managers/GameObjectManager.h"

GameObjectManager *GameObjectManager::instance = nullptr;

GameObjectManager::GameObjectManager()
{
  this->currentIndex = 0;
}

ERROR_TYPE GameObjectManager::registerObject(GameObject* object)
{
  object->setId(currentIndex);

  this->gameObjectMap[currentIndex] = object;
  currentIndex++;

  return SUCCESS;
}

ERROR_TYPE GameObjectManager::deregisterObject(GameObject *object) {
  deregisterObject(object->getId());
}

ERROR_TYPE GameObjectManager::deregisterObject(uint32_t id) {
  this->gameObjectMap.erase(id);
}

GameObjectManager *GameObjectManager::getInstance() {
  if (instance == nullptr)
  {
    instance = new GameObjectManager();
  }

  return instance;
}
