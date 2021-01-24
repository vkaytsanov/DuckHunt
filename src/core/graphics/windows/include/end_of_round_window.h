//
// Created by Viktor on 24.1.2021 г..
//

#ifndef END_OF_ROUND_WINDOW_H
#define END_OF_ROUND_WINDOW_H


#include "window.h"
#include "../../../../lib/utils/ui/include/label.h"

class Gamelib;

// There are 3 types of outcome on the end of the round:
// 1. 10/10 Ducks slain -> PERFECT, 10_000 Score
// 2. Min number of ducks slain threshold reached -> Nothing happens
// 3. Min number of ducks slain threshold not reached -> Game Over
enum EndOfRoundType{
	PERFECT,
	NOTHING,
	GAME_OVER
};

class EndOfRoundWindow : public Window {
private:
	Label perfectLabel;
	Label pointsLabel;
	Label gameOverLabel;
	EndOfRoundType currentType;
public:
	explicit EndOfRoundWindow(Gamelib& game);
	void draw() override;
	void update(EndOfRoundType type);

};


#endif //END_OF_ROUND_WINDOW_H
