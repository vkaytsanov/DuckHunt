//
// Created by Viktor on 18.12.2020 г..
//

#include "include/game_utils.h"

void Gamelib::create() {
    gameStateManager = new GameStateManager();
    dataSystem = new DataSystem();
}

Gamelib::~Gamelib() {
    delete gameStateManager;
    delete dataSystem;
}

Gamelib& Gamelib::operator=(const Gamelib &game)= default;



