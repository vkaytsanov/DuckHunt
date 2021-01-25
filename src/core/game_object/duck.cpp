//
// Created by Viktor on 15.1.2021 г..
//

#include "include/duck.h"
#include "../../lib/include/lib.h"
#include <cassert>


void Duck::processAnimation(const float dt) {
	stateTime += dt;
	if(currentState < 3) {
		currentFrame = animations[currentState].getFrame(stateTime, true);
	}
	else{
		currentFrame = death[currentState - 3];
	}
}

void Duck::loadEntity(Assets& assets) {

}

void Duck::beginParsing(Texture* spriteSheet, const int startingIndex) {
	const int framesPerAnimation = 3;
	set(8, 64, 32);
	width = RENDERING_WIDTH;
	height = RENDERING_HEIGHT;

	std::vector<TextureRegion> flatFlyingTextures;
	std::vector<TextureRegion> diagFlyingTextures;
	std::vector<TextureRegion> upFlyingTextures;


	flatFlyingTextures.reserve(framesPerAnimation);
	diagFlyingTextures.reserve(framesPerAnimation);
	upFlyingTextures.reserve(framesPerAnimation);

	for (int i = startingIndex; i < startingIndex + framesPerAnimation; i++) {
		parseFile(spriteSheet, flatFlyingTextures, i);
		parseFile(spriteSheet, diagFlyingTextures, i + 3);
		parseFile(spriteSheet, upFlyingTextures, i + 6);
	}

	parseFile(spriteSheet, death[0], startingIndex + framesPerAnimation * 3);
	parseFile(spriteSheet, death[1], startingIndex + framesPerAnimation * 3 + 1);

	animations[0].loadFrames(0.15f, flatFlyingTextures);
	animations[1].loadFrames(0.15f, diagFlyingTextures);
	animations[2].loadFrames(0.15f, upFlyingTextures);

	Lib::app->log("Assets", "binded");
	assert(flatFlyingTextures.size() == framesPerAnimation);
	assert(diagFlyingTextures.size() == framesPerAnimation);
	assert(upFlyingTextures.size() == framesPerAnimation);

}

int Duck::getScore() const {
	return score;
}

void Duck::setState(DuckState state) {
	currentState = state;
}

bool Duck::isHit(const float& mouseX, const float& mouseY) {
	return  x < mouseX && mouseX < (x + width) &&
	        y < mouseY && mouseY < (y + height);
}

DuckState Duck::getState() const {
	return currentState;
}

void Duck::setFacingAndState() {
	if(dx == 0){
		setState(UP_FLYING);
		return;
	}
	setFacing();
	std::abs(dx - dy) > 0.99f ? setState(DIAG_FLYING) : setState(FLAT_FLYING);
}

void Duck::setScore(const int score) {
	this->score = score;
}






