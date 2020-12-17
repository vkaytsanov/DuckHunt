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
	void exitApp();
    Application* copy; // to send to the listener
public:
	explicit Application(Listener* listener);
	Application(Listener* listener, Configuration* config);
	Application(Listener* listener, Configuration* config, Graphics* graphics);
	~Application();

	
	// Inherited via ApplicationInterface
	void log(const char* tag, const char* message) override;
	void error(const char* tag, const char* message) override;

};