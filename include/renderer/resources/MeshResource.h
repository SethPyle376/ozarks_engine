//
// Created by seth on 6/10/20.
//

#ifndef OZARKS_ENGINE_MESHRESOURCE_H
#define OZARKS_ENGINE_MESHRESOURCE_H

#include "core/resources/Resource.h"

#include "bgfx/bgfx.h"

class MeshResource : public Resource {
  private:
      std::string type = "mesh_resource";
  public:
    bgfx::VertexBufferHandle vbh;
    bgfx::IndexBufferHandle ibh;
};

#endif//OZARKS_ENGINE_MESHRESOURCE_H
