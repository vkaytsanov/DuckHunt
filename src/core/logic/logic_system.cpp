//
// Created by Viktor on 17.12.2020 г..
//

#include "include/logic_system.h"
#include "../../lib/include/lib.h"
#include "../include/game_utils.h"
#include "scripts/include/dog_sniffing_script.h"
#include "events/include/start_round.h"

LogicSystem::LogicSystem(Gamelib& game) : game(game),
                                          modCreateObjects(game),
                                          eventHandler(),
                                          scriptHandler(game),
                                          modScore(game),
                                          modRound(game),
                                          modShots(game),
                                          modDuckMovement(game),
                                          modDuckSpawner(game){
	modules.emplace_back(&modCreateObjects);
	modules.emplace_back(&modScore);
	modules.emplace_back(&modRound);
	modules.emplace_back(&modShots);
	modules.emplace_back(&modDuckMovement);
	modules.emplace_back(&modDuckSpawner);

}

void LogicSystem::init() {
	for(ModLogic* mod : modules){
		mod->init();
	}
}

void LogicSystem::update() {
	if(game.gameStateManager->getCurrentState() == Playing) {
		eventHandler.update(modules);
		scriptHandler.update();
		for(ModLogic* mod : modules){
			mod->update();
		}
	}
}

void LogicSystem::post(Event* e) {
	if(e->name == "StartRound"){
		Lib::app->log("Event", "StartRound posted");
		game.gameStateManager->changeState(Playing);
		game.audioSystem->playMusic(INTRO);
		scriptHandler.addScript(new DogSniffingScript(game));
		StartRound* s = static_cast<StartRound*>(e);
		modDuckSpawner.setCurrentDifficultyLevel(s->difficultyLevel);
		for(ModLogic* mod : modules){
			mod->reinit();
		}
	}

	eventHandler.post(e);

}

void LogicSystem::reinit() {
	for(ModLogic* mod : modules){
		mod->reinit();
	}
}

bool LogicSystem::isInitialLoadingComplete() const {
	return initialLoadingComplete;
}

void LogicSystem::addScript(Script* s) {
	scriptHandler.addScript(s);
}



