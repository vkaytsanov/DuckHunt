//
// Created by Viktor on 17.12.2020 г..
//
#ifndef DUCKHUNT_GRAPHICS_SYSTEM_H
#define DUCKHUNT_GRAPHICS_SYSTEM_H


#include <unordered_map>
#include "menu_screen.h"
#include "abstract_screen.h"
#include "../../include/game_state_manager.h"


class GraphicsSystem {
private:
    std::unordered_map<GameState, AbstractScreen*> screens;
public:
    GraphicsSystem();
    void render(const GameState& currState, const float& dt);

};


#endif //DUCKHUNT_GRAPHICS_SYSTEM_H
