#include <iostream>
#include "include/duckhunt.h"
#include "../lib/include/lib.h"


void DuckHunt::create() {
    Gamelib::create();
	logicSystem->init();
	audioSystem->playMusic(TITLE);
}

void DuckHunt::render() {
    const float dt = Lib::graphics->getDeltaTime();
    logicSystem->update();
    graphicsSystem->render(dt);
}

void DuckHunt::resize(const int &width, const int &height) {
    graphicsSystem->resizeViewport(width, height);
}

DuckHunt::~DuckHunt() {
	delete graphicsSystem;
	delete logicSystem;
}

void DuckHunt::pause() {

}

void DuckHunt::resume() {

}









