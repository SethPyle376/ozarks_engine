//
// Created by seth on 6/13/20.
//

#ifndef OZARKS_ENGINE_RENDERWINDOW_H
#define OZARKS_ENGINE_RENDERWINDOW_H

#include <SDL_video.h>

class RenderWindow {
  public:
      int width, height;
      SDL_Window* window = NULL;
      RenderWindow(int width, int height) {
        this->width = width;
        this->height = height;
        window = SDL_CreateWindow("Ozarks Engine v0.1", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
      }
};

#endif//OZARKS_ENGINE_RENDERWINDOW_H
