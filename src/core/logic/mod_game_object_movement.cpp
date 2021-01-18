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
//			if(duck->getState() == DIED){
////				int channel = game.audioSystem->getSoundChannel(FALLING);
////				if(channel == -1) channel = game.audioSystem->getFreeChannel();
////				game.audioSystem->playSound(FALLING, channel, false);
//			}
//			else if(duck->getState() == SHOT){
//				//game.audioSystem->stopSound(FLAPPING);
//			}

			move(duck, duck->getDX(), duck->getDY());
		}
	}
	GameObject& dog = game.dataSystem->dogData.getDog();
	if(dog.wantsToMove()){
		move(&dog, dog.getDX(), dog.getDY());
	}
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
//	else{
//		Lib::app->error("DuckMovement", "error");
//	}
}


