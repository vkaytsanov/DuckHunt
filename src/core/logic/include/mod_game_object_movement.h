//
// Created by Viktor on 17.1.2021 г..
//

#ifndef MOD_GAME_OBJECT_MOVEMENT_H
#define MOD_GAME_OBJECT_MOVEMENT_H


#include "mod_logic.h"

class GameObject;

class ModGameObjectMovement : public ModLogic{
private:
	Gamelib& game;
	void move(GameObject* e, const float& dx, const float& dy);
public:
	explicit ModGameObjectMovement(Gamelib& game);
	void init() override;
	void update() override;
	void post(Event* e) override;
	void reinit() override;
};


#endif //MOD_GAME_OBJECT_MOVEMENT_H
