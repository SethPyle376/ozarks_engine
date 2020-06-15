//
// Created by seth on 6/13/20.
//

#ifndef OZARKS_ENGINE_FORWARDRENDERER_H
#define OZARKS_ENGINE_FORWARDRENDERER_H

#include "renderer/Renderer.h"
#include "renderer/utils/RenderUtils.h"
#include "core/resources/ResourceHandle.h"
#include "core/resources/ResourceManager.h"
#include "bgfx/bgfx.h"

class ForwardRenderer : public Renderer {
  private:
      int width, height;

      ResourceHandle blitProgram;
      ResourceHandle renderProgram;

      bgfx::VertexBufferHandle blitTriangleBuffer;
      bgfx::FrameBufferHandle frameBuffer;
      bgfx::UniformHandle blitSampler;

      void blitToScreen(bgfx::ViewId view);
  public:
      ForwardRenderer(int width, int height);
      void tick(float delta);
};

#endif//OZARKS_ENGINE_FORWARDRENDERER_H
