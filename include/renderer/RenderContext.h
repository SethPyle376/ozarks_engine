//
// Created by seth on 6/13/20.
//

#ifndef OZARKS_ENGINE_RENDERCONTEXT_H
#define OZARKS_ENGINE_RENDERCONTEXT_H

#include <core/config/CentralConfig.h>
#include <core/platform/RenderWindow.h>

class RenderContext {
  protected:
      RenderWindow* window;
  public:
      RenderContext() {
        CentralConfig* config = CentralConfig::getInstance();

        int windowWidth = config->document["renderOptions"]["windowWidth"].GetInt();
        int windowHeight = config->document["renderOptions"]["windowHeight"].GetInt();

        this->window = new RenderWindow(windowWidth, windowHeight);
      }

      virtual void start() = 0;
};

#endif//OZARKS_ENGINE_RENDERCONTEXT_H
