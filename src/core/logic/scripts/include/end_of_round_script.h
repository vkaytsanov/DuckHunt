//
// Created by Viktor on 24.1.2021 г..
//

#ifndef END_OF_ROUND_SCRIPT_H
#define END_OF_ROUND_SCRIPT_H


#include "script.h"
#include "../../../data/include/current_game_data.h"

class EndOfRoundScript : public Script{
private:
	float currentTime = 0.0f;
	const float WAIT_TIME = 1.5f;
	int ducksAlive = 0;
	bool blinked = false;
	float scoreCounter = 0;
	DuckTracker duckTracker[10] = {ESCAPED};
	void sortDucksUI(Gamelib& game);
	void blinkDucksUI(Gamelib& game);
	void animateScoreGain(Gamelib& game);
	void EndOfRoundScript::displayNewScore(Gamelib& game) const;
public:
	explicit EndOfRoundScript(Gamelib& game);
	bool update(Gamelib& game) override;

};


#endif //END_OF_ROUND_SCRIPT_H
