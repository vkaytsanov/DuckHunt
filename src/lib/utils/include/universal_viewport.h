//
// Created by Viktor on 20.12.2020 г..
//

#ifndef DUCKHUNT_UNIVERSAL_VIEWPORT_H
#define DUCKHUNT_UNIVERSAL_VIEWPORT_H


#include "viewport.h"
#include <cmath>

class UniversalViewport : public Viewport{
private:
    float minWorldWidth;
    float minWorldHeight;
public:
    UniversalViewport(float minWorldWidth, float minWorldHeight, SDL_Renderer* renderer);
    void update(int screenWidth, int screenHeight, bool centerCamera) override;
    float getMinWorldWidth() const;
    void setMinWorldWidth(float minWorldWidth);
    float getMinWorldHeight() const;
    void setMinWorldHeight(float minWorldHeight);
};


#endif //DUCKHUNT_UNIVERSAL_VIEWPORT_H
