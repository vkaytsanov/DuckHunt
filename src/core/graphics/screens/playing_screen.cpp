//
// Created by Viktor on 13.1.2021 г..
//

#include "include/playing_screen.h"
#include "../../../lib/include/lib.h"


PlayingScreen::PlayingScreen(Gamelib &game) : game(game), hudRenderer(game), gameObjectRenderer(game){
    background.setTexture(game.dataSystem->assets.getSprite("playing-screen-background"));

    background.setWidth(GRAPHICS_WIDTH);
    background.setHeight(GRAPHICS_WIDTH / 2);
    background.setX(0);
    background.setY(GRAPHICS_HEIGHT - background.getHeight());

}

void PlayingScreen::render(const float &dt) {
    SDL_SetRenderDrawColor(Lib::graphics->getRenderer(), 0x32, 0xb5, 0xfc, 0xff);
    SDL_RenderClear(Lib::graphics->getRenderer());

    background.draw();
	gameObjectRenderer.draw(dt);
	hudRenderer.draw(dt);
}
