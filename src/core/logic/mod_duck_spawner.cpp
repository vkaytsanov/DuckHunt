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
}

void ModDuckSpawner::init() {
	ducksPerSpawn = currentDifficultyLevel;
	ducksAlive = 0;
	ducksCount = 9;
	canSpawn = false;
}

void ModDuckSpawner::update() {
	if (canSpawn) {
		canSpawn = false;

		for (int i = 0; i < ducksPerSpawn; i++) {
			const int idx = getCandidate(dist(generator));
			spawn(game.dataSystem->ducksDb.getDucks()[idx]);
		}
		ducksAlive = ducksPerSpawn;
		ducksCount += ducksPerSpawn;
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
	if (e->name == "StartSpawning") {
		canSpawn = true;
	} else if (e->name == "ShotFired") {
		auto* s = dynamic_cast<ShotFired*>(e);
		if (s->duck) {
			game.dataSystem->currentGameData.ducksTracker[ducksCount - ducksAlive] = KILLED;
			ducksAlive--;
		}
		bool finishedRound = ducksCount == 10;
		if (ducksAlive == 0) {
			game.logicSystem->addScript(new DogReactionScript(game, ducksAlive, ducksPerSpawn, finishedRound));
			Lib::input->setProcessor(nullptr);
			if(finishedRound){
				game.logicSystem->addScript(new EndOfRoundScript(game));
			}
		}
		else if(game.dataSystem->currentGameData.shots == 0){
			// fly away script
			game.logicSystem->addScript(new FlyAwayScript(game, ducksPerSpawn));
			Lib::input->setProcessor(nullptr);
			if(finishedRound){
				game.logicSystem->addScript(new EndOfRoundScript(game));
			}
		}
	}
}

void ModDuckSpawner::reinit() {
	init();
}

void ModDuckSpawner::setCurrentDifficultyLevel(const DifficultyLevel difficulty) {
	this->currentDifficultyLevel = difficulty;
}


