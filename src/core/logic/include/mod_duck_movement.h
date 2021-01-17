//
// Created by Viktor on 17.1.2021 г..
//

#ifndef MOD_DUCK_MOVEMENT_H
#define MOD_DUCK_MOVEMENT_H

#include "../../include/game_utils.h"
#include "mod_logic.h"

class ModDuckMovement : public ModLogic{
private:
	Gamelib& game;
	void move(GameObject& e, const float& dx, const float& dy);
public:
	explicit ModDuckMovement(Gamelib& game);
	void init() override;
	void update() override;
	void post(Event* e) override;
	void reinit() override;
};


#endif //MOD_DUCK_MOVEMENT_H
