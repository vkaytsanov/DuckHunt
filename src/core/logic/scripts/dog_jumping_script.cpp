//
// Created by Viktor on 18.1.2021 г..
//

#include <iostream>
#include "include/dog_jumping_script.h"
#include "../../include/game_utils.h"
#include "../../../lib/include/lib.h"
#include "../events/include/start_spawning.h"

DogJumpingScript::DogJumpingScript(Gamelib& game) {
}

bool DogJumpingScript::update(Gamelib& game) {
	Dog& dog = game.dataSystem->dogData.getDog();
	currentWaitTime += Lib::graphics->getDeltaTime();
	if(currentWaitTime < WAIT_TIME){
		dog.resetStateTime();
		return false;
	}
	dog.setDY(-1.0f);
	dog.setDX(0.4f);
	if(dog.getY() < 330){
		bounced = true;
	}
	if(bounced) {
		dog.setHeight(dog.getHeight() - dog.getSpeed()*2 * Lib::graphics->getDeltaTime());
		dog.setDY(1.5f);
		if (dog.getHeight() <= 50.f) {
			dog.setVisible(false);
			// resetting to default height
			dog.setHeight(100);

			// add event to start spawning
			game.logicSystem->post(new StartSpawning());
			game.graphicsSystem->start(Playing);
			game.audioSystem->playSound(BARKS, -1, false);
			return true;
		}
	}
	return false;
}
