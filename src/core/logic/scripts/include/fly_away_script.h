//
// Created by Viktor on 24.1.2021 г..
//

#ifndef FLY_AWAY_SCRIPT_H
#define FLY_AWAY_SCRIPT_H


#include "script.h"

class FlyAwayScript : public Script{
private:
	float currentTime = 0.0f;
	const float WAIT_TIME = 1.5f;
public:
	explicit FlyAwayScript(Gamelib& game);
	bool update(Gamelib& game) override;
};


#endif //FLY_AWAY_SCRIPT_H
