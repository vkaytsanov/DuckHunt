#include "graphics.h"
#include "configuration.h"
#include <chrono>

typedef std::chrono::time_point<std::chrono::system_clock> time_point;
typedef std::chrono::duration<float, std::nano> nanos;


Graphics::Graphics(Configuration* config) {
	this->config = config;
	screenSurface = nullptr;
	window = nullptr;
}

void Graphics::updateTime() {
	time_point now = std::chrono::system_clock::now();
	auto duration = now.time_since_epoch();
	float time = nanos(duration).count();
	deltaTime = (time - lastTime) / 1000000000.0f;
	lastTime = time;

	if (time - frameStart >= 1000000000) {
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

float Graphics::getDeltaTime() {
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
		if (window == NULL) {
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

void Graphics::handleEvents() {
	SDL_Event e;
	while (SDL_PollEvent(&e) != 0) {
		//User requests quit
		if (e.type == SDL_QUIT) {
			quit = true;
		}
	}
}

void Graphics::dispose() {
	//Destroy surface
	SDL_FreeSurface(screenSurface);
	screenSurface = nullptr;
	//Destroy window
	SDL_DestroyWindow(window);
	window = nullptr;
	//Quit SDL subsystems
	SDL_Quit();
}

bool Graphics::shouldStop() {
	return quit;
}
