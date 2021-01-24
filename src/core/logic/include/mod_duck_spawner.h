//
// Created by Viktor on 15.1.2021 г..
//

#ifndef MOD_DUCK_SPAWNER_H
#define MOD_DUCK_SPAWNER_H

#include <random>
#include "mod_logic.h"
#include "../../game_object/include/duck.h"

class Gamelib;

enum DifficultyLevel{
	ONE_DUCK = 1,
	TWO_DUCKS = 2,
	NONE
};

const int BLACK_DUCK_SPAWN_RATE = 70;
const int BLUE_DUCK_SPAWN_RATE = BLACK_DUCK_SPAWN_RATE + 20;
const int RED_DUCK_SPAWN_RATE = BLACK_DUCK_SPAWN_RATE + BLUE_DUCK_SPAWN_RATE + 10;



class ModDuckSpawner : public ModLogic{
private:
	Gamelib& game;
	std::mt19937 generator;
	const std::uniform_int_distribution<int> dist;
	int ducksPerSpawn;
	int ducksAlive;
	int ducksCount;
	bool canSpawn;
	int lastBlackDuckIndex;
	int lastBlueDuckIndex;
	int lastRedDuckIndex;
	int getCandidate(const int& percent);
	void spawn(Duck* duck) const;
	DifficultyLevel currentDifficultyLevel;
public:
	explicit ModDuckSpawner(Gamelib& game);
	void init() override;
	void update() override;
	void post(Event* e) override;
	void reinit() override;
	void setCurrentDifficultyLevel(const DifficultyLevel difficulty);
};


#endif //MOD_DUCK_SPAWNER_H
