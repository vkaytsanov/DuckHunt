//
// Created by Viktor on 20.12.2020 г..
//

#include "include/viewport.h"

void Viewport::apply(bool centerRenderer) {
    SDL_Rect viewportRect;
    viewportRect.w = (int) worldWidth;
    viewportRect.h = (int) worldHeight;
    if(centerRenderer){
        viewportRect.x = (int) worldWidth / 2;
        viewportRect.y = (int) worldHeight / 2;
    }
    else{
        viewportRect.x = 0;
        viewportRect.y = 0;
    }
    // this function is commented because it doesnt set a viewport, but clips the window to the
    // viewportRect dimensions
//    SDL_RenderSetViewport(renderer, &viewportRect);
}

SDL_Renderer *Viewport::getRenderer() const {
    return renderer;
}

void Viewport::setRenderer(SDL_Renderer *renderer) {
    Viewport::renderer = renderer;
}

float Viewport::getWorldWidth() const {
    return worldWidth;
}

void Viewport::setWorldWidth(float worldWidth) {
    Viewport::worldWidth = worldWidth;
}

float Viewport::getWorldHeight() const {
    return worldHeight;
}

void Viewport::setWorldHeight(float worldHeight) {
    Viewport::worldHeight = worldHeight;
}

void Viewport::setWorldSize(float& worldWidth, float& worldHeight) {
    this->worldWidth = worldWidth;
    this->worldHeight = worldHeight;
}

void Viewport::setScreenBounds(const int x, const int y, const int& width, const int& height) {
    screenX = x;
    screenY = y;
    screenWidth = width;
    screenHeight = height;
}


