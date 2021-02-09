//
// Created by Viktor on 25.1.2021 г..
//

#include "include/mod_difficulty_controller.h"
#include "../include/game_utils.h"

ModDifficultyController::ModDifficultyController(Gamelib* game) : game(game){

}

void ModDifficultyController::init() {
	setMinimumDucksToAdvance(6);
	setDuckScores(500);
	resetDucksModSpeed();
}

void ModDifficultyController::update() {

}

void ModDifficultyController::post(Event* e) {
	if(e->name == "StartRound"){
		switch(game->dataSystem->currentGameData.round){
			case 6:
				setDuckScores(800);
				break;
			case 11:
				setDuckScores(1000);
				setMinimumDucksToAdvance(7);
				break;
			case 13:
				setMinimumDucksToAdvance(8);
				break;
			case 15:
				setMinimumDucksToAdvance(9);
				break;
			case 20:
				setMinimumDucksToAdvance(10);
				break;
			default:
				setDucksModSpeed(0.08f);
		}
	}
}

void ModDifficultyController::reinit() {

}

void ModDifficultyController::setDuckScores(const int score) {
	for(int i = 0; i < NUMBER_OF_DUCKS_PER_TYPE; i++){
		// black ducks
		game->dataSystem->ducksDb.getDucks()[i]->setScore(score);
		// blue ducks
		game->dataSystem->ducksDb.getDucks()[i + 2]->setScore(score * 2);
		// red ducks
		game->dataSystem->ducksDb.getDucks()[i + 4]->setScore(score * 3);
	}
}

void ModDifficultyController::setMinimumDucksToAdvance(const int minimum) {
	game->dataSystem->currentGameData.minimumDucksToAdvance = minimum;
}

void ModDifficultyController::setDucksModSpeed(const float additionalAmount) {
	for(Duck* duck : game->dataSystem->ducksDb.getDucks()){
		duck->setModSpeed(1.0f + additionalAmount);
	}
}

void ModDifficultyController::resetDucksModSpeed() {
	for(Duck* duck : game->dataSystem->ducksDb.getDucks()){
		duck->setModSpeed(1.0f);
	}
}
