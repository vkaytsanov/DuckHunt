//
// Created by Viktor on 17.1.2021 г..
//

#include "include/mod_score.h"
#include "../../lib/include/lib.h"
#include "events/include/shot_fired.h"
#include "../include/game_utils.h"
#include "scripts/include/duck_dying_script.h"

void ModScore::init() {
	game.dataSystem->currentGameData.score = 0;
}

void ModScore::update() {

}

void ModScore::post(Event* e) {
	if(e->name == "ShotFired"){
		auto* s = static_cast<ShotFired*>(e);
		if(s->duck){
			Duck* duck = s->duck;
			game.dataSystem->currentGameData.score += duck->getScore();
			duck->setDY(0);
			duck->setDX(0);
			duck->setState(SHOT);
			game.audioSystem->stopSound(FLAPPING, game.audioSystem->duckOneChannel);
			game.audioSystem->playSound(FALLING, game.audioSystem->duckOneChannel);
			game.logicSystem->addScript(new DuckDyingScript(duck));
		}
		Lib::app->log("Score", game.dataSystem->currentGameData.score);
	}
}

void ModScore::reinit() {
	init();
}

ModScore::ModScore(Gamelib& game) : game(game){

}
