//
// Created by seth on 6/10/20.
//

#ifndef OZARKS_ENGINE_RESOURCEREFCOUNTER_H
#define OZARKS_ENGINE_RESOURCEREFCOUNTER_H

#include <unordered_map>

enum CounterResult {
  RESOURCE_OK,
  RESOURCE_NEEDS_DELETED
};

class ResourceRefCounter {
  private:
      std::unordered_map<std::string, uint32_t> refMap;
  public:
      void incrementResourceCount(std::string path);
      CounterResult decrementResourceCount(std::string path);
};

#endif//OZARKS_ENGINE_RESOURCEREFCOUNTER_H
