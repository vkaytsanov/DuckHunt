//
// Created by Viktor on 21.12.2020 г..
//

#include "orthographic_camera.h"

OrthographicCamera::OrthographicCamera(const float viewportWidth, const float viewportHeight) {
    this->viewportWidth = viewportWidth;
    this->viewportHeight = viewportHeight;
    update();
}

void OrthographicCamera::update() {
    projection->setToOrthogonal(-viewportWidth/2,
                                viewportWidth/2,
                                -viewportHeight/2,
                                viewportHeight/2,
                                0,
                                1);
}
