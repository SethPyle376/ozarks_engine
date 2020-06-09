//
// Created by seth on 6/7/20.
//

#include <iostream>

#include "core/types/Actor.h"
#include "core/managers/GameObjectManager.h"

int main()
{
  GameObjectManager *objectManager = GameObjectManager::getInstance();

  Actor* testActor1 = new Actor();
  Actor* testActor2 = new Actor();
  Actor* testActor3 = new Actor();

  objectManager->registerObject(testActor1);
  objectManager->registerObject(testActor2);
  objectManager->registerObject(testActor3);

  testActor1->addChild(testActor2);
  testActor2->addChild(testActor3);

  delete testActor1;

  std::cout << "test" << std::endl;
}