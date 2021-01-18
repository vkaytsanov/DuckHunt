//
// Created by Viktor on 18.1.2021 г..
//

#include "include/audio_system.h"
#include "cassert"

AudioSystem::AudioSystem() {
	std::string musicNames[] = {
			"01 - Title Screen.mp3",
			"02 - Duck Hunt Intro.mp3"
	};

	std::string soundNames[] = {
			"04 - Got Duck(s).mp3",
			"99 - Gunshot (SFX).mp3",
			"99 - Duck Flapping (SFX).mp3",
			"99 - Dead Duck Falls (SFX).mp3",
			"99 - Dead Duck Lands (SFX).mp3",
			"99 - Bark! (SFX).mp3"
	};


	for(std::string& loc : soundNames){
		sounds.emplace_back(new Sound(AUDIO_LOCATION + loc));
	}

	for(std::string& loc : musicNames){
		musics.emplace_back(new Music(AUDIO_LOCATION + loc));
	}

	assert(sizeof(soundNames)/sizeof(soundNames[0]) == 6);
}

void AudioSystem::playSound(SoundType type, int channel, bool loop) {
	sounds[type]->play(channel, loop);
}

void AudioSystem::playMusic(MusicType type) {
	musics[type]->play();
}

AudioSystem::~AudioSystem() {
	for(Sound* sound : sounds){
		delete sound;
	}
//	for(Music* music : musics){
//		delete music;
//	}
}

void AudioSystem::stopSound(SoundType type, int channel) {
	sounds[type]->stop(channel);
}

int AudioSystem::getSoundChannel(SoundType type) {
//	for(int i = 0; i < 4; i++){
//		if(channels[i] == sounds[type]){
//			return i;
//		}
//	}
//	return -1;
	return 0;
}

int AudioSystem::getFreeChannel() {
//	for(int i = 0; i < 4; i++){
//		if(!channels[i]){
//			return i;
//		}
//	}
//	return -1;
	return 0;
}

void AudioSystem::setChannelUsed(int i, SoundType type) {
	//channels[i] = sounds[type];
}

void AudioSystem::setChannelFree(int i) {
	//channels[i] = nullptr;
}
