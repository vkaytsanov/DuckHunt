//
// Created by Viktor on 17.12.2020 г..
//

#ifndef DUCKHUNT_LOADING_SCREEN_H
#define DUCKHUNT_LOADING_SCREEN_H


#include "abstract_screen.h"


class LoadingScreen : public AbstractScreen{
private:
    Gamelib* game;
    bool isReady;
public:
    explicit LoadingScreen(Gamelib* game);
    void render(const float dt) override;
};


#endif //DUCKHUNT_LOADING_SCREEN_H
