//
// Created by Viktor on 17.12.2020 г..
//

#include "include/logic_system.h"
#include "../../lib/include/lib.h"
#include "../include/game_utils.h"
#include "events/include/start_round.h"
#include "events/include/start_spawning.h"
#include "scripts/include/dog_sniffing_script.h"

#define SKIP_INTRO 0

LogicSystem::LogicSystem(Gamelib& game) : game(game),
                                          modCreateObjects(game),
                                          eventHandler(),
                                          scriptHandler(game),
                                          modScore(game),
                                          modRound(game),
                                          modShots(game),
                                          modDuckMovement(game),
                                          modDuckSpawner(game),
                                          modDuckTracker(game),
                                          modDifficultyController(game){
	modules.emplace_back(&modCreateObjects);
	modules.emplace_back(&modScore);
	modules.emplace_back(&modRound);
	modules.emplace_back(&modDuckMovement);
	modules.emplace_back(&modDuckSpawner);
	modules.emplace_back(&modDuckTracker);
	modules.emplace_back(&modDifficultyController);
	modules.emplace_back(&modShots);

}

void LogicSystem::init() {
	for (ModLogic* mod : modules) {
		mod->init();
	}
}

void LogicSystem::update() {
	if (game.gameStateManager->getCurrentState() == Playing) {
		eventHandler.update(modules);
		scriptHandler.update();
		for (ModLogic* mod : modules) {
			mod->update();
		}
	}
}

void LogicSystem::post(Event* e) {
	if (e->name == "StartRound") {
		Lib::app->log("Event", "StartRound posted");
#if SKIP_INTRO
		// add event to start spawning
		game.logicSystem->post(new StartSpawning());
		// Gives input to the playing screen
		game.graphicsSystem->start(Playing);
		Dog& dog = game.dataSystem->dogData.getDog();
		dog.setDrawBefore(true);
		dog.setVisible(false);
#else
		game.audioSystem->playMusic(INTRO);
		scriptHandler.addScript(new DogSniffingScript(game));
#endif
		auto* s = dynamic_cast<StartRound*>(e);
		if(s->difficultyLevel != NONE) {
			game.gameStateManager->changeState(Playing);
			game.dataSystem->currentGameData.difficultyLevel = s->difficultyLevel;
		}
	}
	if(e->name == "Reinitialize"){
		for(ModLogic* mod : modules){
			mod->reinit();
		}
	}else{
		eventHandler.post(e);
	}

}

void LogicSystem::reinit() {
	for (ModLogic* mod : modules) {
		mod->reinit();
	}
}

bool LogicSystem::isInitialLoadingComplete() const {
	return initialLoadingComplete;
}

void LogicSystem::addScript(Script* s) {
	scriptHandler.addScript(s);
}

int LogicSystem::getScriptsSize() {
	return scriptHandler.size();
}



