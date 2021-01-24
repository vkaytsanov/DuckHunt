//
// Created by Viktor on 23.1.2021 г..
//

#include <cstdio>
#include "include/user_data.h"
#include "../../lib/include/lib.h"

int UserData::getHighScore() const {
	return highScore;
}

void UserData::setHighScore(const int highScore) {
	if(this->highScore < highScore) this->highScore = highScore;
}

void UserData::save() {
	FILE* saveFile;
	errno_t err = fopen_s(&saveFile, (SAVE_LOCATION + SAVE_FILE).c_str(), "w");
	if(err != 0){
		Lib::app->error("SaveFile", "Couldn't open save file for write");
		exit(err);
	}
	std::string buffer = ("H " + std::to_string(highScore));
	fwrite(buffer.c_str(), sizeof(char), sizeof (buffer.c_str()), saveFile);
	fclose(saveFile);
}

void UserData::load() {
	FILE* saveFile;
	errno_t err = fopen_s(&saveFile, (SAVE_LOCATION + SAVE_FILE).c_str(), "r");
	if(err != 0){
		Lib::app->error("SaveFile", "Couldn't open save file for read");
		exit(err);
	}

	while(true){
		char line[64];
		int res = fscanf_s(saveFile, "%s", &line, sizeof(line));
		if (res == EOF)
			break;
		if (strcmp(line, "H") == 0) {
			fscanf_s(saveFile, "%d", &highScore, sizeof(highScore));

		}

	}
	Lib::app->log("User HighScore Loaded", highScore);
	fclose(saveFile);
}
