#include "listener.h"
#include "duckhunt.h"
#include <iostream>
void DuckHunt::create(ApplicationInterface* app) {
	this->app = app;
}

void DuckHunt::render() {
	app->log("Delta", "10");
	app->error("Delta", "20");
}

void DuckHunt::dispose() {
	
}
