//
// Created by Viktor on 15.1.2021 г..
//

#ifndef DUCKS_DB_H
#define DUCKS_DB_H


#include <vector>
#include "../../game_object/include/duck.h"

static const int NUMBER_OF_DUCKS = 6;
static const int NUMBER_OF_DUCKS_PER_TYPE = NUMBER_OF_DUCKS / 3;

class DucksDB {
private:
	std::vector<Duck*> ducks;
public:
	DucksDB();
	~DucksDB();
	void addDuck(Duck* duck);
	std::vector<Duck*>& getDucks();
	static int getBlackDuckStartIndex();
	static int getBlueDuckStartIndex();
	static int getRedDuckStartIndex();
	static int getBlackDuckEndIndex();
	static int getBlueDuckEndIndex();
	static int getRedDuckEndIndex();

};


#endif //DUCKS_DB_H
