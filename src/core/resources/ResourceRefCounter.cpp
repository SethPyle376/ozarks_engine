//
// Created by seth on 6/10/20.
//

#include "core/resources/ResourceRefCounter.h"

void ResourceRefCounter::incrementResourceCount(std::string path) {
  refMap[path]++;
}

CounterResult ResourceRefCounter::decrementResourceCount(std::string path) {
  refMap[path]--;
  if(refMap[path] <= 0) {
    return RESOURCE_NEEDS_DELETED;
  } else {
    return RESOURCE_OK;
  }
}