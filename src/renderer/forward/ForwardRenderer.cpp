//
// Created by seth on 6/13/20.
//

#include "renderer/forward/ForwardRenderer.h"

ForwardRenderer::ForwardRenderer(int width, int height) : width(width), height(height) {
  blitProgram = ResourceManager::getInstance()->getResource("shaders/blit/blitProgram.json");
  renderProgram = ResourceManager::getInstance()->getResource("shaders/forward/renderProgram.json");
  frameBuffer = loadFramebuffer(true, true);
  blitSampler = bgfx::createUniform("s_texColor", bgfx::UniformType::Sampler);
}

void ForwardRenderer::blitToScreen(bgfx::ViewId view) {

}


void ForwardRenderer::tick(float delta) {

}