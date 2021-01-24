//
// Created by Viktor on 18.1.2021 г..
//

#ifndef SHOTS_RECEIVER_H
#define SHOTS_RECEIVER_H

#include <SDL.h>
#include "../../../lib/utils/include/input_processor.h"

class Gamelib;

class ShotsReceiver : public InputProcessor{
private:
	Gamelib& game;
public:
	explicit ShotsReceiver(Gamelib& game);
	void touchDown(SDL_Event& e, float x, float y) override;
	void touchUp(SDL_Event& e, float x, float y) override;
	void keyDown(SDL_Event& e, int key) override;
	void keyUp(SDL_Event& e, int key) override;
};


#endif //SHOTS_RECEIVER_H
