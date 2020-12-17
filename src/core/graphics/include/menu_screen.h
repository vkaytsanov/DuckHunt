//
// Created by Viktor on 17.12.2020 г..
//

#ifndef DUCKHUNT_MENU_SCREEN_H
#define DUCKHUNT_MENU_SCREEN_H


#include "abstract_screen.h"

class MenuScreen : public AbstractScreen{
public:
    MenuScreen();
    void render() override;
};


#endif //DUCKHUNT_MENU_SCREEN_H
