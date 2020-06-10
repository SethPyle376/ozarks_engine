//
// Created by seth on 6/9/20.
//

#ifndef OZARKS_ENGINE_TESTCOMPONENT_H
#define OZARKS_ENGINE_TESTCOMPONENT_H

#include <iostream>

#include "core/components/ActorComponent.h"
#include "core/managers/ComponentManager.h"

class TestComponent : public ActorComponent
{
  public:
      TestComponent() : ActorComponent("test_component") {
        name = "test_component";
      }

      ~TestComponent() {
        ComponentManager::getInstance()->deregisterComponent(this);
      }

      void tick(float delta) override {
        std::cout << "tick from test component id: " << this->getId() << " parent id: " << parent->getId() << std::endl;
      }
};

#endif//OZARKS_ENGINE_TESTCOMPONENT_H
