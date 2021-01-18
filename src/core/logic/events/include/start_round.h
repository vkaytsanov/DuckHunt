//
// Created by Viktor on 17.1.2021 г..
//

#ifndef START_ROUND_H
#define START_ROUND_H


#include "event.h"
#include "../../include/mod_duck_spawner.h"

class StartRound : public Event{
public:
	DifficultyLevel difficultyLevel;
	StartRound();
	StartRound(DifficultyLevel difficultyLevel);
};


#endif //START_ROUND_H
