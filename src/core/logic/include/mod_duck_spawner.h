//
// Created by Viktor on 15.1.2021 г..
//

#ifndef MOD_DUCK_SPAWNER_H
#define MOD_DUCK_SPAWNER_H

#include "mod_logic.h"
#include "../../game_object/include/duck.h"

class Gamelib;

enum DifficultyLevel{
	ONE_DUCK = 1,
	TWO_DUCKS = 2
};
class ModDuckSpawner : public ModLogic{
private:
	Gamelib& game;
	int ducksPerSpawn;
	int ducksSpawned;
	int ducksAlive;
	int ducksCount;
	bool canSpawn;
	void spawn(Duck* duck);
	DifficultyLevel currentDifficultyLevel;
public:
	explicit ModDuckSpawner(Gamelib& game);
	void init() override;
	void update() override;
	void post(Event* e) override;
	void reinit() override;
	void setCurrentDifficultyLevel(DifficultyLevel currentDifficultyLevel);
};


#endif //MOD_DUCK_SPAWNER_H
