//
// Created by Viktor on 18.1.2021 г..
//

#include <iostream>
#include "include/dog_reaction_script.h"
#include "../../include/game_utils.h"
#include "../../../lib/include/lib.h"
#include "../events/include/start_spawning.h"

DogReactionScript::DogReactionScript(Gamelib& game, int ducksAlive, int ducksSpawned) {
	Dog& dog = game.dataSystem->dogData.getDog();
	const int count = 2 + ducksSpawned - ducksAlive;
	const auto dogState = static_cast<DogState>(count);
	dog.setState(dogState);
	dog.setX((float) GRAPHICS_WIDTH / 2 - dog.getWidth() / 2);
	dog.setY((float) GRAPHICS_HEIGHT / 2 + 100);
	dog.setDY(0);
	dog.setDX(0);
	dog.setVisible(true);
	dog.setWantToMove(true);
	if (count > 2) {
		playGotDucks = true;
	}
}

DogReactionScript::DogReactionScript(Gamelib& game, int ducksAlive, int ducksSpawned, bool finishedRound)
		: DogReactionScript(game, ducksAlive, ducksSpawned) {
	this->finishedRound = finishedRound;
}

bool DogReactionScript::update(Gamelib& game) {
	// TODO:
	// We have written the drawing before part in the playing screen just because of this method,
	// because the dog is being rendered last in the playing screen
	// but in this case, the dog is appearing behind the bushes, the problem of drawing
	// using the Painter's algorithm...
	float dt = Lib::graphics->getDeltaTime();
	currentWaitTime += dt;
	Dog& dog = game.dataSystem->dogData.getDog();
	// Going Up
	if (currentWaitTime > WAIT_TIME && !didShowReaction) {
		dog.setDY(-1.5f);
		if (dog.getY() < (float) GRAPHICS_HEIGHT / 2 + 22) {
			didShowReaction = true;
			dog.setDY(0);
			if (playGotDucks) game.audioSystem->playSound(GOT_DUCKS);
			else game.audioSystem->playSound(MISS);
		}
	}
		// Going Down
	else if (currentWaitTime > WAIT_TIME * 2 && didShowReaction) {
		dog.setDY(1.5f);
		if (dog.getY() > (float) GRAPHICS_HEIGHT / 2 + 100) {
			if(!finishedRound){
				game.dataSystem->currentGameData.shots = 3;
				game.logicSystem->post(new StartSpawning());
				game.graphicsSystem->start(Playing);
				dog.setVisible(false);
			}
			return true;
		}
	}
	return false;
}




