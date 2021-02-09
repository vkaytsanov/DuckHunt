//
// Created by Viktor on 18.1.2021 г..
//

#ifndef DOG_REACTION_SCRIPT_H
#define DOG_REACTION_SCRIPT_H


#include "script.h"

class DogReactionScript : public Script{
private:
	const float WAIT_TIME = 2.0f;
	float currentWaitTime = 0.0f;
	bool didShowReaction = false;
	bool playGotDucks = false;
public:
	explicit DogReactionScript(Gamelib* game);
	bool update(Gamelib* game) override;
};


#endif //DOG_REACTION_SCRIPT_H
