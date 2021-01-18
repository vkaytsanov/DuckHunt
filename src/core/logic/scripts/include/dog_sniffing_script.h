//
// Created by Viktor on 17.1.2021 г..
//

#ifndef DOG_SNIFFING_SCRIPT_H
#define DOG_SNIFFING_SCRIPT_H


#include "script.h"

class DogSniffingScript : public Script{
private:
	const float SNIFF_TIME = 5.3f;
	float currentSniffTime = 0.0f;
public:
	explicit DogSniffingScript(Gamelib& game);
	bool update(Gamelib& game) override;
};


#endif //DOG_SNIFFING_SCRIPT_H
