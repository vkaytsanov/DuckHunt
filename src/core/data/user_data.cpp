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
	this->highScore = highScore;

}

void UserData::save() {
	FILE* saveFile;
	errno_t err = fopen_s(&saveFile, (SAVE_LOCATION + SAVE_FILE).c_str(), "w");
	if(err != 0){
		Lib::app->error("SaveFile", "Couldn't open save file for write");
		exit(err);
	}
	std::string buffer = "H " + std::to_string(highScore);
	Lib::app->log("Buffer", buffer.c_str());

	fwrite(&buffer[0], 1, buffer.length(), saveFile);
	Lib::app->log("Buffer", "wrote");
	fclose(saveFile);
	Lib::app->log("Buffer","closed");
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

bool UserData::isBetterHighScore(const int highScore) {
	return this->highScore < highScore;
}
