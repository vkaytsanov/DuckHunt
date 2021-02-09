//
// Created by Viktor on 24.1.2021 г..
//

#ifndef ROUND_WINDOW_H
#define ROUND_WINDOW_H


#include "window.h"
#include "fly_away_window.h"
#include "../../include/fonts.h"

class Gamelib;


class RoundWindow : public Window{
private:
	Gamelib* game;
	LabelStyle* style;
	Label roundLabel;
	Label roundNumber;
public:
	explicit RoundWindow(Gamelib* game, Fonts* fonts);
	~RoundWindow();
	void update();
	void draw() override;
};


#endif //ROUND_WINDOW_H
