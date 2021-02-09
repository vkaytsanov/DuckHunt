//
// Created by Viktor on 18.12.2020 г..
//

#ifndef DUCKHUNT_game_utils_H
#define DUCKHUNT_game_utils_H


#include "game_state_manager.h"
#include "../data/include/data_system.h"
#include "../graphics/include/graphics_system.h"
#include "../logic/include/logic_system.h"
#include "../audio/include/audio_system.h"

class Gamelib{
protected:
    void create();
public:
	LogicSystem* logicSystem;
	GraphicsSystem* graphicsSystem;
    GameStateManager* gameStateManager;
    DataSystem* dataSystem;
    AudioSystem* audioSystem;
    ~Gamelib();
};


#endif //DUCKHUNT_game_utils_H
