//
// Created by Viktor on 18.1.2021 г..
//

#include "include/duck_dying_script.h"
#include "../../../lib/include/lib.h"
#include "../../graphics/include/graphics_system.h"
#include "../../graphics/screens/include/hud_renderer.h"
#include "../../include/game_utils.h"

DuckDyingScript::DuckDyingScript(Duck* duck) {
	this->duck = duck;
}

bool DuckDyingScript::update(Gamelib& game) {
	currentTime += Lib::graphics->getDeltaTime();
	if(currentTime > WAIT_TIME){
		duck->setState(DIED);
		duck->setDY(2.5f);
		if(!isFalling){
			isFalling = true;
			game.audioSystem->playSound(FALLING, true);
			displayScore(game);
		}
		if(duck->getY() > (float) GRAPHICS_HEIGHT / 2.f + 80){
			game.audioSystem->stopSound(FALLING);
			game.audioSystem->playSound(LANDS);
			duck->setVisible(false);
			Lib::app->log("DuckScript", "duck finished flying down");
			// hide the label
			const int idx = getLabelIndex();
			game.graphicsSystem->getHudRenderer().shotScoreLabels[idx].setVisible(false);
			return true;
		}
	}
	return false;
}

void DuckDyingScript::displayScore(Gamelib& game) {
	const int idx = getLabelIndex();
	Label& label = game.graphicsSystem->getHudRenderer().shotScoreLabels[idx];
	// we will display it where it was on the shot
	label.setPosition(duck->getX() + (duck->getWidth() - label.getWidth()) / 2, duck->getY());
	label.setVisible(true);
}

int DuckDyingScript::getLabelIndex() const {
	// 500 / 501 = 0
	// 1000 / 501 = 1
	// 1500 / 501 = 2
	return duck->getScore() / 501;
}


