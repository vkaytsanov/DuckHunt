//
// Created by Viktor on 15.1.2021 г..
//

#ifndef MOD_INPUT_HANDLER_H
#define MOD_INPUT_HANDLER_H


#include "mod_logic.h"

class ModInputHandler : public ModLogic{
public:
	void init() override;
	void update() override;
	void post(Event* e) override;
	void reinit() override;
};


#endif //MOD_INPUT_HANDLER_H
