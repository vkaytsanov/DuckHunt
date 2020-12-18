//
// Created by Viktor on 18.12.2020 г..
//

#include "include/game_object.h"

GameObject::GameObject(const float x, const float y) {
    this->x = x;
    this->y = y;
    rect.x = x;
    rect.y = y;

}

float GameObject::getX() const {
    return x;
}

float GameObject::getY() const {
    return y;
}

float GameObject::getWidth() const {
    return width;
}

float GameObject::getHeight() const {
    return height;
}

float GameObject::getDx() const {
    return dx;
}

float GameObject::getDy() const {
    return dy;
}

const SDL_FRect &GameObject::getRect() const {
    return rect;
}

void GameObject::setWidth(const float width) {
    this->width = width;
    rect.w = width;
}

void GameObject::setHeight(const float height) {
    this->height = height;
    rect.h = height;
}




