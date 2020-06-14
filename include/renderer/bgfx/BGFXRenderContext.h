//
// Created by seth on 6/13/20.
//

#ifndef OZARKS_ENGINE_BGFXRENDERCONTEXT_H
#define OZARKS_ENGINE_BGFXRENDERCONTEXT_H

#include "core/config/CentralConfig.h"

#include "bgfx/bgfx.h"
#include "bgfx/platform.h"
#include <SDL_syswm.h>
#include <renderer/RenderContext.h>

class BGFXRenderContext : public RenderContext {
  public:
      void start() override {
        CentralConfig* config = CentralConfig::getInstance();

        SDL_SysWMinfo wmi;
        SDL_VERSION(&wmi.version);

        if (!SDL_GetWindowWMInfo(this->window->window, &wmi)) {
          // TODO: Handle error
        }

        bgfx::PlatformData platformData;
        platformData.nwh = (void*)(uintptr_t)wmi.info.x11.window;
        platformData.ndt = wmi.info.x11.display;
        bgfx::setPlatformData(platformData);

        bgfx::Init bgfxInit;
        bgfxInit.resolution.width = window->width;
        bgfxInit.resolution.height = window->height;
        // bgfxInit.resolution.reset = BGFX_RESET_VSYNC;


        std::string rendererType = "OpenGL";
        rapidjson::Value::ConstMemberIterator itr = config->document["renderOptions"].FindMember("rendererType");

        if (itr != config->document.MemberEnd()) {
          rendererType = config->document["renderOptions"]["rendererType"].GetString();
        }

        if (rendererType == "OpenGL") {
          bgfxInit.type = bgfx::RendererType::OpenGL;
        } else if (rendererType == "Vulkan") {
          bgfxInit.type = bgfx::RendererType::Vulkan;
        }

        bgfx::init(bgfxInit);
      }
};

#endif//OZARKS_ENGINE_BGFXRENDERCONTEXT_H
