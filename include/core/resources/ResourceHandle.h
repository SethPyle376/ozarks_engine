//
// Created by seth on 6/9/20.
//

#ifndef OZARKS_ENGINE_RESOURCEHANDLE_H
#define OZARKS_ENGINE_RESOURCEHANDLE_H

#include <cstdint>
#include <string>

#include "Resource.h"

class ResourceHandle {
  public:
      ~ResourceHandle();

      std::string path;
      std::string type;
      Resource* resource;
};


#endif//OZARKS_ENGINE_RESOURCEHANDLE_H
