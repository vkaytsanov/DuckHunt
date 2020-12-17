#include "include/duckhunt.h"



DuckHunt::DuckHunt() : gameStateManager(), graphicsSystem(), logicSystem(){}

void DuckHunt::create() {
//    Lib::app->log("Current State", gameStateManager.getCurrentStateName());
//    Lib::app->error("Current State", gameStateManager.getCurrentStateName());
}

void DuckHunt::render() {
    const float dt =  0.11;
    logicSystem.update();
    graphicsSystem.render(gameStateManager.getCurrentState(), dt);
}

void DuckHunt::dispose() {
}




