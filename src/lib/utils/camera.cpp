//
// Created by Viktor on 21.12.2020 г..
//

#include "include/camera.h"
#include "geometry/include/vector3.h"

Camera::Camera() {
    pos = new Vector3f();
    view = new Matrix4f();
    combined = new Matrix4f();
    projection = new Matrix4f();
    viewportWidth = 0;
    viewportHeight = 0;
}


Camera::~Camera() {
    delete pos;
    delete view;
    delete combined;
    delete projection;
}


