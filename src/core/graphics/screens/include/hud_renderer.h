//
// Created by Viktor on 17.1.2021 г..
//

#ifndef HUD_RENDERER_H
#define HUD_RENDERER_H

#include "../../../../lib/utils/ui/include/label.h"
#include "../../../../lib/utils/ui/include/user_interface.h"
#include "../../../../lib/utils/include/texture.h"
#include "../../../../lib/utils/include/texture_region.h"
#include "../../../graphics/include/graphics_system.h"
#include "../../windows/include/fly_away_window.h"
#include "../../windows/include/round_window.h"
#include "../../windows/include/end_of_round_window.h"


class HudRenderer {
private:
	Gamelib* game;
	Texture* bullet;
	TextureRegion ducks[2];
	Texture* minimumDucksIndicator;
	UserInterface userInterface;
	LabelStyle* whiteStyle;
	LabelStyle* greenStyle;
public:
	~HudRenderer();
	FlyAwayWindow flyAwayWindow;
	RoundWindow roundWindow;
	EndOfRoundWindow endOfRoundWindow;
	// the scores that will pop when a duck is shot
	Label shotScoreLabel;
	Label scoreLabel;
	Label roundLabel;
	explicit HudRenderer(Gamelib* game, Fonts* fonts);
	void draw(const float dt);
};


#endif //HUD_RENDERER_H
