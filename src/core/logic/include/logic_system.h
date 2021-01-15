//
// Created by Viktor on 17.12.2020 г..
//

#ifndef DUCKHUNT_LOGIC_SYSTEM_H
#define DUCKHUNT_LOGIC_SYSTEM_H


#include "mod_logic.h"

class LogicSystem : public ModLogic{
public:
    LogicSystem();
	void init() override;
	void update() override;
	void post() override;
	void reinit() override;
};


#endif //DUCKHUNT_LOGIC_SYSTEM_H
