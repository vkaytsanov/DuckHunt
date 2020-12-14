#pragma once
#include "listener.h"
#include "logger.h"
#include "graphics.h"

class Application {
private:
	bool running;
protected:
	Listener* listener;
	Configuration* config;
	Graphics* graphics;
	Logger* logger;
public:
	Application(Listener* listener);
	Application(Listener* listener, Configuration* config);
	Application(Listener* listener, Configuration* config, Graphics* graphics);
	void gameLoop();
	void exit();
	void dispose();
};