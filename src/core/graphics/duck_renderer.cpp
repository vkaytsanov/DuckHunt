//
// Created by Viktor on 15.1.2021 г..
//

#include "include/duck_renderer.h"
#include "include/graphics_system.h"

DuckRenderer::DuckRenderer(Gamelib& game) : game(game){}

void DuckRenderer::draw(const float& dt) {
	for(Duck& duck : game.dataSystem->ducksDb.getDucks()){
		if(duck.isVisible()){
			drawDuck(duck, dt);
		}
	}
}

void DuckRenderer::drawDuck(Duck& d, const float& dt) {
	d.processAnimation(dt);
	d.getCurrentFrame().draw(d.getX(), d.getY(), d.getWidth(), d.getHeight());
//	if(d.isFacingLeft()){
//	}
//	else{
//		d.getCurrentFrame().draw(d.getX(), d.getY(), d.getWidth(), d.getHeight());
//	}
}


