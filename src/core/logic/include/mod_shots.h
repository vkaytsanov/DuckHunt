//
// Created by Viktor on 17.1.2021 г..
//

#ifndef MOD_SHOTS_H
#define MOD_SHOTS_H


#include "mod_logic.h"

class ModShots : public ModLogic {
private:
	Gamelib& game;
public:
	ModShots(Gamelib& game);
	void init() override;
	void update() override;
	void post(Event* e) override;
	void reinit() override;
};


#endif //MOD_SHOTS_H
