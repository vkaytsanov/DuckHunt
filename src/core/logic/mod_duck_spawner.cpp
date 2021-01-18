//
// Created by Viktor on 15.1.2021 г..
//

#include "include/mod_duck_spawner.h"
#include "../include/game_utils.h"
#include "../../lib/include/lib.h"
#include "events/include/shot_fired.h"
#include "scripts/include/dog_reaction_script.h"


ModDuckSpawner::ModDuckSpawner(Gamelib& game) : game(game){

}

void ModDuckSpawner::init() {
	ducksPerSpawn = currentDifficultyLevel;
	ducksSpawned = 0;
	ducksAlive = 0;
	ducksCount = 0;
	canSpawn = false;
}

void ModDuckSpawner::update() {
	if(canSpawn){
		canSpawn = false;
		for(int i = 0; i < ducksPerSpawn; i++){
			int idx = std::rand() % NUMBER_OF_DUCKS;
			Duck* duck = game.dataSystem->ducksDb.getDucks()[idx];
			while(duck->isVisible()){
				idx = std::rand() % NUMBER_OF_DUCKS;
				duck = game.dataSystem->ducksDb.getDucks()[idx];
			}
			spawn(duck);
		}
		ducksAlive = ducksPerSpawn;
		ducksCount += ducksPerSpawn;
	}
}

void ModDuckSpawner::spawn(Duck* duck) {
	duck->setVisible(true);
	duck->setX(std::rand() % GRAPHICS_WIDTH);
	duck->setY(GRAPHICS_HEIGHT/2);
	duck->setWantToMove(true);
	// flies always to opposite side
	duck->setDX((GRAPHICS_WIDTH / 2 - duck->getX()) > 0 ? 1.0f : -1.0f);
	if(duck->getDX() > 0) duck->setFacingLeft(false);
	else duck->setFacingLeft(true);
	duck->setDY(-1.0f);
	duck->setState(DIAG_FLYING);
//	int channel = game.audioSystem->getFreeChannel();
//	if(channel == -1) channel = game.audioSystem->getSoundChannel(FLAPPING);
//	game.audioSystem->setChannelUsed(channel, FLAPPING);
	game.audioSystem->playSound(FLAPPING, game.audioSystem->duckOneChannel, true);
}


void ModDuckSpawner::post(Event* e) {
	if(e->name == "StartSpawning"){
		canSpawn = true;
	}
	else if(e->name == "ShotFired"){
		auto* s = static_cast<ShotFired*>(e);
		if(s->duck){
			game.dataSystem->currentGameData.ducksTracker[ducksCount - ducksAlive] = KILLED;
			ducksAlive--;
		}
		if(ducksAlive == 0 || game.dataSystem->currentGameData.shots == 0){
			game.logicSystem->addScript(new DogReactionScript(game, ducksAlive, ducksPerSpawn));
			Lib::input->setProcessor(nullptr);
		}
	}
}

void ModDuckSpawner::reinit() {
	init();
}

void ModDuckSpawner::setCurrentDifficultyLevel(DifficultyLevel currentDifficultyLevel) {
	this->currentDifficultyLevel = currentDifficultyLevel;
}
