//
// Created by Viktor on 17.12.2020 г..
//

#include "include/abstract_screen.h"
#include "../../../lib/include/lib.h"


void AbstractScreen::start() {
	Lib::input->setProcessor(&userInterface);
}
