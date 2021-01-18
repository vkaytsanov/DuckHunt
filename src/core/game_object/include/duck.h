//
// Created by Viktor on 15.1.2021 г..
//

#ifndef DUCK_H
#define DUCK_H


#include "../generic/include/entity_animated.h"
#include "../../../lib/utils/include/texture_region.h"
#include "../generic/include/sprite_parsable.h"


enum DuckState{
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
	DuckState currentState;
protected:
	int score;
	Animation<TextureRegion> animations[3];
	TextureRegion death[2];
public:
	virtual void loadEntity(Assets& assets);
	void beginParsing(Texture* spriteSheet, int startingIndex);
	void processAnimation(float dt) override;
	int getScore() const;
	void setState(DuckState state);
	DuckState getState() const;
	bool isHit(const float& x, const float& y);
};


#endif //DUCK_H
