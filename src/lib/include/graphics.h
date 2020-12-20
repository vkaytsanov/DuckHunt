#ifndef GRAPHICS
#define GRAPHICS

#include "configuration.h"
#include "SDL.h"
#include "SDL_image.h"

class Graphics {
private:
	Configuration* config;
	SDL_Window* window;
	SDL_Surface* screenSurface;
    SDL_Renderer* renderer;
	float lastTime = 0;
	float deltaTime = 0;
	uint16_t fps = 0;
	uint16_t frames = 0;
	uint64_t frameStart = 0;
public:
	explicit Graphics(Configuration* config);
	Graphics();
	~Graphics();
	void  updateTime();
	int	  getWidth();
	int   getHeight();
	float getDeltaTime() const;
	float getFps();
	void  createWindow();
	void  update();

    SDL_Renderer *getRenderer() const;
};

#endif