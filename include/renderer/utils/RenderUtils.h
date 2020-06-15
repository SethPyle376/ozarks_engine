//
// Created by seth on 6/14/20.
//

#ifndef OZARKS_ENGINE_RENDERUTILS_H
#define OZARKS_ENGINE_RENDERUTILS_H

#include "bgfx/bgfx.h"

bgfx::FrameBufferHandle loadFramebuffer(bool hdr, bool depth);

bgfx::TextureFormat::Enum findDepthFormat(uint64_t textureFlags, bool stencil = false);

#endif//OZARKS_ENGINE_RENDERUTILS_H
