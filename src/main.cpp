//
// Created by seth on 6/7/20.
//

#include <iostream>

#include "util/Types.h"
#include "core/managers/GameObjectManager.h"

int main()
{
  GameObject testObject = GameObject();

  GameObjectManager *objectManager = GameObjectManager::getInstance();

  objectManager->registerObject(&testObject);

  std::cout << "test" << std::endl;
}