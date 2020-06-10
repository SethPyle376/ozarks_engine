//
// Created by seth on 6/9/20.
//

#ifndef OZARKS_ENGINE_RESOURCEHANDLE_H
#define OZARKS_ENGINE_RESOURCEHANDLE_H

#include <string>
#include <cstdint>

class ResourceHandle {
  private:
      std::string path;
      std::string type;
  public:
    Resource* resource;
};


#endif//OZARKS_ENGINE_RESOURCEHANDLE_H
