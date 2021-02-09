//
// Created by Viktor on 9.2.2021 г..
//

#include "include/fonts.h"
#include "../../lib/include/lib.h"

Fonts::Fonts() {
	std::string pixelEmulatorPath = FONTS_LOCATION + "pixel-emulator.ttf";
	pixelEmulator = TTF_OpenFont((pixelEmulatorPath).c_str(), 20);

	if (pixelEmulator == nullptr) {
		Lib::app->error("LabelStyle", "Can't load font.");
		Lib::app->error("File path given", (pixelEmulatorPath).c_str());
		exit(-1);
	}
}

Fonts::~Fonts() {
	TTF_CloseFont(pixelEmulator);
	pixelEmulator = nullptr;
}

TTF_Font* Fonts::getMainFont() {
	return pixelEmulator;
}
