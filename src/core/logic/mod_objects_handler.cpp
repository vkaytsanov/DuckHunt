//
// Created by Viktor on 15.1.2021 г..
//

#include "include/mod_objects_handler.h"
#include "../game_object/include/black_duck.h"
#include "../game_object/include/blue_duck.h"
#include "../game_object/include/red_duck.h"
#include "../include/game_utils.h"
#include "scripts/include/duck_dying_script.h"
#include "events/include/shot_fired.h"

ModObjectsHandler::ModObjectsHandler(Gamelib* game) : game(game) {}

void ModObjectsHandler::init() {
	for(int i = 0; i < NUMBER_OF_DUCKS_PER_TYPE; i++){
		auto* blackDuck = new BlackDuck();
		blackDuck->loadEntity(game->dataSystem->assets);
		game->dataSystem->ducksDb.addDuck(blackDuck);
	}
	for(int i = 0; i < NUMBER_OF_DUCKS_PER_TYPE; i++){
		auto* blueDuck = new BlueDuck();
		blueDuck->loadEntity(game->dataSystem->assets);
		game->dataSystem->ducksDb.addDuck(blueDuck);
	}
	for(int i = 0; i < NUMBER_OF_DUCKS_PER_TYPE; i++){
		auto* redDuck = new RedDuck();
		redDuck->loadEntity(game->dataSystem->assets);
		game->dataSystem->ducksDb.addDuck(redDuck);
	}

	Dog dog;
	dog.loadEntity(game->dataSystem->assets);
	game->dataSystem->dogData.setDog(dog);
}

void ModObjectsHandler::update() {

}

void ModObjectsHandler::post(Event* e) {
	if(e->name == "ShotFired"){
		auto* s = dynamic_cast<ShotFired*>(e);
		if(s->duck) {
			Duck* duck = s->duck;
			duck->setDY(0);
			duck->setDX(0);
			duck->setState(SHOT);
			game->audioSystem->stopMusic();
			game->logicSystem->addScript(new DuckDyingScript(duck));
		}
	}
}

void ModObjectsHandler::reinit() {

}


