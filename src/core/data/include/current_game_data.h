//
// Created by Viktor on 17.1.2021 г..
//

#ifndef CURRENT_GAME_DATA_H
#define CURRENT_GAME_DATA_H


enum DuckTracker{
	ESCAPED,
	KILLED
};

class CurrentGameData {
public:
	int score = 0;
	int round = 0;
	int shots = 3;
	DuckTracker ducksTracker[10] = {ESCAPED};
};


#endif //CURRENT_GAME_DATA_H
