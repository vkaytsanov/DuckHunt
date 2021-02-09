//
// Created by Viktor on 17.1.2021 г..
//

#include "include/hud_renderer.h"
#include "../../include/game_utils.h"

HudRenderer::HudRenderer(Gamelib* game, Fonts* fonts) : game(game), flyAwayWindow(game, fonts), roundWindow(game, fonts),
                                                        endOfRoundWindow(game, fonts) {
	bullet = game->dataSystem->assets.getSprite("bullet");
	ducks[0].set(game->dataSystem->assets.getSprite("ducks-ui"), 0, 0, 8, 7);
	ducks[1].set(game->dataSystem->assets.getSprite("ducks-ui"), 8, 0, 8, 7);

	minimumDucksIndicator = game->dataSystem->assets.getSprite("minimum-ducks-indicator");

	whiteStyle = new LabelStyle(fonts->getMainFont(), 18);
	whiteStyle->color = {0xff, 0xff, 0xff};

	scoreLabel.setText("000000");
	scoreLabel.setAlign(Right);

	roundLabel.setText("0");

	scoreLabel.setStyle(whiteStyle);
	greenStyle = new LabelStyle(fonts->getMainFont(), {0x75, 0xcb, 0x0b, 0xff}, 20);

	roundLabel.setStyle(greenStyle);

	shotScoreLabel.setStyle(whiteStyle);
	shotScoreLabel.setSize(50, 40);
	shotScoreLabel.setVisible(false);
	userInterface.addActor(&shotScoreLabel);


	scoreLabel.setWidth(90);
	scoreLabel.setHeight(30);
	scoreLabel.setX((float) GRAPHICS_WIDTH / 2 + 125);
	scoreLabel.setY((float) GRAPHICS_HEIGHT - 80);

	roundLabel.setWidth(20);
	roundLabel.setHeight(25);
	roundLabel.setX((float) GRAPHICS_WIDTH / 2 - 168);
	roundLabel.setY((float) GRAPHICS_HEIGHT - 113);

	userInterface.addActor(&scoreLabel);
	userInterface.addActor(&roundLabel);
	userInterface.addActor(&flyAwayWindow);
	userInterface.addActor(&roundWindow);
	userInterface.addActor(&endOfRoundWindow);

}

void HudRenderer::draw(const float dt) {
	for (int i = 0; i < game->dataSystem->currentGameData.shots; i++) {
		bullet->draw(GRAPHICS_WIDTH / 2 - 195 + 15 * i, GRAPHICS_HEIGHT - 70, 8, 14);
	}
	for (int i = 0; i < 10; i++) {
		ducks[game->dataSystem->currentGameData.ducksTracker[i]].draw(GRAPHICS_WIDTH / 2 - 63 + 15 * i,
		                                                             GRAPHICS_HEIGHT - 70, 14, 14);
	}

	for (int i = 0; i < game->dataSystem->currentGameData.minimumDucksToAdvance; i++) {
		minimumDucksIndicator->draw(GRAPHICS_WIDTH / 2 - 63 + 15 * i,
		                            GRAPHICS_HEIGHT - 50, 14, 14);
	}

	userInterface.act(dt);
	userInterface.draw();


}


HudRenderer::~HudRenderer() {
	delete whiteStyle;
	delete greenStyle;
}
