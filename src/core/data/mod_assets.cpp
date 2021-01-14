//
// Created by Viktor on 18.12.2020 г..
//

#include <stdexcept>
#include "include/mod_assets.h"
#include "../../lib/include/lib.h"


Mod_Assets::Mod_Assets() {
    std::string spritePaths[] = {
            "logo.png",
            "dog.png",
            "bullet.png",
            "ducks.png",
            "ducks-ui.png",
            "fly-away.png",
            "playing-screen-background.png"
    };

    int c = 0;
    for (std::string& path : spritePaths) {
        mapped_sprites[stripName(path)] = new Texture(ASSETS_LOCATION + path);
        c++;
    }

    Lib::app->log("Sprites Loaded", c);

}

Texture *Mod_Assets::getSprite(const std::string name) {
    if(mapped_sprites.find(name) == mapped_sprites.end()){
        throw std::runtime_error("Sprite " + name + " doesn't exists");
    }
    return mapped_sprites[name];
}

Mod_Assets::~Mod_Assets() {
    for(const auto& it : mapped_sprites){
        delete it.second;
    }
}

std::string Mod_Assets::stripName(std::string& name) {
    return name.substr(0, name.find('.'));
}

