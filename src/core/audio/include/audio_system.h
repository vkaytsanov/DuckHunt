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
	INTRO,
	PERFECT_END,
	ROUND_CLEAR_END,
	GAME_OVER_END,
	FLAPPING,
};

enum SoundType{
	GOT_DUCKS,
	MISS,
	GUNSHOT,
	FALLING,
	LANDS,
	BARKS,
	QUACK
};



class AudioSystem {
private:
	std::vector<Sound*> sounds;
	std::vector<Music*> musics;
public:
	AudioSystem();
	~AudioSystem();
	void playSound(SoundType type, bool loop = false);
	void stopSound(SoundType type);
	void playMusic(MusicType type, bool loop = false);
	void stopMusic();
};


#endif //AUDIO_SYSTEM_H
