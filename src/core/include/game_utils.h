//
// Created by Viktor on 18.12.2020 г..
//

#ifndef DUCKHUNT_game_utils_H
#define DUCKHUNT_game_utils_H


#include "game_state_manager.h"
#include "../data/include/data_system.h"

class Gamelib {
private:
    Gamelib& operator=(const Gamelib& game);
protected:
    void create();
public:
    GameStateManager* gameStateManager;
    DataSystem* dataSystem;

    ~Gamelib();

};


#endif //DUCKHUNT_game_utils_H
