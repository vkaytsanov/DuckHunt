//
// Created by Viktor on 15.1.2021 г..
//

#ifndef RED_DUCK_H
#define RED_DUCK_H

#include "duck.h"


class RedDuck : public Duck{
public:
	RedDuck();
	void loadEntity(Assets& assets) override;

};


#endif //RED_DUCK_H
