//
// Created by Viktor on 13.1.2021 г..
//

#ifndef PLAYING_SCREEN_H
#define PLAYING_SCREEN_H


#include "abstract_screen.h"
#include "graphics_system.h"

class PlayingScreen : public AbstractScreen{
private:
    Gamelib& game;
public:
    explicit PlayingScreen(Gamelib& game);
    void render(const float& dt) override;
};


#endif //PLAYING_SCREEN_H
