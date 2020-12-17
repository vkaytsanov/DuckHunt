#pragma once
#include "listener.h"
#include "logger.h"
#include "graphics.h"
#include "input.h"


class Application{
private:
	bool running;
	Listener* listener;
    Input* input;
	Configuration* config;

	void gameLoop();
	void exitApp();
public:
    Graphics* graphics;
    Logger* logger;
	explicit Application(Listener* listener);
	Application(Listener* listener, Configuration* config);
	Application(Listener* listener, Configuration* config, Graphics* graphics);
	~Application();
    void log(const char* tag, const char* message);
    void error(const char* tag, const char* message);

};