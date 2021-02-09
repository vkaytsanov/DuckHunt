//
// Created by Viktor on 15.1.2021 г..
//

#ifndef MOD_OBJECTS_HANDLER_H
#define MOD_OBJECTS_HANDLER_H


#include "mod_logic.h"


class ModObjectsHandler : public ModLogic {
private:
	Gamelib* game;
public:
	explicit ModObjectsHandler(Gamelib* game);
	void init() override;
	void update() override;
	void post(Event* e) override;
	void reinit() override;
};


#endif //MOD_OBJECTS_HANDLER_H
