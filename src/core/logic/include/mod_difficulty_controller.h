//
// Created by Viktor on 25.1.2021 г..
//

#ifndef MOD_DIFFICULTY_CONTROLLER_H
#define MOD_DIFFICULTY_CONTROLLER_H


#include "mod_logic.h"

/** @link https://strategywiki.org/wiki/Duck_Hunt */
class ModDifficultyController : public ModLogic {
private:
	Gamelib& game;
	void setDuckScores(int score);
	void setMinimumDucksToAdvance(int minimum);
	void setDucksModSpeed(float additionalAmount);
	void resetDucksModSpeed();
public:
	explicit ModDifficultyController(Gamelib& game);
	void init() override;
	void update() override;
	void post(Event* e) override;
	void reinit() override;
};


#endif //MOD_DIFFICULTY_CONTROLLER_H
