//
// Created by Viktor on 17.1.2021 г..
//

#include <iostream>
#include "include/dog_sniffing_script.h"
#include "../../../lib/include/lib.h"
#include "include/dog_jumping_script.h"
#include "../../include/game_utils.h"

DogSniffingScript::DogSniffingScript(Gamelib& game) {
	Dog& dog = game.dataSystem->dogData.getDog();
	dog.setVisible(true);
	dog.setX(-dog.getWidth());
	dog.setY(GRAPHICS_HEIGHT - 90 - dog.getHeight());
	dog.setDX(0.45f);
	dog.setState(Sniffing);
	dog.setWantToMove(true);

}

// Keep scripts in the CurrentGameData class?
bool DogSniffingScript::update(Gamelib& game) {
	currentSniffTime += Lib::graphics->getDeltaTime();
	if(currentSniffTime > SNIFF_TIME){
		Dog& dog = game.dataSystem->dogData.getDog();
		dog.setDX(0);
		dog.setState(Jumping);
		dog.resetStateTime();
		game.logicSystem->addScript(new DogJumpingScript(game));
//		int channel = game.audioSystem->getFreeChannel();
//		if(channel == -1) channel = game.audioSystem->getSoundChannel(BARKS);
//		game.audioSystem->setChannelUsed(channel, BARKS);
		game.audioSystem->playSound(BARKS, game.audioSystem->dogChannel, false);
		Lib::app->log("DogSniffing", "Script completed");
		return true;
	}
	return false;
}

