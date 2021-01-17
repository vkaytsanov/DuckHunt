//
// Created by Viktor on 17.1.2021 г..
//

#include "include/mod_round.h"

void ModRound::init() {
	game.dataSystem->currentGameData.round = 0;
}

void ModRound::update() {

}

void ModRound::post(Event* e) {
	if(e->type == StartRoundType){
		game.dataSystem->currentGameData.round++;
	}
}

void ModRound::reinit() {
	init();
}

ModRound::ModRound(Gamelib& game) : game(game){

}
