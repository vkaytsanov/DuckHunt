//
// Created by Viktor on 17.1.2021 г..
//

#ifndef MOD_ROUND_H
#define MOD_ROUND_H


#include "mod_logic.h"

class ModRound : public ModLogic{
private:
	Gamelib& game;
	void displayNewRound();
public:
	ModRound(Gamelib& game);
	void init() override;
	void update() override;
	void post(Event* e) override;
	void reinit() override;
};


#endif //MOD_ROUND_H
