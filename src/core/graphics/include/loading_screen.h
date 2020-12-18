//
// Created by Viktor on 17.12.2020 г..
//

#ifndef DUCKHUNT_LOADING_SCREEN_H
#define DUCKHUNT_LOADING_SCREEN_H


#include "abstract_screen.h"
#include "../include/game_utils.h"

class LoadingScreen : public AbstractScreen{
private:
    GameUtils& game;
    bool isReady;
public:
    explicit LoadingScreen(GameUtils& game);
    void render(const float& dt) override;
};


#endif //DUCKHUNT_LOADING_SCREEN_H
