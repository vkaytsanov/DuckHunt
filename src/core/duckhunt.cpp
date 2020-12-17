#include "include/duckhunt.h"


DuckHunt::DuckHunt() : gameStateManager(), graphicsSystem(), logicSystem(){}

void DuckHunt::create(ApplicationInterface* Lib) {
	this->Lib = Lib;
    Lib->log("Current State", gameStateManager.getCurrentStateName());
}

void DuckHunt::render() {
    logicSystem.update();
    graphicsSystem.render();
}

void DuckHunt::dispose() {
}




