//
// Created by Viktor on 17.12.2020 г..
//

#ifndef DUCKHUNT_MENU_SCREEN_H
#define DUCKHUNT_MENU_SCREEN_H

#include "abstract_screen.h"
#include "../../../../lib/utils/ui/include/label.h"
#include "../../../../lib/utils/include/texture.h"
#include "../../include/fonts.h"

class MenuScreen : public AbstractScreen{
private:
    Texture* logo;
    Texture* pointer;
	LabelStyle* greenLabelStyle;
    Label playLabel[2];
    Label copyright;
    int currentlySelected = 0;
public:
	Label maximumScore;
    explicit MenuScreen(Gamelib* game, Fonts* fonts);
    ~MenuScreen() override;
    void render(const float dt) override;
};


#endif //DUCKHUNT_MENU_SCREEN_H
