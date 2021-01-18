//
// Created by Viktor on 17.12.2020 г..
//

#ifndef DUCKHUNT_ABSTRACT_SCREEN_H
#define DUCKHUNT_ABSTRACT_SCREEN_H


#include "../../../../lib/utils/ui/include/user_interface.h"

class Gamelib;

class AbstractScreen {
protected:
    UserInterface userInterface;
public:
    AbstractScreen() = default;
    virtual ~AbstractScreen() = default;
    virtual void render(const float& dt) = 0;
    virtual void start();

};


#endif //DUCKHUNT_ABSTRACT_SCREEN_H
