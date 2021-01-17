//
// Created by Viktor on 17.1.2021 г..
//

#include "include/sprite_parsable.h"

void SpriteParsable::set(const int framesRow, const int frameWidth,
                         const int frameHeight) {
	FRAMES_ROW = framesRow;
	FRAME_WIDTH = frameWidth;
	FRAME_HEIGHT = frameHeight;

}

void SpriteParsable::parseFile(Texture* spriteSheet, std::vector<TextureRegion>& regions, int i) {
	const int j = i / FRAMES_ROW;
	i = i % FRAMES_ROW;

	regions.emplace_back(
			TextureRegion(spriteSheet,
			              i * FRAME_WIDTH,
			              j * FRAME_HEIGHT,
			              FRAME_WIDTH,
			              FRAME_HEIGHT
			));
}

void SpriteParsable::parseFile(Texture* spriteSheet, TextureRegion& region, int i) {
	const int j = i / FRAMES_ROW;
	i = i % FRAMES_ROW;

	region.set(spriteSheet,
	           i * FRAME_WIDTH,
	           j * FRAME_HEIGHT,
	           FRAME_WIDTH,
	           FRAME_HEIGHT
	);
}