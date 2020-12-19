//
// Created by Viktor on 18.12.2020 г..
//

#include <stdexcept>
#include "include/mod_assets.h"
#include "../../utils/include/lib.h"


Mod_Assets::Mod_Assets() {
    // TODO make it use not absolute paths, but project path
    std::string sprites_names[] = {
            "C:/Users/vikto/CLionProjects/DuckHunt/src/assets/sprites/logo.png"
    };
    // TODO get the sprites here
    int c = 0;
    for (std::string& sprite : sprites_names) {
        mapped_sprites[stripName(sprite)] = new Texture(sprite);
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
    for(int i = name.length(); i >= 0; i--){
        if(name[i] == '.'){
            const int endPos = i;
            for(int j = i; j >= 0; j--){
                if(name[j - 1] == '/'){
                    return name.substr(j, endPos - j);
                }
            }
        }
    }
    return nullptr;
}

