//
// Created by seth on 6/8/20.
//

#ifndef OZARKS_ENGINE_ACTOR_H
#define OZARKS_ENGINE_ACTOR_H

#include <vector>

#include "glm/glm.hpp"

#include "core/types/GameObject.h"
#include "core/managers/GameObjectManager.h"
#include "core/components/ActorComponent.h"

class Actor : public GameObject
{
  private:
      Actor* parent = nullptr;
      std::vector<Actor*> children;
      std::vector<ActorComponent*> components;

      void tickComponents(float delta);
      void tickChildren(float delta);
  public:
      Actor();
      ~Actor();

      void tick(float delta);

      virtual void process(float delta);

      void addChild(Actor* child);
      void addComponent(ActorComponent* component);

      glm::vec3 getWorldPosition();

      glm::vec3 pos;
};

#endif//OZARKS_ENGINE_ACTOR_H
