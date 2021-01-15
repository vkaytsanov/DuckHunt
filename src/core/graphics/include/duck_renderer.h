//
// Created by Viktor on 15.1.2021 г..
//

#ifndef DUCK_RENDERER_H
#define DUCK_RENDERER_H


#include "../../include/game_utils.h"
#include "graphics_system.h"

class DuckRenderer {
private:
	Gamelib& game;
public:
	DuckRenderer(Gamelib& game);
	void draw(const float& dt);
	void drawDuck(Duck& d, const float& dt);
};


#endif //DUCK_RENDERER_H
