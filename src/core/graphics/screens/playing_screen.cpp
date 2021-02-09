//
// Created by Viktor on 13.1.2021 г..
//

#include "include/playing_screen.h"
#include "../../../lib/include/lib.h"


PlayingScreen::PlayingScreen(Gamelib* game, Fonts* fonts) : game(game), hudRenderer(game, fonts), gameObjectRenderer(game), shotsReceiver(game){
    background.setTexture(game->dataSystem->assets.getSprite("playing-screen-background"));

    background.setWidth((float) GRAPHICS_WIDTH);
    background.setHeight((float) GRAPHICS_WIDTH * 0.5f);
    background.setX(0);
    background.setY((float) GRAPHICS_HEIGHT - background.getHeight());
}

void PlayingScreen::start() {
	Lib::input->setProcessor(&shotsReceiver);
}

void PlayingScreen::render(const float dt) {
    SDL_SetRenderDrawColor(Lib::graphics->getRenderer(), 0x32, 0xb5, 0xfc, 0xff);
    SDL_RenderClear(Lib::graphics->getRenderer());

	Dog& dog = game->dataSystem->dogData.getDog();

    if(dog.isDrawBefore()){
	    if(dog.isVisible()) {
		    dog.processAnimation(dt);
		    dog.getCurrentFrame().draw((int) dog.getX(), (int) dog.getY(), (int) dog.getWidth(), (int) dog.getHeight());
	    }
    }
	gameObjectRenderer.draw(dt);
    background.draw();
	hudRenderer.draw(dt);


	if(!dog.isDrawBefore()) {
		if (dog.isVisible()) {
			dog.processAnimation(dt);
			dog.getCurrentFrame().draw((int) dog.getX(), (int) dog.getY(), (int) dog.getWidth(), (int) dog.getHeight());
		}
	}
}
