//
// Created by seth on 6/10/20.
//

#ifndef OZARKS_ENGINE_SYSTEM_H
#define OZARKS_ENGINE_SYSTEM_H

class System {
  public:
      virtual void tick(float delta) = 0;
};

#endif//OZARKS_ENGINE_SYSTEM_H
