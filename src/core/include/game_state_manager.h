//
// Created by Viktor on 17.12.2020 г..
//
#ifndef DUCKHUNT_GAME_STATE_MANAGER_H
#define DUCKHUNT_GAME_STATE_MANAGER_H


enum GameState {
    Loading,
    Menu,
};


class GameStateManager {
private:
    GameState currentState;
public:
    GameStateManager();
    GameState getCurrentState() const;
    const char* getCurrentStateName() const;
    void changeState(GameState nextState);
};


#endif //DUCKHUNT_GAME_STATE_MANAGER_H
