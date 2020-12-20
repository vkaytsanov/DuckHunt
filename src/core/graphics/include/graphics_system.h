//
// Created by Viktor on 17.12.2020 г..
//
#ifndef DUCKHUNT_GRAPHICS_SYSTEM_H
#define DUCKHUNT_GRAPHICS_SYSTEM_H


#include <unordered_map>
#include "menu_screen.h"
#include "abstract_screen.h"
#include "../../include/game_utils.h"

extern int GRAPHICS_WIDTH;
extern int GRAPHICS_HEIGHT;

class GraphicsSystem {
private:
    std::unordered_map<GameState, AbstractScreen*> screens;
    Gamelib& game;
public:

    explicit GraphicsSystem(Gamelib &game);
    void render(const float& dt);

};


#endif //DUCKHUNT_GRAPHICS_SYSTEM_H
