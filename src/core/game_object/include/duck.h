//
// Created by Viktor on 15.1.2021 г..
//

#ifndef DUCK_H
#define DUCK_H


#include "entity_animated.h"
#include "../../lib/utils/include/texture_region.h"

static const int FILE_WIDTH = 512;
static const int FRAME_WIDTH = 64;
static const int FRAME_HEIGHT = 32;
static const int RENDERING_WIDTH = 120;
static const int RENDERING_HEIGHT = 60;

enum DuckAnimationState{
	FLAT_FLYING,
	DIAG_FLYING,
	UP_FLYING,
	SHOT,
	DIED
};

class Duck : public EntityAnimated{
private:
	float stateTime = 0;
protected:
	// TODO make them all from animation class, put them in array for fast animation processing based on current state
	Animation<TextureRegion> flatFlyingAnimation;
	Animation<TextureRegion> diagFlyingAnimation;
	Animation<TextureRegion> upFlyingAnimation;
	TextureRegion shotTexture;
	TextureRegion diedTexture;
public:
	void copyTextures(const Duck& duck);
	virtual void loadEntity(Assets& assets);
	void parseFile(Texture* spriteSheet, std::vector<TextureRegion>& regions, int i);
	void parseFile(Texture* spriteSheet, TextureRegion& region, int i);
	void beginParsing(Texture* spriteSheet, int startingIndex);
	void processAnimation(float dt) override;
};


#endif //DUCK_H
