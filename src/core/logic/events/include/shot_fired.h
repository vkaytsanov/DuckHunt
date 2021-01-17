//
// Created by Viktor on 17.1.2021 г..
//

#ifndef SHOT_FIRED_H
#define SHOT_FIRED_H

#include "../../../game_object/include/duck.h"
#include "event.h"

class ShotFired : public Event{
public:
	Duck* duck;
	ShotFired();
	ShotFired(Duck* duck);
};


#endif //SHOT_FIRED_H
