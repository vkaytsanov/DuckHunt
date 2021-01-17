//
// Created by Viktor on 17.1.2021 г..
//

#include "include/dog_data.h"

Dog& DogData::getDog() {
	return dog;
}

void DogData::setDog(const Dog& dog) {
	this->dog = dog;
}
