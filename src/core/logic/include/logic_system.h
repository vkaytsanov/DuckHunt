//
// Created by Viktor on 17.12.2020 г..
//

#ifndef DUCKHUNT_LOGIC_SYSTEM_H
#define DUCKHUNT_LOGIC_SYSTEM_H


#include "mod_logic.h"
#include "mod_create_objects.h"
#include "mod_score.h"
#include "mod_event_handler.h"
#include "mod_round.h"
#include "mod_shots.h"
#include "mod_game_object_movement.h"
#include "mod_script_handler.h"
#include "mod_duck_spawner.h"


class LogicSystem : public ModLogic{
private:
	Gamelib& game;
	std::vector<ModLogic*> modules;
	ModEventHandler eventHandler;
	ModScriptHandler scriptHandler;
	ModCreateObjects modCreateObjects;
	ModScore modScore;
	ModRound modRound;
	ModShots modShots;
	ModGameObjectMovement modDuckMovement;
	ModDuckSpawner modDuckSpawner;
	bool initialLoadingComplete = false;
public:
    LogicSystem(Gamelib& game);
	void init() override;
	void update() override;
	void post(Event* e);
	void reinit() override;
	void addScript(Script* s);
	bool isInitialLoadingComplete() const;
};


#endif //DUCKHUNT_LOGIC_SYSTEM_H
