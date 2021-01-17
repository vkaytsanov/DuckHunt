//
// Created by Viktor on 15.1.2021 г..
//

#ifndef DUCK_H
#define DUCK_H


#include "../generic/include/entity_animated.h"
#include "../../../lib/utils/include/texture_region.h"
#include "../generic/include/sprite_parsable.h"


enum DuckAnimationState{
	FLAT_FLYING,
	DIAG_FLYING,
	UP_FLYING,
	SHOT,
	DIED
};

class Duck : public EntityAnimated, public SpriteParsable{
private:
	int RENDERING_WIDTH = 120;
	int RENDERING_HEIGHT = 60;
	float stateTime = 0;
protected:
	int score;
	// TODO make them all from animation class, put them in array for fast animation processing based on current state
	Animation<TextureRegion> flatFlyingAnimation;
	Animation<TextureRegion> diagFlyingAnimation;
	Animation<TextureRegion> upFlyingAnimation;
	TextureRegion shotTexture;
	TextureRegion diedTexture;
public:
	void copyTextures(const Duck& duck);
	virtual void loadEntity(Assets& assets);
	void beginParsing(Texture* spriteSheet, int startingIndex);
	void processAnimation(float dt) override;
	int getScore() const;
};


#endif //DUCK_H
