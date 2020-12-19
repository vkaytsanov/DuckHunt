//
// Created by Viktor on 18.12.2020 г..
//

#ifndef DUCKHUNT_GAME_UTILS_H
#define DUCKHUNT_GAME_UTILS_H


#include "game_state_manager.h"
#include "../data/include/data_system.h"

class GameUtils {
private:
    GameUtils& operator=(const GameUtils& game);
protected:
    void create();
public:
    GameStateManager* gameStateManager;
    DataSystem* dataSystem;

    ~GameUtils();

};


#endif //DUCKHUNT_GAME_UTILS_H
