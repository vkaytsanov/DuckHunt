//
// Created by Viktor on 18.1.2021 г..
//

#include "include/music.h"

Music::Music(const std::string& file_path) {
	rawMusic = Mix_LoadMUS(file_path.c_str());
	if (rawMusic == nullptr) {
		printf("Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError());
	}
}

void Music::loadMusic(const std::string& file_path) {
	rawMusic = Mix_LoadMUS(file_path.c_str());
	if (rawMusic == nullptr) {
		printf("Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError());
	}
}

void Music::play() {
	Mix_PlayMusic(rawMusic, 0);
}

Music::~Music() {
	Mix_FreeMusic(rawMusic);
}
