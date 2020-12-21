//
// Created by Viktor on 21.12.2020 г..
//

#ifndef DUCKHUNT_ORTHOGRAPHIC_CAMERA_H
#define DUCKHUNT_ORTHOGRAPHIC_CAMERA_H


#include "include/camera.h"

class OrthographicCamera : public Camera{
public:
    OrthographicCamera(float viewportWidth, float viewportHeight);
    void update() override;

};


#endif //DUCKHUNT_ORTHOGRAPHIC_CAMERA_H
