//
// Created by Viktor on 21.12.2020 г..
//

#ifndef DUCKHUNT_CAMERA_H
#define DUCKHUNT_CAMERA_H

#include "../geometry/include/matrix4.h"
#include "../geometry/include/vector3.h"

/**
 *  @pdf https://www.google.com/url?sa=t&rct=j&q=&esrc=s&source=web&cd=&ved=2ahUKEwjz_Y71-t7tAhVCPuwKHVgYCCoQFjACegQIARAC&url=https%3A%2F%2Fweb.cs.wpi.edu%2F~emmanuel%2Fcourses%2Fcs543%2Ff13%2Fslides%2Flecture04_p3.pdf&usg=AOvVaw3DhRKP2d1wamu2osZL4Ibp
 *  @link https://en.wikipedia.org/wiki/Viewing_frustum
 */


class Camera {
private:
    /** Camera position vector */
    Vector3f* pos;
    /** Camera view matrix */
    Matrix4f* view;
    /** Camera's combined matrix */
    Matrix4f* combined;
protected:
    /** Camera projection matrix */
    Matrix4f* projection;
public:
    float viewportWidth;
    float viewportHeight;
    Camera();
    ~Camera();
    virtual void update() = 0;
};


#endif //DUCKHUNT_CAMERA_H
