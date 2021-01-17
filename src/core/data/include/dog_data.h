//
// Created by Viktor on 17.1.2021 г..
//

#ifndef DOG_DATA_H
#define DOG_DATA_H


#include "../../game_object/include/dog.h"

class DogData {
private:
	Dog dog;
public:
	Dog& getDog();
	void setDog(const Dog& dog);
};


#endif //DOG_DATA_H
