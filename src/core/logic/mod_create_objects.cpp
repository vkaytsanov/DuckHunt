//
// Created by Viktor on 15.1.2021 г..
//

#include "include/mod_create_objects.h"
#include "../game_object/include/black_duck.h"
#include "../game_object/include/blue_duck.h"
#include "../game_object/include/red_duck.h"

ModCreateObjects::ModCreateObjects(Gamelib& game) : game(game) {}

void ModCreateObjects::init() {
	BlackDuck blackDuck;
	blackDuck.loadEntity(game.dataSystem->assets);

	BlueDuck blueDuck;
	blueDuck.loadEntity(game.dataSystem->assets);

	RedDuck redDuck;
	redDuck.loadEntity(game.dataSystem->assets);

	BlackDuck blackDuck2;
	blackDuck2.copyTextures(blackDuck);

	BlueDuck blueDuck2;
	blueDuck2.copyTextures(blueDuck);

	RedDuck redDuck2;
	redDuck2.copyTextures(redDuck);


	game.dataSystem->ducksDb.addDuck(blackDuck);
	game.dataSystem->ducksDb.addDuck(blackDuck2);
	game.dataSystem->ducksDb.addDuck(blueDuck);
	game.dataSystem->ducksDb.addDuck(blueDuck2);
	game.dataSystem->ducksDb.addDuck(redDuck);
	game.dataSystem->ducksDb.addDuck(redDuck2);

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


