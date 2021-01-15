//
// Created by Viktor on 15.1.2021 г..
//

#ifndef DUCK_H
#define DUCK_H


#include "entity_animated.h"
#include "../../lib/utils/include/texture_region.h"


class Duck : public EntityAnimated{
private:
	float stateTime = 0;
protected:
	Animation<TextureRegion> flatFlyingAnimation;
	Animation<TextureRegion> diagFlyingAnimation;
	Animation<TextureRegion> upFlyingAnimation;
public:
	virtual void loadEntity(Assets& assets);
	virtual void parseAnimationFile();
	void processAnimation(float dt) override;
};


#endif //DUCK_H
