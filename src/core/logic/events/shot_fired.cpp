//
// Created by Viktor on 17.1.2021 г..
//

#include "include/shot_fired.h"

ShotFired::ShotFired(Duck* duck) : Event("ShotFired", EventType::ShotFiredType) {
	this->duck = duck;
}

ShotFired::ShotFired() : Event("ShotFired", ShotFiredType){
	duck = nullptr;
}
