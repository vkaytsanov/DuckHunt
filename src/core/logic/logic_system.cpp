//
// Created by Viktor on 17.12.2020 г..
//

#include "include/logic_system.h"
#include "../../lib/include/lib.h"

LogicSystem::LogicSystem(Gamelib& game) : game(game),
                                          modCreateObjects(game),
                                          eventHandler(),
                                          modScore(game),
                                          modRound(game),
                                          modShots(game),
                                          modDuckMovement(game){
	modCreateObjects.init();
	modules.emplace_back(&modScore);
	modules.emplace_back(&modRound);
	modules.emplace_back(&modShots);
	modules.emplace_back(&modDuckMovement);

}

void LogicSystem::init() {

}

void LogicSystem::update() {
	//if(game.gameStateManager->getCurrentState() == Playing) {
		eventHandler.update(modules);
		for(ModLogic* mod : modules){
			mod->update();
		}
	//}
}

void LogicSystem::post(Event* e) {
	eventHandler.post(e);

}

void LogicSystem::reinit() {

}

bool LogicSystem::isInitialLoadingComplete() const {
	return initialLoadingComplete;
}



