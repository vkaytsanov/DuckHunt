//
// Created by Viktor on 15.1.2021 г..
//

#include "include/duck.h"

void Duck::copyTextures(const Duck& duck) {
	this->flatFlyingAnimation = duck.flatFlyingAnimation;
	this->diagFlyingAnimation = duck.diagFlyingAnimation;
	this->upFlyingAnimation = duck.upFlyingAnimation;
	this->shotTexture = duck.shotTexture;
	this->diedTexture = duck.diedTexture;
}

void Duck::processAnimation(const float dt) {
	stateTime += dt;
	currentFrame = flatFlyingAnimation.getFrame(stateTime, true);
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

	for (int i = startingIndex; i < framesPerAnimation; i++) {
		parseFile(spriteSheet, flatFlyingTextures, i);
		parseFile(spriteSheet, diagFlyingTextures, i + 3);
		parseFile(spriteSheet, upFlyingTextures, i + 6);
	}

	parseFile(spriteSheet, shotTexture, startingIndex + framesPerAnimation * 3 + 1);
	parseFile(spriteSheet, diedTexture, startingIndex + framesPerAnimation * 3 + 2);

	flatFlyingAnimation.loadFrames(0.15f, flatFlyingTextures);
	diagFlyingAnimation.loadFrames(0.15f, diagFlyingTextures);
	upFlyingAnimation.loadFrames(0.15f, upFlyingTextures);
}

int Duck::getScore() const {
	return score;
}






