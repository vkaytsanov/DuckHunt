//
// Created by Viktor on 25.1.2021 г..
//

#ifndef MOD_DUCK_TRACKER_H
#define MOD_DUCK_TRACKER_H


#include "mod_logic.h"

class ModDuckTracker : public ModLogic{
private:
	Gamelib& game;
public:
	explicit ModDuckTracker(Gamelib& game);
	void init() override;
	void update() override;
	void post(Event* e) override;
	void reinit() override;
};


#endif //MOD_DUCK_TRACKER_H
