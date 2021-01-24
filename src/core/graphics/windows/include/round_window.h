//
// Created by Viktor on 24.1.2021 г..
//

#ifndef ROUND_WINDOW_H
#define ROUND_WINDOW_H


#include "window.h"
#include "fly_away_window.h"

class Gamelib;


class RoundWindow : public Window{
private:
	Gamelib& game;
	Label roundLabel;
	Label roundNumber;
public:
	explicit RoundWindow(Gamelib& game);
	void update();
	void draw() override;
};


#endif //ROUND_WINDOW_H
