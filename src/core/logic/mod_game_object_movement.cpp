//
// Created by Viktor on 17.1.2021 г..
//

#include <iostream>
#include "include/mod_game_object_movement.h"
#include "../../lib/include/lib.h"
#include "../include/game_utils.h"

ModGameObjectMovement::ModGameObjectMovement(Gamelib& game) : game(game){

}

void ModGameObjectMovement::init() {

}

void ModGameObjectMovement::update() {
	for(Duck* duck : game.dataSystem->ducksDb.getDucks()){
		if(duck->wantsToMove() && duck->isVisible()){
			if(duck->getState() != SHOT && duck->getState() != DIED && duck->getState() != UP_FLYING) {
				keepInBounds(duck);
				duck->setFacing();
			}
			move(duck, duck->getDX(), duck->getDY());
		}
	}
	GameObject& dog = game.dataSystem->dogData.getDog();
	if(dog.wantsToMove()){
		move(&dog, dog.getDX(), dog.getDY());
	}
}


void ModGameObjectMovement::keepInBounds(GameObject* duck) {
	// checking if it is leaving the screen bounds
	const float& x = duck->getX();
	const float& y = duck->getY();
	const float& width = duck->getWidth();
	const float& height = duck->getHeight();


	// in the left or right
	if(x < 0 || x + width > (float) GRAPHICS_WIDTH) duck->setDX(-duck->getDX());
	// in top or bottom, including the bushes
	if(y < 0) duck->setDY(-duck->getDY());
	else if(y + height + 200 > (float) GRAPHICS_HEIGHT) duck->setDY(std::abs(duck->getDY()) * -1);

}

void ModGameObjectMovement::post(Event* e) {

}

void ModGameObjectMovement::reinit() {

}

void ModGameObjectMovement::move(GameObject* e, const float& dx, const float& dy) {
	if(dx != 0 || dy != 0){
		const float speed = e->getSpeed();
		e->setX(e->getX() + (dx * speed) * Lib::graphics->getDeltaTime());
		e->setY(e->getY() + (dy * speed) * Lib::graphics->getDeltaTime());
	}
}


