//
// Created by Viktor on 17.1.2021 г..
//

#include "include/mod_duck_movement.h"
#include "../../lib/include/lib.h"

ModDuckMovement::ModDuckMovement(Gamelib& game) : game(game){

}

void ModDuckMovement::init() {

}

void ModDuckMovement::update() {
	for(GameObject& duck : game.dataSystem->ducksDb.getDucks()){
		if(duck.wantsToMove()){
			move(duck, duck.getDX(), duck.getDY());
		}
	}
}

void ModDuckMovement::post(Event* e) {

}

void ModDuckMovement::reinit() {

}

void ModDuckMovement::move(GameObject& e, const float& dx, const float& dy) {
	if(dx != 0 || dy != 0){
		const float speed = e.getSpeed();
		e.setX(e.getX() + (dx * speed) * Lib::graphics->getDeltaTime());
		e.setY(e.getY() + (dy * speed) * Lib::graphics->getDeltaTime());
	}
	else{
		Lib::app->error("DuckMovement", "error");
	}
}


