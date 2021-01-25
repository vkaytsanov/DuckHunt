//
// Created by Viktor on 14.1.2021 г..
//

#include "include/entity_animated.h"

bool EntityAnimated::isVisible() const {
	return visible;
}

void EntityAnimated::setVisible(const bool visible) {
	EntityAnimated::visible = visible;
}

bool EntityAnimated::isFacingLeft() const {
	return facingLeft;
}

void EntityAnimated::setFacingLeft(const bool facingLeft) {
	EntityAnimated::facingLeft = facingLeft;
}

TextureRegion EntityAnimated::getCurrentFrame() const {
	return currentFrame;
}

void EntityAnimated::setCurrentFrame(const TextureRegion& currentFrame) {
	EntityAnimated::currentFrame = currentFrame;
}

void EntityAnimated::processAnimation(const float dt) {

}

EntityAnimated::EntityAnimated(const float x, const float y) : GameObject(x, y) {

}

void EntityAnimated::setFacing() {
	dx > 0 ? setFacingLeft(false) : setFacingLeft(true);
}




