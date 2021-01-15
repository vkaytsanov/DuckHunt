//
// Created by Viktor on 13.1.2021 г..
//

#include "include/playing_screen.h"
#include "../../../lib/include/lib.h"
#include "../../game_object/include/black_duck.h"
#include "../../game_object/include/red_duck.h"
#include "../../game_object/include/blue_duck.h"

PlayingScreen::PlayingScreen(Gamelib &game) : game(game), duckRenderer(game){
    background.setTexture(game.dataSystem->assets.getSprite("playing-screen-background"));

    background.setWidth(GRAPHICS_WIDTH);
    background.setHeight(GRAPHICS_WIDTH / 2);
    background.setX(0);
    background.setY(GRAPHICS_HEIGHT - background.getHeight());

    BlackDuck duck;
    duck.setX(GRAPHICS_WIDTH / 2);
    duck.setY(GRAPHICS_HEIGHT / 2);
	duck.loadEntity(game.dataSystem->assets);
	duck.setVisible(true);
	duck.setFacingLeft(true);
	game.dataSystem->ducksDb.addDuck(duck);
}

void PlayingScreen::render(const float &dt) {
    SDL_SetRenderDrawColor(Lib::graphics->getRenderer(), 0x32, 0xb5, 0xfc, 0xff);
    SDL_RenderClear(Lib::graphics->getRenderer());

    background.draw();
	duckRenderer.draw(dt);

}
