//
// Created by Viktor on 18.1.2021 г..
//

#include "include/audio_system.h"
#include "cassert"
#include "../../lib/include/lib.h"

#define AUDIO 0

AudioSystem::AudioSystem() {
	std::string musicNames[] = {
			"title.mp3",
			"intro.mp3",
			"flapping.wav",
	};

	std::string soundNames[] = {
			"got_ducks.wav",
			"miss.wav",
			"gunshot.wav",
			"falling.wav",
			"lands.wav",
			"bark.wav",
			"quack.wav"
	};


	for(std::string& loc : soundNames){
		sounds.emplace_back(new Sound(AUDIO_LOCATION + loc));
	}

	for(std::string& loc : musicNames){
		musics.emplace_back(new Music(AUDIO_LOCATION + loc));
	}
}

void AudioSystem::playSound(SoundType type, bool loop) {
#if AUDIO
	sounds[type]->play(-1, loop);
#endif
}

void AudioSystem::playMusic(MusicType type, bool loop) {
#if AUDIO
	musics[type]->play(loop);
#endif
}

void AudioSystem::stopSound(SoundType type) {
	sounds[type]->stop(-1);
}

void AudioSystem::stopMusic() {
	Lib::audio->stopMusic();
}

AudioSystem::~AudioSystem() {
	for(Sound* sound : sounds){
		sound->stop();
		delete sound;
	}
	// TODO Unable to delete the initialized music
	Lib::audio->stopMusic();
//	for(Music* music : musics){
//		Lib::app->log("Music", "deleting music");
//		delete music;
//	}
}


