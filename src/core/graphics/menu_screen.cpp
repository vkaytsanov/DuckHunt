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
//    SDL_SetRenderDrawColor(Lib::graphics->getRenderer(), 255, 0, 0, 255);
//    SDL_Rect rect;
//    rect.x = 0;
//    rect.y = 0;
//    rect.w = GRAPHICS_WIDTH;
//    rect.y = GRAPHICS_HEIGHT;
//    SDL_RenderFillRect(Lib::graphics->getRenderer(), &rect);
//    SDL_RenderPresent(Lib::graphics->getRenderer());

    logo->draw(0, 0, (int) WORLD_WIDTH, (int) WORLD_HEIGHT);
}


