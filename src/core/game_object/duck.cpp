//
// Created by Viktor on 15.1.2021 г..
//

#include "include/duck.h"

void Duck::loadEntity(Assets& assets) {

}

void Duck::parseAnimationFile() {

}

void Duck::processAnimation(float dt) {
	stateTime += dt;
	currentFrame = flatFlyingAnimation.getFrame(stateTime, true);
}
