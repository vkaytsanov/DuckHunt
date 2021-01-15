//
// Created by Viktor on 15.1.2021 г..
//

#include "include/blue_duck.h"

void BlueDuck::loadEntity(Assets& assets) {
	const int startingIndex = 11;
	Texture* spriteSheet = assets.getSprite("ducks");

	beginParsing(spriteSheet, startingIndex);
}