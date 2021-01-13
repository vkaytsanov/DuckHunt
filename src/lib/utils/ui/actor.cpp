//
// Created by Viktor on 12.1.2021 г..
//

#include "include/actor.h"

const std::vector<EventListener> &Actor::getListeners() const {
    return listeners;
}

void Actor::setListeners(const std::vector<EventListener> &listeners) {
    Actor::listeners = listeners;
}

float Actor::getX() const {
    return x;
}

void Actor::setX(float x) {
    Actor::x = x;
}

float Actor::getY() const {
    return y;
}

void Actor::setY(float y) {
    Actor::y = y;
}

void Actor::addListener(const EventListener &e) {
    listeners.emplace_back(e);
}

void Actor::act(float dt) {

}

Actor::Actor(const int ID) : ID(ID) {}

int Actor::getId() const {
    return ID;
}

void Actor::setId(int id) {
    ID = id;
}

float Actor::getWidth() const {
    return width;
}

float Actor::getHeight() const {
    return height;
}


void Actor::setWidth(float width) {
    Actor::width = width;
}

void Actor::setHeight(float height) {
    Actor::height = height;
}

bool Actor::isVisible() const {
    return visible;
}

void Actor::setVisible(bool visible) {
    Actor::visible = visible;
}

bool Actor::isInMouseBounds(const float& mouseX, const float& mouseY) {
    return  x < mouseX && mouseX < (x + width) &&
            y < mouseY && mouseY < (y + height);
}