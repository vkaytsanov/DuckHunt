//
// Created by Viktor on 15.1.2021 г..
//

#include "include/mod_duck_spawner.h"
#include "../include/game_utils.h"
#include "../../lib/include/lib.h"
#include "events/include/shot_fired.h"
#include "scripts/include/dog_reaction_script.h"
#include "scripts/include/fly_away_script.h"
#include "scripts/include/end_of_round_script.h"


ModDuckSpawner::ModDuckSpawner(Gamelib& game) : game(game),
                                                generator(std::random_device()()),
                                                dist(0, 100) {
	lastBlackDuckIndex = -1;
	lastBlueDuckIndex = -1;
	lastRedDuckIndex = -1;
	canSpawn = false;
}

void ModDuckSpawner::init() {
	game.dataSystem->currentGameData.ducksAlive = 0;
	game.dataSystem->currentGameData.ducksSpawnedTotal = 0;

	canSpawn = false;
}

void ModDuckSpawner::update() {
	if (canSpawn) {
		canSpawn = false;
		const int ducksPerSpawn = game.dataSystem->currentGameData.difficultyLevel;

		for (int i = 0; i < ducksPerSpawn; i++) {
			const int idx = getCandidate(dist(generator));
			spawn(game.dataSystem->ducksDb.getDucks()[idx]);
		}

		game.dataSystem->currentGameData.ducksAlive = ducksPerSpawn;
		game.dataSystem->currentGameData.ducksSpawnedTotal += ducksPerSpawn;
	}
}

int ModDuckSpawner::getCandidate(const int& percent) {
	// 70% to spawn black duck
	if(percent < BLACK_DUCK_SPAWN_RATE){
		return DucksDB::getBlackDuckStartIndex() + ((++lastBlackDuckIndex) % NUMBER_OF_DUCKS_PER_TYPE);
	}
	// 20% to spawn blue duck
	if(percent < BLUE_DUCK_SPAWN_RATE){
		return DucksDB::getBlueDuckStartIndex() + ((++lastBlueDuckIndex) % NUMBER_OF_DUCKS_PER_TYPE);
	}
	// 10% to spawn red duck
	return DucksDB::getRedDuckStartIndex() + ((++lastRedDuckIndex) % NUMBER_OF_DUCKS_PER_TYPE);
}

void ModDuckSpawner::spawn(Duck* duck) const {
	duck->setVisible(true);
	duck->setX((float) (std::rand() % GRAPHICS_WIDTH));
	duck->setY((float) GRAPHICS_HEIGHT - 100);
	duck->setWantToMove(true);
	// flies always to opposite side
	duck->setDX(((float) GRAPHICS_WIDTH / 2 - duck->getX()) > 0 ? 1.5f : -1.5f);
	// There are only 2 duck types on spawn, besides their color:
	// The ones that fly only diagonally and the ones that only fly flat
	duck->setDY((float) -1 - (std::rand() % 2));
	duck->setFacingAndState();

//	game.audioSystem->playMusic(FLAPPING, true);
	game.audioSystem->playSound(QUACK);
	SDL_Delay(100);
}


void ModDuckSpawner::post(Event* e) {
	if(e->name == "StartRound"){
		init();
	}
	if (e->name == "StartSpawning") {
		canSpawn = true;
	}
}

void ModDuckSpawner::reinit() {
	init();
}



