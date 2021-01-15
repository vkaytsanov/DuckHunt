//
// Created by Viktor on 15.1.2021 г..
//

#include "include/black_duck.h"


void BlackDuck::loadEntity(Assets& assets) {
	Texture* spriteSheet = assets.getSprite("ducks");

	const int framesPerAnimation = 3;

	std::vector<TextureRegion> flatFlyingTextures;
	std::vector<TextureRegion> diagFlyingTextures;
	std::vector<TextureRegion> upFlyingTextures;


	const int frameWidth = 64;
	const int frameHeight = 32;

	flatFlyingTextures.reserve(framesPerAnimation);

	for (int i = 0; i < framesPerAnimation; i++) {
		flatFlyingTextures.emplace_back(
				TextureRegion(spriteSheet,
				              i * frameWidth,
				              0,
				              frameWidth,
				              frameHeight
				));
		diagFlyingTextures.emplace_back(
				TextureRegion(spriteSheet,
				              (3 + i) * frameWidth,
				              0,
				              frameWidth,
				              frameHeight
				));
	}

	flatFlyingAnimation.loadFrames(0.3f, flatFlyingTextures);
	diagFlyingAnimation.loadFrames(0.3f, diagFlyingTextures);

}
