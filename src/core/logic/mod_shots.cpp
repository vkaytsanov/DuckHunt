//
// Created by Viktor on 17.1.2021 г..
//

#include "include/mod_shots.h"
#include "../include/game_utils.h"
#include "scripts/include/dog_reaction_script.h"
#include "../../lib/include/lib.h"
#include "scripts/include/fly_away_script.h"
#include "scripts/include/end_of_round_script.h"


ModShots::ModShots(Gamelib* game) : game(game){

}

void ModShots::init() {
	game->dataSystem->currentGameData.shots = 3;
}

void ModShots::update() {

}

void ModShots::post(Event* e) {
	if(e->name == "StartSpawning"){
		game->dataSystem->currentGameData.shots = 3;
	}
	if(e->name == "ShotFired"){
		game->audioSystem->stopSound(GUNSHOT);
		game->audioSystem->playSound(GUNSHOT);
		game->dataSystem->currentGameData.shots--;
		if(game->dataSystem->currentGameData.shouldFlyAway()){
			// fly away script
			game->logicSystem->addScript(new FlyAwayScript(game));
			Lib::input->setProcessor(nullptr);
		}
	}
}

void ModShots::reinit() {
	init();
}


