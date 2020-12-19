//
// Created by Viktor on 17.12.2020 г..
//

#ifndef DUCKHUNT_MENU_SCREEN_H
#define DUCKHUNT_MENU_SCREEN_H

#include "abstract_screen.h"
#include "../include/game_utils.h"

class MenuScreen : public AbstractScreen{
private:
    Texture* logo;
    GameUtils& game;
public:
    explicit MenuScreen(GameUtils& game);
    void render(const float& dt) override;
};


#endif //DUCKHUNT_MENU_SCREEN_H
