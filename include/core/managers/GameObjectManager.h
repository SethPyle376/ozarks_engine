//
// Created by seth on 6/8/20.
//

#ifndef OZARKS_ENGINE_GAMEOBJECTMANAGER_H
#define OZARKS_ENGINE_GAMEOBJECTMANAGER_H

#include <core/GameObject.h>
#include <unordered_map>
#include <util/ErrorTypes.h>

class GameObjectManager
{
  private:
      static GameObjectManager *instance;
      uint32_t currentIndex;
      std::unordered_map<uint32_t, GameObject*> gameObjectMap;

  public:
      static GameObjectManager *getInstance();
      GameObjectManager();
      ERROR_TYPE registerObject(GameObject* object);

      ERROR_TYPE deregisterObject(GameObject* object);
      ERROR_TYPE deregisterObject(uint32_t id);
};

#endif//OZARKS_ENGINE_GAMEOBJECTMANAGER_H
