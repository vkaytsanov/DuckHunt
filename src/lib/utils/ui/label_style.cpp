//
// Created by Viktor on 12.1.2021 г..
//

#include "include/label_style.h"
#include "../../include/lib.h"

LabelStyle::LabelStyle(const std::string& name, const SDL_Color &color, int size) : color(color), size(size) {
    font = TTF_OpenFont((FONTS_LOCATION + name).c_str(), size);
    if(font == nullptr){
        Lib::app->error("LabelStyle", "Can't load font.");
        Lib::app->error("File path given", (FONTS_LOCATION + name).c_str());
        exit(-1);
    }
}

LabelStyle::LabelStyle(const std::string& name, int size) : LabelStyle(name, {255,255,255, 255}, size) {}

LabelStyle::LabelStyle(const std::string& name) : LabelStyle(name, 16) {}

LabelStyle::~LabelStyle() {
    if(font) {
        TTF_CloseFont(font);
        font = nullptr;
    }
}
