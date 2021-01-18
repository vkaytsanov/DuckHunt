//
// Created by Viktor on 17.1.2021 г..
//

#include "include/mod_round.h"
#include "../include/game_utils.h"

void ModRound::init() {
	game.dataSystem->currentGameData.round = -1;
}

void ModRound::update() {

}

void ModRound::post(Event* e) {
	if(e->name == "StartRound"){
		game.dataSystem->currentGameData.round++;
	}
}

void ModRound::reinit() {
	init();
}

ModRound::ModRound(Gamelib& game) : game(game){

}
