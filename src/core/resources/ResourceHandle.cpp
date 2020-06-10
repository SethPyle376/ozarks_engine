//
// Created by seth on 6/10/20.
//

#include "core/resources/ResourceHandle.h"
#include "core/resources/ResourceManager.h"

ResourceHandle::~ResourceHandle() {
  ResourceManager::getInstance()->destroyResource(this);
}