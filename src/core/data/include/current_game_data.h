//
// Created by Viktor on 17.1.2021 г..
//

#ifndef CURRENT_GAME_DATA_H
#define CURRENT_GAME_DATA_H


enum DuckTracker{
	ESCAPED,
	KILLED
};

enum DifficultyLevel{
	ONE_DUCK = 1,
	TWO_DUCKS = 2,
	NONE
};

class CurrentGameData {
public:
	int score;
	int round;
	int shots;
	int ducksAlive;
	int ducksSpawnedTotal;
	int minimumDucksToAdvance;
	DifficultyLevel difficultyLevel;
	DuckTracker ducksTracker[10];
};


#endif //CURRENT_GAME_DATA_H
