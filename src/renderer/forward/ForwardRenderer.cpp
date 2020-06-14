//
// Created by seth on 6/13/20.
//

#include "renderer/forward/ForwardRenderer.h"

ForwardRenderer::ForwardRenderer() {
  // blitProgram = ResourceManager::getInstance()->getResource("shaders/blit/blitProgram.json");
  renderProgram = ResourceManager::getInstance()->getResource("shaders/forward/renderProgram.json");
}


void ForwardRenderer::tick(float delta) {

}