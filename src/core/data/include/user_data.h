//
// Created by Viktor on 23.1.2021 г..
//

#ifndef USER_DATA_H
#define USER_DATA_H

#include <string>

const std::string SAVE_LOCATION = __FILE__ "/../../../../../";
const std::string SAVE_FILE = "save.txt";

class UserData {
private:
	int highScore = 0;
public:
	int getHighScore() const;
	void setHighScore(int highScore);
	bool isBetterHighScore(int highScore);
	void save();
	void load();
};


#endif //USER_DATA_H
