//
// Created by seth on 6/9/20.
//

#ifndef OZARKS_ENGINE_TESTRESOURCEFACTORY_H
#define OZARKS_ENGINE_TESTRESOURCEFACTORY_H

#include "TestResource.h"
#include "core/resources/ResourceFactory.h"

class TestResourceFactory : public ResourceFactory {
  public:
      Resource* loadResource(std::string path) {
        return new TestResource();
      }
};

#endif//OZARKS_ENGINE_TESTRESOURCEFACTORY_H
