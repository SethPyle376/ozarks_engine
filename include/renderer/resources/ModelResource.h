//
// Created by seth on 6/11/20.
//

#ifndef OZARKS_ENGINE_MODELRESOURCE_H
#define OZARKS_ENGINE_MODELRESOURCE_H

#include "core/resources/Resource.h"
#include <core/resources/ResourceHandle.h>

class ModelResource : public Resource {
  public:
      ResourceHandle meshHandle;
      ResourceHandle materialHandle;
};

#endif//OZARKS_ENGINE_MODELRESOURCE_H
