//
// Created by Viktor on 17.12.2020 г..
//

#include "include/loading_screen.h"


LoadingScreen::LoadingScreen(Gamelib &game) : game(game) {
    isReady = true;
}

void LoadingScreen::render(const float& dt) {
    if(isReady){
        game.gameStateManager->changeState(Menu);
    }
}


