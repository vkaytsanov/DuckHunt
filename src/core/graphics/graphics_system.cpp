//
// Created by Viktor on 17.12.2020 г..
//

#include <iostream>
#include "include/graphics_system.h"
#include "include/loading_screen.h"
#include "../../lib/include/lib.h"

int GRAPHICS_WIDTH;
int GRAPHICS_HEIGHT;
float WORLD_WIDTH = 240;
float WORLD_HEIGHT = 120;

GraphicsSystem::GraphicsSystem(Gamelib &game) : game(game),
        viewport(WORLD_WIDTH, WORLD_HEIGHT, Lib::graphics->getRenderer()) {
    GRAPHICS_WIDTH = Lib::graphics->getWidth();
    GRAPHICS_HEIGHT = Lib::graphics->getHeight();
    viewport.update(GRAPHICS_WIDTH, GRAPHICS_HEIGHT, true);
    screens[Loading] = new LoadingScreen(game);
    screens[Menu] = new MenuScreen(game);
}

void GraphicsSystem::render(const float& dt) {
    screens[game.gameStateManager->getCurrentState()]->render(dt);
}

void GraphicsSystem::resizeViewport(const int &width, const int &height) {
    viewport.update(width, height, true);
}



