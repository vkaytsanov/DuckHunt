//
// Created by Viktor on 23.1.2021 г..
//

#ifndef WINDOW_H
#define WINDOW_H

#include "../../../../lib/utils/include/texture.h"
#include "../../../../lib/utils/ui/include/actor.h"


class Window : public Actor{
protected:
	Texture* background;
public:
	explicit Window();
	void draw() override;
};


#endif //WINDOW_H
