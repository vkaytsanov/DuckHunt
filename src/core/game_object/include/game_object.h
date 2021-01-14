//
// Created by Viktor on 18.12.2020 г..
//

#ifndef DUCKHUNT_GAME_OBJECT_H
#define DUCKHUNT_GAME_OBJECT_H


#include <SDL.h>

static const float DEFAULT_MOVE_SPEED = 150.0f;

class GameObject {
private:
    float dx;
    float dy;
    SDL_FRect rect;
protected:
    float x;
    float y;
    float width;
    float height;
public:
    GameObject() = default;
    GameObject(float x, float y);
    float getX() const;
    float getY() const;
    float getWidth() const;
    float getHeight() const;
    float getDx() const;
    float getDy() const;
    const SDL_FRect &getRect() const;

    void setX(float x);
    void setY(float y);
    void setWidth(float width);
    void setHeight(float height);
};


#endif //DUCKHUNT_GAME_OBJECT_H
