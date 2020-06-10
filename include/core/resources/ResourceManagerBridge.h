//
// Created by seth on 6/10/20.
//

#ifndef OZARKS_ENGINE_RESOURCEMANAGERBRIDGE_H
#define OZARKS_ENGINE_RESOURCEMANAGERBRIDGE_H

#include "core/resources/ResourceManager.h"

static void destroyResourceHandle(ResourceHandle* handle) {
  ResourceManager::getInstance()->destroyResource(handle);
}

#endif//OZARKS_ENGINE_RESOURCEMANAGERBRIDGE_H
