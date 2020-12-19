//
// Created by Viktor on 18.12.2020 г..
//

#include <iostream>
#include "include/mod_assets.h"
#include "../../utils/include/lib.h"


Mod_Assets::Mod_Assets() {
    // TODO make it use not absolute paths, but project path
    const char* sprites_names[] = {
            "C:/Users/vikto/CLionProjects/DuckHunt/src/assets/sprites/logo.png"
    };
    // TODO get the sprites here
    int c = 0;
    for (const char *&sprite : sprites_names) {
        SDL_Surface *surface = IMG_Load(sprite);
        if (surface) {
            // TODO init The graphics before the class
            mapped_sprites[sprite] = SDL_CreateTextureFromSurface(
                    Lib::graphics->getRenderer(),
                    surface
                    );
            SDL_FreeSurface(surface);
            std::cout << sprite << std::endl;
            c++;
        }
    }

    Lib::app->log("Sprites Loaded", c);

}

SDL_Texture *Mod_Assets::getSprite(const char *name) {
    return mapped_sprites[name];
}
