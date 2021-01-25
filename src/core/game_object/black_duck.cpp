//
// Created by Viktor on 15.1.2021 г..
//

#include "include/black_duck.h"


void BlackDuck::loadEntity(Assets& assets) {
	const int startingIndex = 0;
	Texture* spriteSheet = assets.getSprite("ducks");

	beginParsing(spriteSheet, startingIndex);
}




