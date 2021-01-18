//
// Created by Viktor on 18.1.2021 г..
//

#include "include/duck_dying_script.h"
#include "../../../lib/include/lib.h"
#include "../../graphics/include/graphics_system.h"
#include "../../include/game_utils.h"

bool DuckDyingScript::update(Gamelib& game) {
	currentTime += Lib::graphics->getDeltaTime();
	if(currentTime > WAIT_TIME){
		duck->setState(DIED);
		duck->setDY(2.0f);

		if(duck->getY() > (float) GRAPHICS_HEIGHT / 2.f + 80){
			game.audioSystem->stopSound(FALLING);
			game.audioSystem->playSound(LANDS);
			duck->setVisible(false);
			Lib::app->log("DuckScript", "duck finished flying down");

			return true;
		}
	}
	return false;
}

DuckDyingScript::DuckDyingScript(Duck* duck) {
	this->duck = duck;
}
