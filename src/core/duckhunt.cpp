#include <iostream>
#include "include/duckhunt.h"
#include "../lib/include/lib.h"


void DuckHunt::create() {
    Gamelib::create();
	logicSystem->init();
	audioSystem->playMusic(TITLE);
}

void DuckHunt::render() {
    logicSystem->update();
    graphicsSystem->render(Lib::graphics->getDeltaTime());
}

void DuckHunt::resize(const int width, const int height) {
    graphicsSystem->resizeViewport(width, height);
}

DuckHunt::~DuckHunt() = default;

void DuckHunt::pause() {

}

void DuckHunt::resume() {

}









