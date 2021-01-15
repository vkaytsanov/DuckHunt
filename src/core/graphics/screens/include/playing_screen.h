//
// Created by Viktor on 13.1.2021 г..
//

#ifndef PLAYING_SCREEN_H
#define PLAYING_SCREEN_H


#include "abstract_screen.h"
#include "../../include/graphics_system.h"
#include "../../../game_object/include/entity.h"
#include "../../include/duck_renderer.h"

class PlayingScreen : public AbstractScreen{
private:
    Gamelib& game;
    Entity background;
    DuckRenderer duckRenderer;
public:
    explicit PlayingScreen(Gamelib& game);
    void render(const float& dt) override;
};


#endif //PLAYING_SCREEN_H
