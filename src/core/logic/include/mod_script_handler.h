//
// Created by Viktor on 18.1.2021 г..
//

#ifndef MOD_SCRIPT_HANDLER_H
#define MOD_SCRIPT_HANDLER_H


#include <list>
#include "mod_logic.h"
#include "../scripts/include/script.h"

class ModScriptHandler : ModLogic{
private:
	Gamelib* game;
	std::list<Script*> scripts;
public:
	explicit ModScriptHandler(Gamelib* game);
	void addScript(Script* s);
	void init() override;
	void update() override;
	void post(Event* e) override;
	void reinit() override;
	int size();
};


#endif //MOD_SCRIPT_HANDLER_H
