//
// Created by seth on 6/15/20.
//

#include "runtime/scene/GLTFSceneLoader.h"

void GLTFSceneLoader::loadScene(std::string filename, Actor *rootActor) {
  Assimp::Importer importer;

  importer.SetPropertyInteger(AI_CONFIG_PP_SBP_REMOVE, aiPrimitiveType_LINE | aiPrimitiveType_POINT);
  importer.SetPropertyInteger(AI_CONFIG_PP_SLM_VERTEX_LIMIT, static_cast<int>(std::numeric_limits<uint16_t>::max()) + 1);

  unsigned int flags = aiProcessPreset_TargetRealtime_Quality | aiProcess_OptimizeMeshes | aiProcess_PreTransformVertices | aiProcess_FixInfacingNormals
                        | aiProcess_TransformUVCoords | aiProcess_MakeLeftHanded | aiProcess_FlipUVs;

  const aiScene *scene = nullptr;

  try {
    scene = importer.ReadFile(filename.c_str(), flags);
  } catch(const std::exception &e) {

  }
}