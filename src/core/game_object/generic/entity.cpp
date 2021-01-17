//
// Created by Viktor on 14.1.2021 г..
//

#include "include/entity.h"

Entity::Entity(float x, float y) : GameObject(x, y) {}

void Entity::setTexture(Texture *texture) {
    this->m_texture = texture;
}

Entity::Entity(Texture *texture, float x, float y) : GameObject(x, y) {
    this->m_texture = texture;
}

void Entity::draw() const {
    m_texture->draw(x, y, width, height);
}
