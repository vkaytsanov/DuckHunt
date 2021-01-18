//
// Created by Viktor on 18.1.2021 г..
//

#include <iostream>
#include "include/dog_reaction_script.h"
#include "../../include/game_utils.h"
#include "../../../lib/include/lib.h"
#include "../events/include/start_spawning.h"

DogReactionScript::DogReactionScript(Gamelib& game, int ducksAlive, int ducksSpawned){
	Dog& dog = game.dataSystem->dogData.getDog();
	const int count = 2 + ducksSpawned - ducksAlive;
	const auto dogState = static_cast<DogState>(count);
	dog.setState(dogState);
	dog.setX((float) GRAPHICS_WIDTH / 2  - dog.getWidth() / 2);
	dog.setY((float) GRAPHICS_HEIGHT / 2 + 100);
	dog.setDY(0);
	dog.setDX(0);
	dog.setVisible(true);
	dog.setDrawBefore(true);
	if(count > 2){
		playSound = true;
	}
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
	if(currentWaitTime > WAIT_TIME && !didShowReaction) {
		dog.setDY(-1);
		if (dog.getY() < (float) GRAPHICS_HEIGHT / 2 + 20) {
			didShowReaction = true;
			dog.setDY(0);
			if(playSound) game.audioSystem->playSound(GOT_DUCKS, 2, false);
		}
	}
	else if (currentWaitTime > WAIT_TIME * 2 && didShowReaction) {
		dog.setDY(1);
		if (dog.getY() > (float) GRAPHICS_HEIGHT / 2 + 100) {
			game.dataSystem->currentGameData.shots = 3;
			game.logicSystem->post(new StartSpawning());
			game.graphicsSystem->start(Playing);
			return true;
		}
	}
	return false;
}


