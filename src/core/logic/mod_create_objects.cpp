//
// Created by Viktor on 15.1.2021 г..
//

#include "include/mod_create_objects.h"
#include "../game_object/include/black_duck.h"
#include "../game_object/include/blue_duck.h"
#include "../game_object/include/red_duck.h"
#include "../include/game_utils.h"
ModCreateObjects::ModCreateObjects(Gamelib& game) : game(game) {}

void ModCreateObjects::init() {
	for(int i = 0; i < 2; i++){
		auto* blackDuck = new BlackDuck();
		blackDuck->loadEntity(game.dataSystem->assets);
		game.dataSystem->ducksDb.addDuck(blackDuck);
		auto* blueDuck = new BlueDuck();
		blueDuck->loadEntity(game.dataSystem->assets);
		game.dataSystem->ducksDb.addDuck(blueDuck);
		auto* redDuck = new RedDuck();
		redDuck->loadEntity(game.dataSystem->assets);
		game.dataSystem->ducksDb.addDuck(redDuck);
	}

	Dog dog;
	dog.loadEntity(game.dataSystem->assets);
	game.dataSystem->dogData.setDog(dog);
}

void ModCreateObjects::update() {

}

void ModCreateObjects::post(Event* e) {

}

void ModCreateObjects::reinit() {

}


