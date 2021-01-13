//
// Created by Viktor on 13.1.2021 г..
//

#include "include/playing_screen.h"
#include "../../lib/include/lib.h"

PlayingScreen::PlayingScreen(Gamelib &game) : game(game){

}

void PlayingScreen::render(const float &dt) {
    SDL_SetRenderDrawColor(Lib::graphics->getRenderer(), 0x32, 0xb5, 0xfc, 0xff);
    SDL_RenderClear(Lib::graphics->getRenderer());
}
