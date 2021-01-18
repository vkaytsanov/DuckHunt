//
// Created by Viktor on 15.1.2021 г..
//

#include "include/game_object_renderer.h"
#include "include/graphics_system.h"

GameObjectRenderer::GameObjectRenderer(Gamelib& game) : game(game){}

void GameObjectRenderer::draw(const float& dt) {
	for(Duck* duck : game.dataSystem->ducksDb.getDucks()){
		if(duck->isVisible()){
			drawObject(duck, dt);
		}
	}

}

void GameObjectRenderer::drawObject(EntityAnimated* e, const float& dt) {
	e->processAnimation(dt);
	if(e->isFacingLeft()){
		e->getCurrentFrame().draw(e->getX(), e->getY(), e->getWidth(), e->getHeight(), SDL_FLIP_HORIZONTAL);
	}
	else{
		e->getCurrentFrame().draw(e->getX(), e->getY(), e->getWidth(), e->getHeight());
	}
}


