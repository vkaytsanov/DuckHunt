//
// Created by Viktor on 15.1.2021 г..
//

#ifndef BLUE_DUCK_H
#define BLUE_DUCK_H

#include "duck.h"

class BlueDuck : public Duck{
public:
	BlueDuck();
	void loadEntity(Assets& assets) override;

};


#endif //BLUE_DUCK_H
