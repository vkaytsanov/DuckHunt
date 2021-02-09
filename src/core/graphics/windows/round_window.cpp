//
// Created by Viktor on 24.1.2021 г..
//

#include "include/round_window.h"
#include "../../include/game_utils.h"

RoundWindow::RoundWindow(Gamelib* game, Fonts* fonts) : game(game) {
	background = game->dataSystem->assets.getSprite("window");
	setSize(200, 90);
	setPosition(GRAPHICS_WIDTH / 2 - getWidth() / 2, GRAPHICS_HEIGHT / 2 - getHeight() * 2);
	setVisible(false);
	style = new LabelStyle(fonts->getMainFont(), 20);

	roundLabel.setText("ROUND");
	roundLabel.setStyle(style);
	roundLabel.setPosition(this->getX() + 20, this->getY() + 5);
	roundLabel.setSize(this->getWidth() - 30, 40);

	roundNumber.setText("1");
	roundNumber.setStyle(style);
	roundNumber.setSize(20, 30);
	roundNumber.setPosition(this->getX() + (this->getWidth() - roundNumber.getWidth() / 2) / 2,
	                        roundLabel.getY() + roundLabel.getHeight());
}


void RoundWindow::draw() {
	Window::draw();
	roundLabel.draw();
	roundNumber.draw();
}

void RoundWindow::update() {
	roundNumber.setText(std::to_string(game->dataSystem->currentGameData.round));
	roundNumber.updateText();
}

RoundWindow::~RoundWindow() {
	delete style;
}