//
// Created by Viktor on 18.1.2021 г..
//

#ifndef DUCK_DYING_SCRIPT_H
#define DUCK_DYING_SCRIPT_H


#include "script.h"
#include "../../../game_object/include/duck.h"


class DuckDyingScript : public Script{
private:
	Duck* duck;
	const float WAIT_TIME = 0.5f;
	float currentTime = 0.f;
	bool isFalling = false;
	void displayScore(Gamelib& game);
public:
	explicit DuckDyingScript(Duck* duck);
	bool update(Gamelib& game) override;
};


#endif //DUCK_DYING_SCRIPT_H
