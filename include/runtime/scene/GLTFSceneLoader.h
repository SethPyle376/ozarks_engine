//
// Created by seth on 6/15/20.
//

#ifndef OZARKS_ENGINE_GLTFSCENELOADER_H
#define OZARKS_ENGINE_GLTFSCENELOADER_H

#include <string>

#include "assimp/postprocess.h"
#include "assimp/pbrmaterial.h"
#include "assimp/Importer.hpp"
#include "assimp/material.h"
#include "assimp/scene.h"

#include <bx/allocator.h>
#include <core/types/Actor.h>

class GLTFSceneLoader {
  private:
      static bx::DefaultAllocator allocator;
  public:
    static void loadScene(std::string filename, Actor *rootActor);
};


#endif//OZARKS_ENGINE_GLTFSCENELOADER_H
