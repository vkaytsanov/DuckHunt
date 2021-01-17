//
// Created by Viktor on 17.1.2021 г..
//

#include "include/mod_score.h"
#include "../../lib/include/lib.h"
#include "events/include/shot_fired.h"

void ModScore::init() {
	game.dataSystem->currentGameData.score = 0;
}

void ModScore::update() {

}

void ModScore::post(Event* e) {
	if(e->type == EventType::ShotFiredType){
		ShotFired* s = static_cast<ShotFired*>(e);
		if(s->duck){
			game.dataSystem->currentGameData.score += s->duck->getScore();
		}
		Lib::app->log("Score", game.dataSystem->currentGameData.score);
	}
}

void ModScore::reinit() {
	init();
}

ModScore::ModScore(Gamelib& game) : game(game){

}
