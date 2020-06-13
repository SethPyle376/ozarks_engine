//
// Created by seth on 6/13/20.
//

#ifndef OZARKS_ENGINE_PROGRAMRESOURCE_H
#define OZARKS_ENGINE_PROGRAMRESOURCE_H

#include <bgfx/bgfx.h>
#include <core/resources/Resource.h>

class ProgramResource : public Resource {
  public:
      bgfx::ProgramHandle programHandle;
};

#endif//OZARKS_ENGINE_PROGRAMRESOURCE_H
