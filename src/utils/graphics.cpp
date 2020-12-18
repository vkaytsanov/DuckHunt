#include "include/graphics.h"
#include <chrono>


Graphics::Graphics(Configuration* config) {
	this->config = config;
	screenSurface = nullptr;
	window = nullptr;
}

void Graphics::updateTime() {
	// calculating the delta time
	uint64_t time = SDL_GetTicks();
	deltaTime = (time - lastTime) / 1000.0f;
	lastTime = time;

	// calculating fps
	if (time - frameStart >= 1000) {
		fps = frames;
		frames = 0;
		frameStart = time;
	}
	frames++;
}

int Graphics::getWidth() {
	return config->width;
}

int Graphics::getHeight() {
	return config->height;
}

float Graphics::getDeltaTime() const {
	return deltaTime;
}

float Graphics::getFps() {
	return fps;
}

void Graphics::createWindow() {
	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		exit(-1);
	}
	else {
		//Create window
		window = SDL_CreateWindow(config->title, config->x, config->y,
			config->width, config->height, config->isVisible);
		if (window == nullptr) {
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			exit(-1);
		}
		else {
			//Get window surface
			screenSurface = SDL_GetWindowSurface(window);

			//Update the surface
			SDL_UpdateWindowSurface(window);
		}
	}

}

void Graphics::update() {
	SDL_UpdateWindowSurface(window);
}

Graphics::~Graphics() {
    //Destroy surface
    SDL_FreeSurface(screenSurface);
    screenSurface = nullptr;
    //Destroy window
    SDL_DestroyWindow(window);
    window = nullptr;
    //Quit SDL subsystems
    SDL_Quit();
}

Graphics::Graphics() {
    config = new Configuration();
}

