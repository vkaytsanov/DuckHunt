//
// Created by Viktor on 21.12.2020 г..
//

#ifndef DUCKHUNT_MATRIX4_H
#define DUCKHUNT_MATRIX4_H

#define A00 0
#define A01 1
#define A02 2
#define A03 3
#define A10 4
#define A11 5
#define A12 6
#define A13 7
#define A20 8
#define A21 9
#define A22 10
#define A23 11
#define A30 12
#define A31 13
#define A32 14
#define A33 15

/**
 *  [ A00 ] [ A01 ] [ A02 ] [ A03 ]     x
 *  [ A10 ] [ A11 ] [ A12 ] [ A13 ]     y
 *  [ A20 ] [ A21 ] [ A22 ] [ A23 ]     z
 *  [ A30 ] [ A31 ] [ A32 ] [ A33 ]     w
 *
 *  @param a - 4x4 array instead of matrix for memory reducement
 *
 */

template<typename T>
class Matrix4 {
private:
    T a[16];
public:
    Matrix4() {
        // Create identity matrix with 1's on the diagonal and 0's everywhere else
        a[A00] = 1; a[A01] = 0; a[A02] = 0; a[A03] = 0;
        a[A10] = 0; a[A11] = 1; a[A12] = 0; a[A13] = 0;
        a[A20] = 0; a[A21] = 0; a[A22] = 1; a[A23] = 0;
        a[A30] = 0; a[A31] = 0; a[A32] = 0; a[A33] = 1;
    }

    void setToOrthogonal2D(T x, T y, T width, T height){
        // in 2D we dont use the z coordinate, instead we use 0 for near clipping
        // plane that is at the start of the camera and 1 for far clipping plane
        setToOrthogonal(x, x + width, y, y + height, 0, 1);
    }

    /**  @link https://docs.microsoft.com/en-us/windows/win32/opengl/glortho */
    void setToOrthogonal(T left, T right, T bottom, T top, T near, T far) {
        // following the picture and formulas on the Microsoft's OpenGL page - glOrtho() function
        a[A00] =  2 / (right - left);
        a[A11] =  2 / (top - bottom);
        a[A22] = -2 / (far - near);

        a[A30] = -(right + left) / (right - left);
        a[A31] = -(top + bottom) / (top - bottom);
        a[A32] = -(far + near)   / (far - near);

        a[A33] =  1;
    }

    Matrix4<T>& operator*(const Matrix4<T>& mat) {
        for(int i = 0; i < 4; ++i)
            for(int j = 0; j < 4; ++j)
                for(int k = 0; k < 4; ++k)
                    a[i+j] += a[i + k] * mat[k + j];
        return *this;
    }

    Matrix4<T>& operator*(const T& scale){
        for(auto & i : a){
            i += i * scale;
        }
        return *this;
    }
};

typedef Matrix4<float> Matrix4f;
typedef Matrix4<int>   Matrix4i;

#endif //DUCKHUNT_MATRIX4_H
