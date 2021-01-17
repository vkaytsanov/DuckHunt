//
// Created by Viktor on 14.1.2021 г..
//

#ifndef ENTITY_ANIMATED_H
#define ENTITY_ANIMATED_H


#include "game_object.h"
#include "../../../lib/utils/include/texture.h"
#include "../../../data/include/assets.h"
#include "../../../../lib/utils/include/animation.h"

// TODO Animation Class
class EntityAnimated : public GameObject{
private:
    bool visible = false;
    bool facingLeft;
protected:
	TextureRegion currentFrame;
public:
	EntityAnimated() = default;
	EntityAnimated(float x, float y);
    virtual void loadEntity(Assets& assets) = 0;
	virtual void processAnimation(float dt);
	bool isVisible() const;
	void setVisible(bool visible);
	bool isFacingLeft() const;
	void setFacingLeft(bool facingLeft);
	TextureRegion getCurrentFrame() const;
	void setCurrentFrame(TextureRegion currentFrame);
};


#endif //ENTITY_ANIMATED_H
