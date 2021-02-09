//
// Created by Viktor on 25.1.2021 г..
//

#include "include/mod_duck_tracker.h"
#include "../include/game_utils.h"
#include "events/include/shot_fired.h"
#include "scripts/include/dog_reaction_script.h"
#include "../../lib/include/lib.h"


ModDuckTracker::ModDuckTracker(Gamelib* game) : game(game){

}

void ModDuckTracker::init() {
	for(auto& duckTracker : game->dataSystem->currentGameData.ducksTracker){
		duckTracker = ESCAPED;
	}
}

void ModDuckTracker::update() {

}

void ModDuckTracker::post(Event* e) {
	if(e->name == "StartRound"){
		init();
	}
	if(e->name == "ShotFired"){
		auto* s = dynamic_cast<ShotFired*>(e);
		if (s->duck) {
			game->dataSystem->currentGameData.setDuckKilled();
			if (game->dataSystem->currentGameData.ducksAlive == 0) {
				game->logicSystem->addScript(new DogReactionScript(game));
				Lib::input->setProcessor(nullptr);
			}
		}
	}
}

void ModDuckTracker::reinit() {
	init();
}



