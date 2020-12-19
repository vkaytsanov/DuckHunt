//
// Created by Viktor on 18.12.2020 г..
//

#include "include/game_utils.h"

void GameUtils::create() {
    gameStateManager = new GameStateManager();
    dataSystem = new DataSystem();
}

GameUtils::~GameUtils() {
    delete gameStateManager;
    delete dataSystem;
}

GameUtils& GameUtils::operator=(const GameUtils &game)= default;



