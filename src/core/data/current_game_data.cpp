//
// Created by Viktor on 17.1.2021 г..
//

#include "include/current_game_data.h"

bool CurrentGameData::shouldFlyAway() {
	return shots == 0 && ducksAlive != 0;
}

void CurrentGameData::setDuckKilled() {
	const int idx = ducksSpawnedTotal - ducksAlive;
	ducksTracker[idx] = KILLED;
	ducksAlive--;
}
