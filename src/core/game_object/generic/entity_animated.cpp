//
// Created by Viktor on 14.1.2021 г..
//

#include "include/entity_animated.h"

bool EntityAnimated::isVisible() const {
	return visible;
}

void EntityAnimated::setVisible(bool visible) {
	EntityAnimated::visible = visible;
}

bool EntityAnimated::isFacingLeft() const {
	return facingLeft;
}

void EntityAnimated::setFacingLeft(bool facingLeft) {
	EntityAnimated::facingLeft = facingLeft;
}

TextureRegion EntityAnimated::getCurrentFrame() const {
	return currentFrame;
}

void EntityAnimated::setCurrentFrame(TextureRegion currentFrame) {
	EntityAnimated::currentFrame = currentFrame;
}

void EntityAnimated::processAnimation(const float dt) {

}

EntityAnimated::EntityAnimated(float x, float y) : GameObject(x, y) {

}

void EntityAnimated::setFacing() {
	dx > 0 ? setFacingLeft(false) : setFacingLeft(true);
}




