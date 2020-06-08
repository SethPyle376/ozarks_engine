//
// Created by seth on 6/7/20.
//

#ifndef OZARKS_ENGINE_GAMEOBJECT_H
#define OZARKS_ENGINE_GAMEOBJECT_H

#include "util/Types.h"

class GameObject
{
  private:
      uint32_t id;
  public:
      virtual void serialize() {
        return;
      };
      
};

#endif //OZARKS_ENGINE_GAMEOBJECT_H
