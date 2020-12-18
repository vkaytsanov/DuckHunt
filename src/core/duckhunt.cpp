#include <iostream>
#include "include/duckhunt.h"
#include "../utils/include/lib.h"


DuckHunt::DuckHunt() : gameStateManager(), graphicsSystem(), logicSystem(){}

void DuckHunt::create() {
    Lib::app->log("Current State", gameStateManager.getCurrentStateName());
    Lib::app->error("Current State", gameStateManager.getCurrentStateName());
    std::cout << Lib::graphics->getDeltaTime() << std::endl;
}

void DuckHunt::render() {
    const float dt =  Lib::graphics->getDeltaTime();
    logicSystem.update();
    graphicsSystem.render(gameStateManager.getCurrentState(), dt);
}

void DuckHunt::dispose() {
}




