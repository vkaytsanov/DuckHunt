//
// Created by Viktor on 14.1.2021 г..
//

#ifndef ENTITY_ANIMATED_H
#define ENTITY_ANIMATED_H


#include "game_object.h"
#include "../../lib/utils/include/texture.h"
#include "../../data/include/mod_assets.h"

// TODO Animation Class
class EntityAnimated : public GameObject{
private:
    bool visible;
    bool facingLeft;
    Texture* currentFrame;
public:
    virtual void loadEntity(Mod_Assets assets, float xPos, float yPos) = 0;
    virtual void parseAnimationFile() = 0;
    void processAnimation();
	bool isVisible() const;
	void setVisible(bool visible);
	bool isFacingLeft() const;
	void setFacingLeft(bool facingLeft);
	Texture* getCurrentFrame() const;
	void setCurrentFrame(Texture* currentFrame);
};


#endif //ENTITY_ANIMATED_H
