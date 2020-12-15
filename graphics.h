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
	uint16_t fps = 0;
	uint16_t frames = 0;
	uint64_t frameStart = 0;
public:
	Graphics(Configuration* config);
	void  updateTime();
	int	  getWidth();
	int   getHeight();
	float getDeltaTime();
	float getFps();
	void  createWindow();
	void  update();
	void  dispose();
};