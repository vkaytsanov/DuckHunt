//
// Created by Viktor on 15.1.2021 г..
//

#ifndef GAME_OBJECT_RENDERER_H
#define GAME_OBJECT_RENDERER_H


#include "../../include/game_utils.h"
#include "graphics_system.h"

class GameObjectRenderer {
private:
	Gamelib& game;
	void drawObject(EntityAnimated* e, const float& dt);
public:
	explicit GameObjectRenderer(Gamelib& game);
	void draw(const float& dt);

};


#endif //GAME_OBJECT_RENDERER_H
