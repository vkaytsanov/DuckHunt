#pragma once
#include "configuration.h"
#include "SDL.h"

class Graphics {
private:
	Configuration* config;
	SDL_Window* window;
	SDL_Surface* screenSurface;
	float lastTime = 0;
	float deltaTime = 0;
	int fps = 0;
	int frames = 0;
	unsigned long frameStart = 0;
	bool quit = false;
public:
	Graphics(Configuration* config);
	void  updateTime();
	int	  getWidth();
	int   getHeight();
	float getDeltaTime();
	float getFps();
	void  createWindow();
	void  handleEvents();
	void  dispose();
	bool  shouldStop();
};