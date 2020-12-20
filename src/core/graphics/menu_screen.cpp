//
// Created by Viktor on 17.12.2020 г..
//

#include "include/menu_screen.h"
#include "include/graphics_system.h"
#include "../../lib/include/lib.h"


MenuScreen::MenuScreen(Gamelib& game) : game(game){
    logo = game.dataSystem->assets.getSprite("logo");
}


void MenuScreen::render(const float& dt) {
    SDL_SetRenderDrawColor(Lib::graphics->getRenderer(), 0, 0, 0, 255);
    SDL_RenderClear(Lib::graphics->getRenderer());
    logo->draw(GRAPHICS_WIDTH/2 - logo->getWidth()/2, 0, logo->getWidth(), logo->getHeight());
}


