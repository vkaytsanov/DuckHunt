//
// Created by Viktor on 17.1.2021 г..
//

#ifndef SPRITE_PARSABLE_H
#define SPRITE_PARSABLE_H

#include "../../../lib/utils/include/texture.h"
#include "../../../lib/utils/include/texture_region.h"
#include <vector>

class SpriteParsable {
private:
	int FRAMES_ROW;
	int FRAME_WIDTH;
	int FRAME_HEIGHT;
public:
	void set(int framesRow, int frameWidth, int frameHeight);
	void parseFile(Texture* spriteSheet, std::vector<TextureRegion>& regions, int i);
	void parseFile(Texture* spriteSheet, TextureRegion& region, int i);
};


#endif //SPRITE_PARSABLE_H
