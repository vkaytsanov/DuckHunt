//
// Created by Viktor on 17.12.2020 г..
//

#include <iostream>
#include "include/graphics_system.h"
#include "include/loading_screen.h"
#include "../../utils/include/lib.h"

int GRAPHICS_WIDTH;
int GRAPHICS_HEIGHT;

GraphicsSystem::GraphicsSystem(GameUtils &game) : game(game) {
    GRAPHICS_WIDTH = Lib::graphics->getWidth();
    GRAPHICS_HEIGHT = Lib::graphics->getHeight();

    screens[Loading] = new LoadingScreen(game);
    screens[Menu] = new MenuScreen(game);
}

void GraphicsSystem::render(const float& dt) {
    screens[game.gameStateManager->getCurrentState()]->render(dt);
}



