//
// Created by Viktor on 17.12.2020 г..
//

#include "include/application.h"

#include <typeinfo>


Application::Application(Listener* listener) :
	Application(listener, new Configuration()){}

Application::Application(Listener* listener, Configuration* config) :
	Application(listener, config, new Graphics(config)){}

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
	// creating the environment utils
//    Lib::initialize(this, graphics);
    // creating the objects from the game
	listener->create();

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

void Application::exitApp() {
	running = false;
}

Application::~Application() {
    delete logger;
    delete listener;
    delete graphics;
    delete config;
}

void Application::log(const char *tag, const char *message) {
    logger->log(tag, message);
}

void Application::error(const char *tag, const char *message) {
    logger->error(tag, message);
}


