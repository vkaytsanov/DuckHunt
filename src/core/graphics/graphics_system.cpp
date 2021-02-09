//
// Created by Viktor on 17.12.2020 г..
//

#include <iostream>
#include "include/graphics_system.h"
#include "screens/include/loading_screen.h"
#include "../../lib/include/lib.h"
#include "screens/include/playing_screen.h"


int GRAPHICS_WIDTH;
int GRAPHICS_HEIGHT;
float WORLD_WIDTH = 240;
float WORLD_HEIGHT = 120;

GraphicsSystem::GraphicsSystem(Gamelib* game) : game(game),
        viewport(WORLD_WIDTH, WORLD_HEIGHT) {
	fonts = new Fonts();
    GRAPHICS_WIDTH = Lib::graphics->getWidth();
    GRAPHICS_HEIGHT = Lib::graphics->getHeight();
    viewport.update(GRAPHICS_WIDTH, GRAPHICS_HEIGHT, false);
    screens[Loading] = new LoadingScreen(game);
    screens[Playing] = new PlayingScreen(game, fonts);
    screens[Menu] = new MenuScreen(game, fonts);
}

void GraphicsSystem::render(const float dt) {
    screens[game->gameStateManager->getCurrentState()]->render(dt);
}

void GraphicsSystem::resizeViewport(const int width, const int height) {
    viewport.update(width, height, false);
}

void GraphicsSystem::start(int state) {
	screens[state]->start();
}

HudRenderer& GraphicsSystem::getHudRenderer() {
	return ((PlayingScreen*) screens[Playing])->hudRenderer;
}

AbstractScreen* GraphicsSystem::getScreen(int state) {
	return screens[state];
}

GraphicsSystem::~GraphicsSystem() {
	for(auto& screen : screens){
		delete screen;
	}
	delete fonts;
}




