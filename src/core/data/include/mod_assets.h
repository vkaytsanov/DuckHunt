//
// Created by Viktor on 18.12.2020 г..
//

#ifndef DUCKHUNT_MOD_ASSETS_H
#define DUCKHUNT_MOD_ASSETS_H

#include <unordered_map>
#include "SDL.h"
#include "SDL_image.h"
#include "../../../lib/utils/include/texture.h"

// TODO Don't know how to use project path
static std::string ASSETS_LOCATION = __FILE__ "/../../../../assets/sprites/";

class Mod_Assets {
private:
    std::unordered_map<std::string, Texture*> mapped_sprites;
    static std::string stripName(std::string& name);
public:
    Mod_Assets();
    ~Mod_Assets();
    Texture* getSprite(std::string name);
};


#endif //DUCKHUNT_MOD_ASSETS_H
