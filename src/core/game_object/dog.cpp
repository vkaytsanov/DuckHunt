//
// Created by Viktor on 17.1.2021 г..
//

#include <iostream>
#include "include/dog.h"

void Dog::loadEntity(Assets& assets) {
	Texture* spriteSheet = assets.getSprite("dog");
	set(6, 60, 50);
	width = RENDERING_WIDTH;
	height = RENDERING_HEIGHT;

	std::vector<TextureRegion> sniffingAnimationTextures;
	std::vector<TextureRegion> jumpingAnimationTextures;
	std::vector<TextureRegion> laughingAnimationTextures;

	const int sniffCountTex = 5;
	const int jumpCountTex = 3;
	const int laughCountTex = 2;
	sniffingAnimationTextures.reserve(sniffCountTex);
	jumpingAnimationTextures.reserve(jumpCountTex);
	laughingAnimationTextures.reserve(laughCountTex);

	for(int i = 0; i < sniffCountTex; i++){
		parseFile(spriteSheet, sniffingAnimationTextures, i);
	}

	parseFile(spriteSheet, ducks[0], sniffCountTex);

	for(int i = 0; i < jumpCountTex; i++){
		parseFile(spriteSheet, jumpingAnimationTextures, i + sniffCountTex + 1);
	}

	for(int i = 0; i < laughCountTex; i++){
		parseFile(spriteSheet, laughingAnimationTextures, i + sniffCountTex + 1 + jumpCountTex);
	}

	parseFile(spriteSheet, ducks[1], sniffCountTex + 1 + jumpCountTex + laughCountTex);

	animations[0].loadFrames(0.15f, sniffingAnimationTextures, true);
	animations[1].loadFrames(0.30f, jumpingAnimationTextures, false);
	animations[2].loadFrames(0.20f, laughingAnimationTextures, true);
}

void Dog::processAnimation(const float dt) {
	stateTime += dt;
	if(currentState < 3){
		currentFrame = animations[currentState].getFrame(stateTime);
	}
	else{
		currentFrame = ducks[currentState - 3];
	}
}

void Dog::setState(DogState state) {
	currentState = state;
}

void Dog::resetStateTime() {
	stateTime = 0.0f;
}

bool Dog::isDrawBefore() const {
	return drawBefore;
}

void Dog::setDrawBefore(bool drawBefore) {
	Dog::drawBefore = drawBefore;
}

