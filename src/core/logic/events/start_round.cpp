//
// Created by Viktor on 17.1.2021 г..
//

#include "include/start_round.h"

StartRound::StartRound() : Event("StartRound") {
	difficultyLevel = ONE_DUCK;
}

StartRound::StartRound(DifficultyLevel difficultyLevel) : Event("StartRound") {
	this->difficultyLevel = difficultyLevel;
}
