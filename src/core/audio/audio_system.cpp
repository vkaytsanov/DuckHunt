//
// Created by Viktor on 18.1.2021 г..
//

#include "include/audio_system.h"
#include "cassert"
#include "../../lib/include/lib.h"

// disabling the audio during development because it gets annoying
#define AUDIO 1

AudioSystem::AudioSystem() {
	const std::string musicNames[] = {
			"title.mp3",
			"intro.mp3",
			"perfect.wav",
			"round_clear.wav",
			"game_over.wav",
			"flapping.wav",
	};

	const std::string soundNames[] = {
			"got_ducks.wav",
			"miss.wav",
			"gunshot.wav",
			"falling.wav",
			"lands.wav",
			"bark.wav",
			"quack.wav"
	};

	sounds.reserve(6);
	for(const std::string& loc : soundNames){
		sounds.emplace_back(new Sound(AUDIO_LOCATION + loc));
	}
	musics.reserve(7);
	for(const std::string& loc : musicNames){
		musics.emplace_back(new Music(AUDIO_LOCATION + loc));
	}
}

void AudioSystem::playSound(const SoundType type, const bool loop) {
#if AUDIO
	sounds[type]->play(-1, loop);
#endif
}

void AudioSystem::playMusic(const MusicType type, const bool loop) {
#if AUDIO
	musics[type]->play(loop);
#endif
}

void AudioSystem::stopSound(const SoundType type) {
	sounds[type]->stop(-1);
}

void AudioSystem::stopMusic() {
	Lib::audio->stopMusic();
}

AudioSystem::~AudioSystem() {
	for(auto & sound : sounds){
		delete sound;
	}
	for(auto & music : musics){
		delete music;
	}
}


