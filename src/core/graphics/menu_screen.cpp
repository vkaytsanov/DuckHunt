//
// Created by Viktor on 17.12.2020 г..
//

#include "include/menu_screen.h"
#include "include/graphics_system.h"


MenuScreen::MenuScreen(GameUtils& game) : game(game){
    logo = game.dataSystem->assets.getSprite("logo");
}


void MenuScreen::render(const float& dt) {
    logo->draw(GRAPHICS_WIDTH/2 - logo->getWidth()/2, 0, logo->getWidth(), logo->getHeight());
}


