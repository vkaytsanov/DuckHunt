#include "include/application.h"
#include "include/configuration.h"
#include <typeinfo>

Application::Application(Listener* listener) {
	Application(listener, new Configuration());
}


Application::Application(Listener* listener, Configuration* config) {
	Application(listener, config, new Graphics(config));
}

/* Initializing here the application */
Application::Application(Listener* listener, Configuration* config, Graphics* graphics) {
	// Our game 
	this->listener = listener;
	// Our configuration file for the game
	this->config = config;
	// Our library for graphics 
	this->graphics = graphics;
	// Logging, debugging and errors utility
	this->logger = new Logger();
	// Receive user input
	this->input = new Input();
	// if we dont have declared title, we will use the name of the class
	if (config->title == nullptr) config->title = typeid(listener).name();
	// creating the window
	graphics->createWindow();
	// creating the objects from the game
	copy = this;
	listener->create(copy);
	
	running = true;

	gameLoop();
}

void Application::gameLoop() {
	while (running) {
		input->update();
		if (input->shouldQuit()) running = false;
		graphics->updateTime();
		listener->render();
		
		/* So we don't use 100% CPU */
		SDL_Delay(1);
	}
	// cleaning the memory if we are no longer running the game loop
}

void Application::exit() {
	running = false;
}


void Application::log(const char* tag, const char* message) {
	logger->log(tag, message);
}

void Application::error(const char* tag, const char* message) {
	logger->error(tag, message);
}

Application::~Application() {
    delete logger;
    delete listener;
    delete graphics;
    delete config;
}

