//
// Created by Viktor on 18.1.2021 г..
//

#include <iostream>
#include "include/dog_jumping_script.h"
#include "../../include/game_utils.h"
#include "../../../lib/include/lib.h"
#include "../events/include/start_spawning.h"

DogJumpingScript::DogJumpingScript(Gamelib* game) {

}

bool DogJumpingScript::update(Gamelib* game) {
	Dog& dog = game->dataSystem->dogData.getDog();
	currentWaitTime += Lib::graphics->getDeltaTime();
	if(currentWaitTime < WAIT_TIME){
		dog.resetStateTime();
		return false;
	}
	if(!didBark){
		didBark = true;
		game->audioSystem->playSound(BARKS);
	}
	// Jumping
	dog.setDY(-4.0f);
	dog.setDX(0.4f);
	if(dog.getY() < 300){
		bounced = true;
		dog.setDrawBefore(true);

	}
	// Needs to fall down
	if(bounced) {
		dog.setDY(3.5f);
		if (dog.getY() > 370) {
			dog.setVisible(false);

			// add event to start spawning
			game->logicSystem->post(new StartSpawning());
			// Gives input to the playing screen
			game->graphicsSystem->start(Playing);
			return true;
		}
	}
	return false;
}
