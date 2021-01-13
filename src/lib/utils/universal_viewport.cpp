//
// Created by Viktor on 20.12.2020 г..
//

#include <iostream>
#include "../include/lib.h"
#include "include/universal_viewport.h"


UniversalViewport::UniversalViewport(const float minWorldWidth, const float minWorldHeight){
    this->minWorldWidth = minWorldWidth;
    this->minWorldHeight = minWorldHeight;
}


float UniversalViewport::getMinWorldWidth() const {
    return minWorldWidth;
}

void UniversalViewport::setMinWorldWidth(float minWorldWidth) {
    UniversalViewport::minWorldWidth = minWorldWidth;
}

float UniversalViewport::getMinWorldHeight() const {
    return minWorldHeight;
}

void UniversalViewport::setMinWorldHeight(float minWorldHeight) {
    UniversalViewport::minWorldHeight = minWorldHeight;
}


void UniversalViewport::update(int screenWidth, int screenHeight, bool centerCamera) {
    float worldWidth = minWorldWidth;
    float worldHeight = minWorldHeight;

    const float screenRatio = (float) screenHeight / (float) screenWidth;
    const float worldRatio = worldHeight / worldWidth;
    const float scale = screenRatio > worldRatio ? (float) screenWidth / minWorldWidth : (float) screenHeight / minWorldHeight;

    int viewportWidth  = (int)std::round(worldWidth * scale);
    int viewportHeight = (int)std::round(worldHeight * scale);

    // Enlarging the viewport by its short side
    if(viewportWidth < screenWidth){
        float toViewportSpace = (float) viewportHeight / worldHeight;
        float toWorldSpace = worldHeight / (float) viewportHeight;
        float lengthen = (float) (screenWidth - viewportWidth) * toWorldSpace;
        worldWidth += lengthen;
        viewportWidth += (int)(lengthen * toViewportSpace);
    }
    else if(viewportHeight < screenHeight){
        float toViewportSpace = (float) viewportWidth / worldWidth;
        float toWorldSpace = worldWidth / (float) viewportWidth;
        float lengthen = (float) (screenHeight - viewportHeight) * toWorldSpace;
        worldHeight += lengthen;
        viewportHeight += (int)(lengthen * toViewportSpace);
    }
    std::cout << worldWidth << "\n";
    std::cout << worldHeight << "\n";
    setWorldSize(worldWidth, worldHeight);
    setScreenBounds( (screenWidth - viewportWidth) / 2, (screenHeight - viewportHeight) / 2, viewportWidth, viewportHeight);
    //apply(centerCamera);
}


