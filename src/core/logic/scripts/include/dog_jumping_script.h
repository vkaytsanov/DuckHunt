//
// Created by Viktor on 18.1.2021 г..
//

#ifndef DOG_JUMPING_SCRIPT_H
#define DOG_JUMPING_SCRIPT_H

#include "script.h"

class DogJumpingScript : public Script{
private:
	bool bounced = false;
	const float WAIT_TIME = 1.0f;
	float currentWaitTime = 0.0f;
	bool didBark = false;
public:
	explicit DogJumpingScript(Gamelib& game);
	bool update(Gamelib& game) override;
};


#endif //DOG_JUMPING_SCRIPT_H
