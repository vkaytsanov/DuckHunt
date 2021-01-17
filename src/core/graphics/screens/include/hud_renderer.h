//
// Created by Viktor on 17.1.2021 г..
//

#ifndef HUD_RENDERER_H
#define HUD_RENDERER_H

#include "../../../../lib/utils/ui/include/label.h"
#include "../../../../lib/utils/ui/include/user_interface.h"
#include "../../../../lib/utils/include/texture.h"
#include "../../../graphics/include/graphics_system.h"



class HudRenderer {
private:
	Gamelib& game;
	Texture* bullet;
	TextureRegion ducks[2];
	UserInterface userInterface;
	Label scoreLabel;
	Label roundLabel;
public:
	explicit HudRenderer(Gamelib& game);
	void draw(const float& dt);
};


#endif //HUD_RENDERER_H
