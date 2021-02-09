//
// Created by Viktor on 18.12.2020 г..
//

#ifndef DUCKHUNT_DATA_SYSTEM_H
#define DUCKHUNT_DATA_SYSTEM_H


#include "assets.h"
#include "ducks_db.h"
#include "dog_data.h"
#include "current_game_data.h"
#include "user_data.h"


class DataSystem {
public:
	Assets assets;
	DucksDB ducksDb;
	DogData dogData;
	CurrentGameData currentGameData;
	UserData userData;
	DataSystem();


};


#endif //DUCKHUNT_DATA_SYSTEM_H
