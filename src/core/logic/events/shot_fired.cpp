//
// Created by Viktor on 17.1.2021 г..
//

#include "include/shot_fired.h"

ShotFired::ShotFired(Duck* duck) : Event("ShotFired") {
	this->duck = duck;
}

ShotFired::ShotFired() : Event("ShotFired"){
	duck = nullptr;
}
