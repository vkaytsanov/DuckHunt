//
// Created by Viktor on 17.12.2020 г..
//

#include "include/graphics_system.h"
#include "loading_screen.h"

GraphicsSystem::GraphicsSystem() {
    screens[Loading] = new LoadingScreen();
    screens[Menu] = new MenuScreen();
}

void GraphicsSystem::render() {

}


