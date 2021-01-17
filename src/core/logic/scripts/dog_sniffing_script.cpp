//
// Created by Viktor on 17.1.2021 г..
//

#include "include/dog_sniffing_script.h"
#include "../../../lib/include/lib.h"

DogSniffingScript::DogSniffingScript(Gamelib& game) {
	Dog& dog = game.dataSystem->dogData.getDog();
	dog.setVisible(true);
	dog.setDX(1.0f);
	dog.setState(Sniffing);

}

// Keep scripts in the CurrentGameData class?
bool DogSniffingScript::update(Gamelib& game) {
	currentSniffTime += Lib::graphics->getDeltaTime();
	if(currentSniffTime > SNIFF_TIME){
		Dog& dog = game.dataSystem->dogData.getDog();
		if(!stoppedSniffing) {
			stoppedSniffing = true;
			dog.setState(Jumping);
			dog.setDX(0);
		}
		else{
			dog.setDY(1.0f);
		}
	}
	return false;
}

