//
// Created by Viktor on 18.12.2020 г..
//

#ifndef DUCKHUNT_MOD_ASSETS_H
#define DUCKHUNT_MOD_ASSETS_H

#include <unordered_map>
#include "SDL.h"
#include "SDL_image.h"


class Mod_Assets {
private:
    const char* sprites_location = "assets/sprites/";
    std::unordered_map<const char*, SDL_Texture*> mapped_sprites;
public:
    Mod_Assets();
    SDL_Texture* getSprite(const char* name);
};


#endif //DUCKHUNT_MOD_ASSETS_H
