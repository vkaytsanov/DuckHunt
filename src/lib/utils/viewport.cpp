//
// Created by Viktor on 20.12.2020 г..
//
#include "SDL.h"
#include "SDL_opengl.h"
#include <cmath>
#include "include/viewport.h"

void Viewport::apply(bool centerCamera) const {
    glViewport(screenX, screenY, screenWidth, screenHeight);
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






