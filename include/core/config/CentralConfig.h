//
// Created by seth on 6/13/20.
//

#ifndef OZARKS_ENGINE_CENTRALCONFIG_H
#define OZARKS_ENGINE_CENTRALCONFIG_H

#include <string>
#include <vector>

#include "rapidjson/document.h"
#include "SDL.h"

class CentralConfig {
  private:
      static CentralConfig* instance;
  public:
      rapidjson::Document document;

      static CentralConfig* getInstance() {
        if (instance == nullptr) {
          instance = new CentralConfig();
        }
        return instance;
      }

      void load(std::string filename) {
        SDL_RWops *file = SDL_RWFromFile(filename.c_str(), "r");
        int size = SDL_RWsize(file);
        std::vector<char> buffer(size);
        SDL_RWread(file, buffer.data(), size, 1);
        SDL_RWclose(file);

        std::string resourceData(buffer.begin(), buffer.end());

        document.Parse(resourceData.c_str());
      }
};

CentralConfig* CentralConfig::instance = nullptr;

#endif//OZARKS_ENGINE_CENTRALCONFIG_H
