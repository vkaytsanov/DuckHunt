//
// Created by Viktor on 14.1.2021 г..
//

#ifndef ENTITY_H
#define ENTITY_H


#include "game_object.h"
#include "../../../lib/utils/include/texture.h"

class Entity : public GameObject{
    Texture* m_texture;
public:
    Entity() = default;
    Entity(float x, float y);
    Entity(Texture* texture, float x, float y);
    void setTexture(Texture *texture);
    void draw() const;
};


#endif //ENTITY_H
