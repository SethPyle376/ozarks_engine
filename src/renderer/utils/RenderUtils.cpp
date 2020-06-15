//
// Created by seth on 6/14/20.
//

#include "renderer/utils/RenderUtils.h"
#include <bx/bx.h>

bgfx::FrameBufferHandle loadFramebuffer(bool hdr, bool depth) {
  bgfx::TextureHandle textures[2];
  uint8_t attachments = 0;

  const uint64_t samplerFlags = BGFX_SAMPLER_MIN_POINT | BGFX_SAMPLER_MAG_POINT | BGFX_SAMPLER_MIP_POINT | BGFX_SAMPLER_U_CLAMP | BGFX_SAMPLER_V_CLAMP;

  bgfx::TextureFormat::Enum format = hdr ? bgfx::TextureFormat::RGBA16F : bgfx::TextureFormat::BGRA8;

  if (!bgfx::isTextureValid(0, false, 1, format, BGFX_TEXTURE_RT | samplerFlags)) {
    // TODO: HANDLE ERROR
  }

  textures[attachments++] = bgfx::createTexture2D(bgfx::BackbufferRatio::Equal, false, 1, format, BGFX_TEXTURE_RT | samplerFlags);

  if (depth) {
    bgfx::TextureFormat::Enum depthFormat = findDepthFormat(BGFX_TEXTURE_RT_WRITE_ONLY | samplerFlags);
    textures[attachments++] = bgfx::createTexture2D(bgfx::BackbufferRatio::Equal, false, 1, depthFormat, BGFX_TEXTURE_RT_WRITE_ONLY | samplerFlags);
  }

  bgfx::FrameBufferHandle fb = bgfx::createFrameBuffer(attachments, textures, true);

  return fb;
}

bgfx::TextureFormat::Enum findDepthFormat(uint64_t textureFlags, bool stencil) {
  const bgfx::TextureFormat::Enum depthFormats[] = { bgfx::TextureFormat::D16, bgfx::TextureFormat::D32 };
  const bgfx::TextureFormat::Enum depthStencilFormats[] = { bgfx::TextureFormat::D24S8 };
  const bgfx::TextureFormat::Enum* formats = stencil ? depthStencilFormats : depthFormats;

  size_t count = stencil ? BX_COUNTOF(depthStencilFormats) : BX_COUNTOF(depthFormats);

  bgfx::TextureFormat::Enum depthFormat = bgfx::TextureFormat::Count;

  for (size_t i = 0; i < count; i++) {
    if (bgfx::isTextureValid(0, false, 1, formats[i], textureFlags)) {
      depthFormat = formats[i];
      break;
    }
  }

  return depthFormat;
}
