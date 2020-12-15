#pragma once
#include "SDL.h"
#include <memory>


class Input {
private:
	SDL_Event e;
	bool quit = false;
	/* check SDL_KeyCode, z is the 122th */
	bool currFrameKeys[123];
	bool lastFrameKeys[123];
public:
	void update();
	bool shouldQuit();
	bool isKeyPressed(const char key);
	bool isKeyJustPressed(const char key);
};