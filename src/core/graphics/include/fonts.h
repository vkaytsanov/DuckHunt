//
// Created by Viktor on 9.2.2021 г..
//

#ifndef FONTS_H
#define FONTS_H


#include <SDL_ttf.h>
#include <string>

// TODO Don't know how to use project path
static const std::string FONTS_LOCATION = __FILE__ "/../../../../assets/fonts/";

class Fonts {
private:
	TTF_Font* pixelEmulator;
public:
	Fonts();
	~Fonts();
	TTF_Font* getMainFont();
};



#endif //FONTS_H
