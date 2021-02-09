//
// Created by Viktor on 17.1.2021 г..
//

#include "include/mod_round.h"
#include "../include/game_utils.h"
#include "../graphics/windows/include/round_window.h"
#include "../graphics/screens/include/hud_renderer.h"

ModRound::ModRound(Gamelib* game) : game(game){

}

void ModRound::init() {
	game->dataSystem->currentGameData.round = 0;
}

void ModRound::update() {

}

void ModRound::post(Event* e) {
	if(e->name == "StartRound"){
		game->dataSystem->currentGameData.round++;
		displayNewRound();
		RoundWindow& roundWindow = game->graphicsSystem->getHudRenderer().roundWindow;
		roundWindow.update();
		roundWindow.setVisible(true);
	}
}

void ModRound::reinit() {
	init();
}

void ModRound::displayNewRound() {
	Label& roundLabel = game->graphicsSystem->getHudRenderer().roundLabel;
	roundLabel.setText(std::to_string(game->dataSystem->currentGameData.round));
	roundLabel.updateText();
}


