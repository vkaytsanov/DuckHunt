//
// Created by Viktor on 15.1.2021 г..
//

#ifndef ANIMATION_H
#define ANIMATION_H


#include <vector>
#include "texture_region.h"
#include <cmath>
#include <algorithm>

template<typename T>
class Animation {
private:
	std::vector<T> frames;
	float frameDuration;
	float animationDuration;

public:
	Animation() = default;

	void loadFrames(const float frameDuration, const std::vector<T>& frames) {
		this->frameDuration = frameDuration;
		this->frames = frames;

		animationDuration = frameDuration * frames.size();
	}

	T getFrame(float stateTime, bool looping) const {
		int frameNumber = (int)(stateTime / frameDuration);
		if(looping){
			frameNumber = frameNumber % frames.size();
		}
		else{
			frameNumber = frames.size() - 1 > frameNumber ? frameNumber : frames.size() - 1;
		}
		const int idx = frameNumber;

		return frames[idx];
	}

};


#endif //ANIMATION_H
