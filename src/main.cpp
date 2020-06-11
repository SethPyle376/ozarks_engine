//
// Created by seth on 6/7/20.
//

#include <iostream>
#include <renderer/resources/MeshResourceFactory.h>

#include "core/components/TestComponent.h"
#include "core/managers/GameObjectManager.h"
#include "core/types/Actor.h"

#include "core/resources/ResourceManager.h"
#include "core/resources/test/TestResourceFactory.h"

#include "bgfx/bgfx.h"

int main()
{
  GameObjectManager *objectManager = GameObjectManager::getInstance();
  ComponentManager *componentManager = ComponentManager::getInstance();
  ResourceManager *resourceManager = ResourceManager::getInstance();

  Actor* testActor1 = new Actor();
  Actor* testActor2 = new Actor();
  Actor* testActor3 = new Actor();

  TestComponent* testComponent = new TestComponent();

  objectManager->registerObject(testActor1);
  objectManager->registerObject(testActor2);
  objectManager->registerObject(testActor3);

  testActor1->addChild(testActor2);
  testActor2->addChild(testActor3);

  testActor1->addComponent(testComponent);

  testActor1->tick(0);

  delete testActor1;

  TestResourceFactory *factory = new TestResourceFactory();
  MeshResourceFactory *meshFactory = new MeshResourceFactory();

  resourceManager->registerFactory(factory);
  resourceManager->registerFactory(meshFactory);

  {
    ResourceHandle testResource = resourceManager->getResource("test/testResource.json");
    ResourceHandle testMeshResource = resourceManager->getResource("test/renderer/testMeshResource.json");
  }

  std::cout << "test" << std::endl;
}