//
// Created by Viktor on 17.1.2021 г..
//

#ifndef MOD_SCORE_H
#define MOD_SCORE_H

#include "../../include/game_utils.h"
#include "mod_logic.h"

class ModScore : public ModLogic{
private:
	Gamelib& game;
public:
	explicit ModScore(Gamelib& game);
	void init() override;
	void update() override;
	void post(Event* e) override;
	void reinit() override;
};


#endif //MOD_SCORE_H
