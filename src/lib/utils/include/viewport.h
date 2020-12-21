//
// Created by Viktor on 20.12.2020 г..
//

#ifndef DUCKHUNT_VIEWPORT_H
#define DUCKHUNT_VIEWPORT_H

#include "SDL.h"

class Viewport {
private:
    SDL_Renderer* renderer;
    float worldWidth;
    float worldHeight;
    int screenX;
    int screenY;
    int screenWidth;
    int screenHeight;
protected:
    void setScreenBounds(int x, int y, const int& width, const int& height);
public:
    virtual void update(int screenWidth, int screenHeight, bool centerCamera) = 0;
    void apply(bool centerRenderer);
    void setRenderer(SDL_Renderer *renderer);
    void setWorldWidth(float worldWidth);
    void setWorldHeight(float worldHeight);
    void setWorldSize(float& worldWidth, float& worldHeight);
    SDL_Renderer *getRenderer() const;
    float getWorldWidth() const;
    float getWorldHeight() const;
};


#endif //DUCKHUNT_VIEWPORT_H
