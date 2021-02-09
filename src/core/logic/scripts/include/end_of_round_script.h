//
// Created by Viktor on 24.1.2021 г..
//

#ifndef END_OF_ROUND_SCRIPT_H
#define END_OF_ROUND_SCRIPT_H


#include "script.h"
#include "../../../data/include/current_game_data.h"
#include "../../../graphics/windows/include/end_of_round_window.h"

class EndOfRoundScript : public Script{
private:
	Gamelib* game;
	EndOfRoundType type;
	float currentTime = 0.0f;
	const float WAIT_TIME = 1.5f;
	bool blinked = false;
	bool isCurrentTracker = false;
	float scoreCounter = 0.0f;
	DuckTracker duckTracker[10] = {ESCAPED};
	void sortDucksUI();
	void blinkDucksUI();
	void animateScoreGain();
	bool isAnimationComplete() const;
	void displayNewScore() const;
public:
	explicit EndOfRoundScript(Gamelib* game);
	bool update(Gamelib* game) override;

};


#endif //END_OF_ROUND_SCRIPT_H
