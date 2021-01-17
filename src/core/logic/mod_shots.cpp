//
// Created by Viktor on 17.1.2021 г..
//

#include "include/mod_shots.h"

void ModShots::init() {
	game.dataSystem->currentGameData.shots = 3;
}

void ModShots::update() {

}

void ModShots::post(Event* e) {
	if(e->type == ShotFiredType){
		game.dataSystem->currentGameData.shots--;
	}
}

void ModShots::reinit() {
	init();
}

ModShots::ModShots(Gamelib& game) : game(game){

}
