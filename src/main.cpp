//
// Created by seth on 6/7/20.
//

#include <iostream>
#include <renderer/bgfx/BGFXRenderContext.h>
#include <renderer/components/ModelComponent.h>
#include <renderer/resources/MeshResourceFactory.h>
#include <renderer/resources/ModelResourceFactory.h>

#include "core/components/TestComponent.h"
#include "core/managers/GameObjectManager.h"
#include "core/types/Actor.h"

#include "core/resources/ResourceManager.h"
#include "core/resources/test/TestResourceFactory.h"

#include "bgfx/bgfx.h"

int main() {
  GameObjectManager *objectManager = GameObjectManager::getInstance();
  ComponentManager *componentManager = ComponentManager::getInstance();
  ResourceManager *resourceManager = ResourceManager::getInstance();
  CentralConfig *centralConfig = CentralConfig::getInstance();

  centralConfig->load("./config.json");

  BGFXRenderContext renderContext;
  renderContext.start();

  Actor *testActor1 = new Actor();
  Actor *testActor2 = new Actor();
  Actor *testActor3 = new Actor();

  TestComponent *testComponent = new TestComponent();

  TestResourceFactory *factory = new TestResourceFactory();
  MeshResourceFactory *meshFactory = new MeshResourceFactory();
  ModelResourceFactory *modelFactory = new ModelResourceFactory();

  resourceManager->registerFactory(factory);
  resourceManager->registerFactory(meshFactory);
  resourceManager->registerFactory(modelFactory);

  ModelComponent *modelComponent = new ModelComponent("model_component", "test/renderer/testModelResource.json");

  objectManager->registerObject(testActor1);
  objectManager->registerObject(testActor2);
  objectManager->registerObject(testActor3);

  testActor1->addChild(testActor2);
  testActor2->addChild(testActor3);

  testActor1->addComponent(testComponent);
  testActor3->addComponent(modelComponent);

  testActor1->tick(0);
}