//
// Created by Viktor on 18.1.2021 г..
//

#include "include/shots_receiver.h"
#include "../include/game_utils.h"
#include "../logic/events/include/shot_fired.h"

ShotsReceiver::ShotsReceiver(Gamelib& game) : game(game){

}


void ShotsReceiver::touchDown(SDL_Event& e, float x, float y) {
	if(game.dataSystem->currentGameData.shots > 0) {
		for (Duck* duck : game.dataSystem->ducksDb.getDucks()) {
			// check if the coordinates are over its rect
			if (duck->isVisible() && duck->isHit(x, y)) {
				game.logicSystem->post(new ShotFired(duck));
				return;
			}
		}
		// else nullptr;
		game.logicSystem->post(new ShotFired());
	}
}

void ShotsReceiver::touchUp(SDL_Event& e, float x, float y) {

}

void ShotsReceiver::keyDown(SDL_Event& e, int key) {

}

void ShotsReceiver::keyUp(SDL_Event& e, int key) {

}


