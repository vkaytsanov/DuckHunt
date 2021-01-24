//
// Created by Viktor on 17.1.2021 г..
//

#include "include/mod_shots.h"
#include "../include/game_utils.h"
#include "scripts/include/dog_reaction_script.h"
#include "../../lib/include/lib.h"

void ModShots::init() {
	game.dataSystem->currentGameData.shots = 3;
}

void ModShots::update() {

}

void ModShots::post(Event* e) {
	if(e->name == "ShotFired"){
		game.dataSystem->currentGameData.shots--;
		game.audioSystem->stopSound(GUNSHOT);
		game.audioSystem->playSound(GUNSHOT);
	}
}

void ModShots::reinit() {
	init();
}

ModShots::ModShots(Gamelib& game) : game(game){

}
