//
// Created by Viktor on 24.1.2021 г..
//

#include "include/end_of_round_window.h"
#include "../../include/game_utils.h"

EndOfRoundWindow::EndOfRoundWindow(Gamelib& game) {
	background = game.dataSystem->assets.getSprite("window");


	setVisible(false);

	LabelStyle style("pixel-emulator.ttf", 20);

	gameOverLabel.setText("GAME OVER");
	perfectLabel.setText("PERFECT");
	pointsLabel.setText("10000");

	gameOverLabel.setStyle(&style);
	perfectLabel.setStyle(&style);
	pointsLabel.setStyle(&style);




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
	currentType = type;
	if(type == PERFECT){
		this->setVisible(true);
		perfectLabel.setVisible(true);
		pointsLabel.setVisible(true);
		gameOverLabel.setVisible(false);
		setSize(200, 90);
		setPosition(GRAPHICS_WIDTH / 2 - getWidth() / 2, GRAPHICS_HEIGHT / 2 - getHeight() * 2);

		perfectLabel.setPosition(this->getX() + 20, this->getY() + 5);
		perfectLabel.setSize(this->getWidth() - 30, 40);

		pointsLabel.setSize(100, 40);
		pointsLabel.setPosition(this->getX() + (this->getWidth() - pointsLabel.getWidth()) / 2,
		                        perfectLabel.getY() + pointsLabel.getHeight());
	}
	else if(type == GAME_OVER){
		this->setVisible(true);
		perfectLabel.setVisible(false);
		pointsLabel.setVisible(false);
		gameOverLabel.setVisible(true);
		setSize(200, 50);
		setPosition(GRAPHICS_WIDTH / 2 - getWidth() / 2, GRAPHICS_HEIGHT / 2 - getHeight() * 2);

		gameOverLabel.setPosition(this->getX() + 10, this->getY() + 10);
		gameOverLabel.setSize(this->getWidth() - 20, this->getHeight() - 20);
	}

}
