//
// Created by Viktor on 23.1.2021 г..
//

#ifndef FLY_AWAY_WINDOW_H
#define FLY_AWAY_WINDOW_H


#include "window.h"
#include "../../../../lib/utils/ui/include/label.h"

class Gamelib;

class FlyAwayWindow : public Window{
private:
	Label flyAway;
public:
	explicit FlyAwayWindow(Gamelib& game);
	void draw() override;
};


#endif //FLY_AWAY_WINDOW_H
