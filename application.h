#pragma once
#include "listener.h"
#include "logger.h"
#include "graphics.h"
#include "application_interface.h"

class Application : public ApplicationInterface{
private:
	bool running;
	Listener* listener;
	Configuration* config;
	Logger* logger;
	void gameLoop();
	void exit();
	void dispose();
protected:
	Graphics* graphics;
public:
	Application(Listener* listener);
	Application(Listener* listener, Configuration* config);
	Application(Listener* listener, Configuration* config, Graphics* graphics);
	
	// Inherited via ApplicationInterface
	virtual void log(const char* tag, const char* message) override;
	virtual void error(const char* tag, const char* message) override;

};