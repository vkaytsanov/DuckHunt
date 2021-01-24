//
// Created by Viktor on 18.1.2021 г..
//

#include "include/mod_script_handler.h"

void ModScriptHandler::init() {

}

void ModScriptHandler::update() {
	std::list<Script*>::iterator i = scripts.begin();
	while(i != scripts.end()){
		bool isDone = (*i)->update(game);
		if(isDone){
			scripts.erase(i);
			i = scripts.begin();
		}
		else {
			++i;
		}
	}
}

void ModScriptHandler::post(Event* e) {

}

void ModScriptHandler::reinit() {
	while(!scripts.empty()){
		scripts.pop_front();
	}
}

ModScriptHandler::ModScriptHandler(Gamelib& game) : game(game){

}

void ModScriptHandler::addScript(Script* s) {
	scripts.emplace_back(s);
}

int ModScriptHandler::size() {
	return scripts.size();
}
