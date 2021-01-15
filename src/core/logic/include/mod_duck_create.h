//
// Created by Viktor on 15.1.2021 г..
//

#ifndef MOD_DUCK_CREATE_H
#define MOD_DUCK_CREATE_H


#include "mod_logic.h"
#include "../../include/game_utils.h"

class ModDuckCreate : public ModLogic{
private:
	Gamelib& game;
public:
	explicit ModDuckCreate(Gamelib &game);
	void init() override;
	void update() override;
	void post() override;
	void reinit() override;
};


#endif //MOD_DUCK_CREATE_H
