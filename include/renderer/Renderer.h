//
// Created by seth on 6/13/20.
//

#ifndef OZARKS_ENGINE_RENDERER_H
#define OZARKS_ENGINE_RENDERER_H

#include <core/systems/System.h>

class Renderer : public System {
  public:
      void tick(float delta) override = 0;
};

#endif//OZARKS_ENGINE_RENDERER_H
