//
// Created by Viktor on 15.1.2021 г..
//

#include "include/ducks_db.h"

DucksDB::DucksDB() {
	ducks.reserve(NUMBER_OF_DUCKS);
}

void DucksDB::addDuck(Duck* duck) {
	ducks.emplace_back(duck);
}

std::vector<Duck*>& DucksDB::getDucks() {
	return ducks;
}

DucksDB::~DucksDB() {
	for(auto & duck : ducks){
		delete duck;
	}
}

int DucksDB::getBlackDuckStartIndex() {
	return 0 * NUMBER_OF_DUCKS_PER_TYPE;
}

int DucksDB::getBlueDuckStartIndex() {
	return 1 * NUMBER_OF_DUCKS_PER_TYPE;
}

int DucksDB::getRedDuckStartIndex() {
	return 2 * NUMBER_OF_DUCKS_PER_TYPE ;
}
