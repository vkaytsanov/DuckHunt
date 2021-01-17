//
// Created by Viktor on 17.1.2021 г..
//

#ifndef MOD_ROUND_H
#define MOD_ROUND_H

#include "../../include/game_utils.h"
#include "mod_logic.h"

class ModRound : public ModLogic{
private:
	Gamelib& game;
public:
	ModRound(Gamelib& game);
	void init() override;
	void update() override;
	void post(Event* e) override;
	void reinit() override;
};


#endif //MOD_ROUND_H
