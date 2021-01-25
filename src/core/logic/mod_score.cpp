//
// Created by Viktor on 17.1.2021 г..
//

#include "include/mod_score.h"
#include "../../lib/include/lib.h"
#include "events/include/shot_fired.h"
#include "../include/game_utils.h"
#include "../graphics/screens/include/hud_renderer.h"

ModScore::ModScore(Gamelib& game) : game(game){

}

void ModScore::init() {
	game.dataSystem->currentGameData.score = 0;
}

void ModScore::update() {

}

void ModScore::post(Event* e) {
	if(e->name == "ShotFired"){
		auto* s = dynamic_cast<ShotFired*>(e);
		if(s->duck){
			game.dataSystem->currentGameData.score = (game.dataSystem->currentGameData.score + s->duck->getScore()) % 100000;
			displayNewScore();
		}
		Lib::app->log("Score", game.dataSystem->currentGameData.score);
	}
}

void ModScore::reinit() {
	init();
	displayNewScore();
}

void ModScore::displayNewScore() const {
	int zeros = 0;
	int score = game.dataSystem->currentGameData.score;
	while(score){
		score /= 10;
		zeros++;
	}
	std::string displayScore;
	for(int i = 0; i < 6 - zeros; i++){
		displayScore += "0";
	}
	game.graphicsSystem->getHudRenderer().scoreLabel.setText(displayScore + std::to_string(game.dataSystem->currentGameData.score));
	game.graphicsSystem->getHudRenderer().scoreLabel.updateText();
}
