//
// Created by Viktor on 15.1.2021 г..
//

#include "include/ducks_db.h"

DucksDB::DucksDB() {
	ducks.reserve(NUMBER_OF_DUCKS);
}

void DucksDB::addDuck(const Duck& duck) {
	ducks.push_back(duck);
}

std::vector<Duck>& DucksDB::getDucks() {
	return ducks;
}
