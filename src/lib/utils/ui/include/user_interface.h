//
// Created by Viktor on 12.1.2021 г..
//

#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H


#include <vector>
#include "actor.h"

class UserInterface {
private:
    // TODO Use KD/BVH Tree
    // Using pointers so we can use runtime polymorphism
    std::vector<Actor*> actors;
public:
    bool debug;
    void add(Actor& actor);
    void act(float dt);
    void draw();
};


#endif //USER_INTERFACE_H
