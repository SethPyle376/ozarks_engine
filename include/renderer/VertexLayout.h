//
// Created by seth on 6/11/20.
//

#ifndef OZARKS_ENGINE_VERTEXLAYOUT_H
#define OZARKS_ENGINE_VERTEXLAYOUT_H

#include "bgfx/bgfx.h"

struct Vertex {
  float x, y, z; // position
  float nx, ny, nz; // normal
  float tx, ty, tz; // tangent
  float u, v; // texture

  static void init() {
    layout.begin()
            .add(bgfx::Attrib::Position, 3, bgfx::AttribType::Float)
            .add(bgfx::Attrib::Normal, 3, bgfx::AttribType::Float)
            .add(bgfx::Attrib::Tangent, 3, bgfx::AttribType::Float)
            .add(bgfx::Attrib::TexCoord0, 2, bgfx::AttribType::Float)
            .end();
  }

  static bgfx::VertexLayout layout;
};

struct PosVertex
{
  float x;
  float y;
  float z;

  static void init()
  {
    layout.begin().add(bgfx::Attrib::Position, 3, bgfx::AttribType::Float).end();
  }

  static bgfx::VertexLayout layout;
};

#endif//OZARKS_ENGINE_VERTEXLAYOUT_H
