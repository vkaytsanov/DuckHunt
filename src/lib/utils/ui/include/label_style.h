//
// Created by Viktor on 12.1.2021 г..
//

#ifndef LABEL_STYLE_H
#define LABEL_STYLE_H


#include <SDL_ttf.h>
#include <string>

// TODO Don't know how to use project path
static const std::string FONTS_LOCATION = __FILE__ "/../../../../../assets/fonts/";

class LabelStyle {
public:

    TTF_Font* font;
    SDL_Color color;
    SDL_Color backgroundColor = {255, 255, 255,255};
    int size;
    LabelStyle() = default;
    LabelStyle(const std::string& name, const SDL_Color &color, int size);
    LabelStyle(const std::string& name);
    LabelStyle(const std::string& name, int size);
    ~LabelStyle();
};


#endif //LABEL_STYLE_H
