//
// Created by Viktor on 17.1.2021 г..
//

#include "include/mod_event_handler.h"
#include "../../lib/include/lib.h"


void ModEventHandler::update(std::vector<ModLogic*>& modules) {
	while(!events.empty()){
		Event* e = events.front();
		sendToModules(modules, e);
		delete e;
		events.pop();
	}
}

void ModEventHandler::post(Event* e) {
	events.push(e);
}


void ModEventHandler::sendToModules(std::vector<ModLogic*>& modules, Event* e) {
	for(ModLogic* mod : modules){
		Lib::app->log("Event", (e->name +  " posted").c_str());
		mod->post(e);
	}
}
