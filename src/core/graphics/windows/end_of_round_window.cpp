//
// Created by Viktor on 24.1.2021 г..
//

#include "include/end_of_round_window.h"
#include "../../include/game_utils.h"

EndOfRoundWindow::EndOfRoundWindow(Gamelib& game) {
	background = game.dataSystem->assets.getSprite("window");
	LabelStyle style("pixel-emulator.ttf", 20);

	gameOverLabel.setText("GAME OVER");
	perfectLabel.setText("PERFECT");
	pointsLabel.setText("10000");

	gameOverLabel.setStyle(&style);
	perfectLabel.setStyle(&style);
	pointsLabel.setStyle(&style);

	gameOverLabel.setPosition(this->getX() + 10, this->getY() + 10);
	gameOverLabel.setSize(this->getWidth() - 20, this->getHeight() - 20);

	perfectLabel.setPosition(this->getX() + 20, this->getY() + 5);
	perfectLabel.setSize(this->getWidth() - 30, 40);

	pointsLabel.setSize(80, 30);
	pointsLabel.setPosition(this->getX() + (this->getWidth() - pointsLabel.getWidth() / 2) / 2,
	                        pointsLabel.getY() + pointsLabel.getHeight());
}

void EndOfRoundWindow::draw() {
	if(currentType != NOTHING) {
		Window::draw();
		if(currentType == PERFECT){
			perfectLabel.draw();
			pointsLabel.draw();
		}
		else{
			gameOverLabel.draw();
		}
	}
}

void EndOfRoundWindow::update(EndOfRoundType type) {
	if(this->isVisible()) return;

	if(type == PERFECT){
		this->setVisible(true);
		perfectLabel.setVisible(true);
		pointsLabel.setVisible(true);
		gameOverLabel.setVisible(false);
	}
	else if(type == GAME_OVER){
		this->setVisible(true);
		perfectLabel.setVisible(false);
		pointsLabel.setVisible(false);
		gameOverLabel.setVisible(true);
	}

}
