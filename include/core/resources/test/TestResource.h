//
// Created by seth on 6/9/20.
//

#ifndef OZARKS_ENGINE_TESTRESOURCE_H
#define OZARKS_ENGINE_TESTRESOURCE_H

#include "core/resources/Resource.h"

class TestResource : public Resource {
  public:
      uint32_t testNum = 42;
};

#endif//OZARKS_ENGINE_TESTRESOURCE_H
