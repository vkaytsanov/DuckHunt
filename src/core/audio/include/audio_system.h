//
// Created by Viktor on 18.1.2021 г..
//

#ifndef AUDIO_SYSTEM_H
#define AUDIO_SYSTEM_H

#include <vector>
#include "../../lib/utils/include/sound.h"
#include "../../lib/utils/include/music.h"

static std::string AUDIO_LOCATION = __FILE__ "/../../../../assets/audio/";

enum MusicType{
	TITLE,
	INTRO
};

enum SoundType{
	GOT_DUCKS,
	GUNSHOT,
	FLAPPING,
	FALLING,
	LANDS,
	BARKS
};



class AudioSystem {
private:
	std::vector<Sound*> sounds;
	std::vector<Music*> musics;
public:
	int duckOneChannel = 0;
	int duckTwoChannel = 1;
	int dogChannel = 2;
	int shotChannel = 3;
//	Sound* channels[4] = {nullptr};
	AudioSystem();
	~AudioSystem();
	void playSound(SoundType type, int channel = -1, bool loop = false);
	void stopSound(SoundType type, int channel = -1);
	void playMusic(MusicType type);
	int getSoundChannel(SoundType type);
	int getFreeChannel();
	void setChannelUsed(int i, SoundType type);
	void setChannelFree(int i);

};


#endif //AUDIO_SYSTEM_H
