//
// Created by Viktor on 15.1.2021 г..
//

#ifndef MOD_CREATE_OBJECTS_H
#define MOD_CREATE_OBJECTS_H


#include "mod_logic.h"


class ModCreateObjects : public ModLogic {
private:
	Gamelib& game;
public:
	explicit ModCreateObjects(Gamelib& game);
	void init() override;
	void update() override;
	void post(Event* e) override;
	void reinit() override;
};


#endif //MOD_CREATE_OBJECTS_H
