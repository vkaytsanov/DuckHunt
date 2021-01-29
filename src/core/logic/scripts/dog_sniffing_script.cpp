//
// Created by Viktor on 17.1.2021 г..
//

#include <iostream>
#include "include/dog_sniffing_script.h"
#include "../../../lib/include/lib.h"
#include "include/dog_jumping_script.h"
#include "../../include/game_utils.h"
#include "../../graphics/screens/include/hud_renderer.h"

DogSniffingScript::DogSniffingScript(Gamelib& game) {
	Dog& dog = game.dataSystem->dogData.getDog();
	dog.setVisible(true);
	dog.setX(-dog.getWidth());
	dog.setY(GRAPHICS_HEIGHT - 90 - dog.getHeight());
	dog.setDX(0.7f);
	dog.setDY(0);
	dog.setState(Sniffing);
	dog.setWantToMove(true);
	dog.setDrawBefore(false);

}


bool DogSniffingScript::update(Gamelib& game) {
	currentSniffTime += Lib::graphics->getDeltaTime();
	if(currentSniffTime > SNIFF_TIME){
		Dog& dog = game.dataSystem->dogData.getDog();
		dog.setDX(0);
		dog.setState(Jumping);
		dog.resetStateTime();
		game.logicSystem->addScript(new DogJumpingScript(game));
		game.graphicsSystem->getHudRenderer().roundWindow.setVisible(false);
		Lib::app->log("DogSniffing", "Script completed");
		return true;
	}
	return false;
}

