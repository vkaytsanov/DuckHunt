//
// Created by Viktor on 17.1.2021 г..
//

#ifndef DOG_H
#define DOG_H


#include "../generic/include/entity_animated.h"
#include "../generic/include/sprite_parsable.h"


enum DogState{
	Sniffing,
	Jumping,
	Laughing,
	OneDuck,
	TwoDucks
};

class Dog : public EntityAnimated, public SpriteParsable{
private:
	int RENDERING_WIDTH = 120;
	int RENDERING_HEIGHT = 100;
	float stateTime = 0.0f;
	Animation<TextureRegion> animations[3];
	TextureRegion ducks[2];
	DogState currentState;
	bool drawBefore = false;
public:
	void loadEntity(Assets& assets) override;
	void processAnimation(float dt) override;
	void setState(DogState state);
	void resetStateTime();
	bool isDrawBefore() const;
	void setDrawBefore(bool drawBefore);
};


#endif //DOG_H
