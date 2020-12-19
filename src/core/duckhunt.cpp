#include <iostream>
#include "include/duckhunt.h"
#include "../utils/include/lib.h"


void DuckHunt::create() {
    GameUtils::create();
    graphicsSystem = new GraphicsSystem(*this);
    logicSystem = new LogicSystem();

}

void DuckHunt::render() {
    const float dt = Lib::graphics->getDeltaTime();
    logicSystem->update();
    graphicsSystem->render(dt);
}

DuckHunt::~DuckHunt() {
    delete graphicsSystem;
    delete logicSystem;
}






