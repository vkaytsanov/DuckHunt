//
// Created by Viktor on 17.12.2020 г..
//

#ifndef DUCKHUNT_MENU_SCREEN_H
#define DUCKHUNT_MENU_SCREEN_H

#include "abstract_screen.h"
#include "../../../../lib/utils/ui/include/label.h"

class MenuScreen : public AbstractScreen{
private:
    Texture* logo;
    Label playLabel[2];
    Label maximumScore;
    Label copyright;
    Gamelib& game;
public:
    explicit MenuScreen(Gamelib& game);
    void render(const float& dt) override;
};


#endif //DUCKHUNT_MENU_SCREEN_H
