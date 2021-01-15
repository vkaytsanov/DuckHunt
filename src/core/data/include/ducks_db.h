//
// Created by Viktor on 15.1.2021 г..
//

#ifndef DUCKS_DB_H
#define DUCKS_DB_H


#include <vector>
#include "../../game_object/include/duck.h"

static const int NUMBER_OF_DUCKS = 6;
class DucksDB {
private:
	std::vector<Duck> ducks;
public:
	DucksDB();
	void addDuck(const Duck& duck);
	std::vector<Duck>& getDucks();

};


#endif //DUCKS_DB_H
