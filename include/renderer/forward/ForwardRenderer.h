//
// Created by seth on 6/13/20.
//

#ifndef OZARKS_ENGINE_FORWARDRENDERER_H
#define OZARKS_ENGINE_FORWARDRENDERER_H

#include "renderer/Renderer.h"
#include "core/resources/ResourceHandle.h"
#include "core/resources/ResourceManager.h"

class ForwardRenderer : public Renderer {
  private:
      ResourceHandle blitProgram;
      ResourceHandle renderProgram;
  public:
      ForwardRenderer();
      void tick(float delta);
};

#endif//OZARKS_ENGINE_FORWARDRENDERER_H
