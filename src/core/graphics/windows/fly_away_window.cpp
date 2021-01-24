//
// Created by Viktor on 23.1.2021 г..
//

#include "include/fly_away_window.h"
#include "../../include/game_utils.h"

FlyAwayWindow::FlyAwayWindow(Gamelib& game){
	background = game.dataSystem->assets.getSprite("window");
	setSize(200, 50);
	setPosition(GRAPHICS_WIDTH / 2 - getWidth() / 2, GRAPHICS_HEIGHT / 2 - getHeight() * 2);
	setVisible(false);
	LabelStyle style("pixel-emulator.ttf", 20);
	flyAway.setText("FLY AWAY");
	flyAway.setStyle(&style);
	flyAway.setPosition(this->getX() + 10, this->getY() + 10);
	flyAway.setSize(this->getWidth() - 20, this->getHeight() - 20);

}

void FlyAwayWindow::draw() {
	Window::draw();
	flyAway.draw();
}
