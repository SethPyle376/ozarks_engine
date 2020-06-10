//
// Created by seth on 6/9/20.
//

#ifndef OZARKS_ENGINE_TESTRESOURCEFACTORY_H
#define OZARKS_ENGINE_TESTRESOURCEFACTORY_H

#include "core/resources/test/TestResource.h"
#include "core/resources/ResourceFactory.h"

class TestResourceFactory : public ResourceFactory {
  public:
      TestResourceFactory() {
        this->type = "test_resource";
      }

      Resource* loadResource(std::string path) override {
        return new TestResource();
      }
};

#endif//OZARKS_ENGINE_TESTRESOURCEFACTORY_H
