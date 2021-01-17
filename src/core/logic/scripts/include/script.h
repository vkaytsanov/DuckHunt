//
// Created by Viktor on 17.1.2021 г..
//

#ifndef SCRIPT_H
#define SCRIPT_H

#include "../../../include/game_utils.h"

class Script {
public:
	virtual bool update(Gamelib& game) = 0;
};


#endif //SCRIPT_H
