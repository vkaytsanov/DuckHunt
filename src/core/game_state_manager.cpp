//
// Created by Viktor on 17.12.2020 г..
//

#include "include/game_state_manager.h"

GameStateManager::GameStateManager(){
    currentState = new GameState(Loading);
}


GameState GameStateManager::getCurrentState() const {
    return *currentState;
}


void GameStateManager::changeState(const GameState nextState) {
    *currentState = nextState;
}

const char *GameStateManager::getCurrentStateName() const {
    switch ((*currentState)) {
        case Loading:
            return "Loading";
        case Menu:
            return "Menu";
        case Playing:
            return "Playing";
        default:
            return nullptr;
    }
}

GameStateManager::~GameStateManager() {
    delete currentState;
}



