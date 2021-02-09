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

bool DuckDyingScript::update(Gamelib* game) {
	currentTime += Lib::graphics->getDeltaTime();
	if(currentTime > WAIT_TIME){
		duck->setState(DIED);
		duck->setDY(2.5f);
		// spin effect like in the original game
		duck->setFacingLeft(!duck->isFacingLeft());
		if(!isFalling){
			isFalling = true;
			game->audioSystem->playSound(FALLING, true);
			displayScore(game);
		}
		if(duck->getY() > (float) GRAPHICS_HEIGHT / 2.f + 80){
			game->audioSystem->stopSound(FALLING);
			game->audioSystem->playSound(LANDS);
			duck->setVisible(false);
			Lib::app->log("DuckScript", "duck finished flying down");
			// hide the label
			game->graphicsSystem->getHudRenderer().shotScoreLabel.setVisible(false);
			return true;
		}
	}
	return false;
}

void DuckDyingScript::displayScore(Gamelib* game) {
	Label& label = game->graphicsSystem->getHudRenderer().shotScoreLabel;
	label.setText(std::to_string(duck->getScore()));
	label.updateText();
	// we will display it where it was on the shot
	label.setPosition(duck->getX() + (duck->getWidth() - label.getWidth()) / 2, duck->getY());
	label.setVisible(true);
}



