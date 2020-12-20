#ifndef INPUT
#define INPUT

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
    bool shouldQuit() const;
	bool isKeyPressed(const char key);
	bool isKeyJustPressed(const char key);
};

#endif