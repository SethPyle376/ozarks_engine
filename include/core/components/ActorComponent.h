//
// Created by seth on 6/8/20.
//

#ifndef OZARKS_ENGINE_ACTORCOMPONENT_H
#define OZARKS_ENGINE_ACTORCOMPONENT_H


#include <string>

#include "core/types/GameObject.h"

class Actor;

class ActorComponent : public GameObject
{
  public:
      ActorComponent(std::string name);
      virtual ~ActorComponent();
      Actor* parent = nullptr;
      void tick(float delta) override = 0;
};

#endif//OZARKS_ENGINE_ACTORCOMPONENT_H
