//
// Created by Viktor on 21.12.2020 г..
//

#ifndef DUCKHUNT_VECTOR3_H
#define DUCKHUNT_VECTOR3_H


#include "vector.h"



template <typename T>
class Vector3 : public Vector<T> {
public:
    T z;
    Vector3(){
        this->x = 0;
        this->y = 0;
        this->z = 0;
    }
    Vector3(T x, T y, T z){
        this->x = x;
        this->y = y;
        this->z = z;
    }
    Vector3<T> operator+(const Vector3<T>& vec) {
        return Vector3<T>(this->x + vec.x, this->y + vec.y, this->z + vec.z);
    }
    Vector3<T> operator-(const Vector3<T>& vec){
        return Vector3<T>(this->x - vec.x, this->y - vec.y, this->z - vec.z);
    }
    Vector3<T> operator*(const Vector3<T>& vec){
        return Vector3<T>(this->x * vec.x, this->y * vec.y, this->z * vec.z);
    }
    Vector3<T> operator/(const Vector3<T>& vec) {
        return Vector3<T>(this->x / vec.x, this->y / vec.y, this->z / vec.z);
    }
};

typedef Vector3<float> Vector3f;
typedef Vector3<int>   Vector3i;

#endif //DUCKHUNT_VECTOR3_H
