//
// Created by Viktor on 18.12.2020 г..
//


#include "include/game_utils.h"

void Gamelib::create() {
    gameStateManager = new GameStateManager();
    dataSystem = new DataSystem();
	graphicsSystem = new GraphicsSystem(this);
	logicSystem = new LogicSystem(this);
	audioSystem = new AudioSystem();
}

Gamelib::~Gamelib() {
    delete gameStateManager;
    delete dataSystem;
	delete graphicsSystem;
	delete logicSystem;
    delete audioSystem;
}




