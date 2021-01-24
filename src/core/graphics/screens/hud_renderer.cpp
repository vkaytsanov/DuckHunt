//
// Created by Viktor on 17.1.2021 г..
//

#include "include/hud_renderer.h"
#include "../../include/game_utils.h"

HudRenderer::HudRenderer(Gamelib& game) : game(game), flyAwayWindow(game), roundWindow(game), endOfRoundWindow(game) {
	bullet = game.dataSystem->assets.getSprite("bullet");
	ducks[0].set(game.dataSystem->assets.getSprite("ducks-ui"), 0, 0, 8, 7);
	ducks[1].set(game.dataSystem->assets.getSprite("ducks-ui"), 8, 0, 8, 7);

	LabelStyle* whiteStyle = new LabelStyle("pixel-emulator.ttf", 18);
	whiteStyle->color = {0xff, 0xff, 0xff};

	scoreLabel.setText("000000");
	scoreLabel.setAlign(Right);

	roundLabel.setText("0");

	scoreLabel.setStyle(whiteStyle);
	LabelStyle* greenStyle = new LabelStyle(whiteStyle->font, {0x75, 0xcb, 0x0b, 0xff});
	greenStyle->size = 20;
	roundLabel.setStyle(greenStyle);

	for (int i = 0; i < 3; i++) {
		shotScoreLabels[i].setText(std::to_string(500 + 500 * i));
		shotScoreLabels[i].setStyle(whiteStyle);
		shotScoreLabels[i].setSize(i == 0 ? 30 : 50, 40);
		shotScoreLabels[i].setVisible(false);
		userInterface.addActor(&shotScoreLabels[i]);
	}

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

}

void HudRenderer::draw(const float& dt) {
	if (std::stoi(roundLabel.getText()) != game.dataSystem->currentGameData.round) {
		roundLabel.setText(std::to_string(game.dataSystem->currentGameData.round));
		roundLabel.updateText();
	}

	for (int i = 0; i < game.dataSystem->currentGameData.shots; i++) {
		bullet->draw(GRAPHICS_WIDTH / 2 - 195 + 15 * i, GRAPHICS_HEIGHT - 70, 8, 14);
	}
	for (int i = 0; i < 10; i++) {
		ducks[game.dataSystem->currentGameData.ducksTracker[i]].draw(GRAPHICS_WIDTH / 2 - 63 + 15 * i,
		                                                             GRAPHICS_HEIGHT - 70, 14, 14);
	}

	userInterface.act(dt);
	userInterface.draw();


}

