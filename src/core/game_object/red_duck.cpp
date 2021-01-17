//
// Created by Viktor on 15.1.2021 г..
//

#include "include/red_duck.h"

void RedDuck::loadEntity(Assets& assets) {
	const int startingIndex = 22;
	Texture* spriteSheet = assets.getSprite("ducks");

	beginParsing(spriteSheet, startingIndex);
}

RedDuck::RedDuck() {
	score = 1500;
}
