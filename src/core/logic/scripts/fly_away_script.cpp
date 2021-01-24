//
// Created by Viktor on 24.1.2021 г..
//

#include "include/fly_away_script.h"
#include "../../include/game_utils.h"
#include "../../../lib/include/lib.h"
#include "../../graphics/screens/include/hud_renderer.h"
#include "include/dog_reaction_script.h"

FlyAwayScript::FlyAwayScript(Gamelib& game, int ducksSpawned) {
	this->ducksSpawned = ducksSpawned;

	game.graphicsSystem->getHudRenderer().flyAwayWindow.setVisible(true);
	for(Duck* duck : game.dataSystem->ducksDb.getDucks()){
		if(duck->isVisible() && duck->getState() != SHOT && duck->getState() != DIED){
			duck->setDX(0);
			duck->setDY(-1.0f);
			duck->setFacingAndState();
			ducksAlive++;
		}
	}
}

bool FlyAwayScript::update(Gamelib& game) {
	currentTime += Lib::graphics->getDeltaTime();
	if(currentTime > WAIT_TIME){
		game.graphicsSystem->getHudRenderer().flyAwayWindow.setVisible(false);
		game.logicSystem->addScript(new DogReactionScript(game, ducksAlive, ducksSpawned));
		return true;
	}
	return false;
}


