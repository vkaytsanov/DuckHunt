//
// Created by Viktor on 17.12.2020 г..
//

#include "include/menu_screen.h"

#include "../../../lib/include/lib.h"
#include "../../include/game_utils.h"
#include "../../../lib/utils/ui/include/click_listener.h"
#include "../../logic/events/include/start_round.h"


MenuScreen::MenuScreen(Gamelib& game) :  playLabel(){
    logo = game.dataSystem->assets.getSprite("logo");
    LabelStyle style("pixel-emulator.ttf", 24);
    std::string gameModes[2] = {"GAME A   1 DUCK",
                                "GAME B   2 DUCKS"};

    for(int i = 0; i < 2; i++) {
        playLabel[i].setText(gameModes[i]);
        style.color = {0xCC, 0x55, 0x00};
        playLabel[i].setStyle(&style);
        const float width = (float) GRAPHICS_WIDTH * 0.6f + 40.f * (float) i;
        const float height = 50.f;
        playLabel[i].setWidth(width);
        playLabel[i].setHeight(height);
	    playLabel[i].setX((float) GRAPHICS_WIDTH * 0.2f);
	    playLabel[i].setY((float) GRAPHICS_WIDTH * 0.3f + height * (float) i);
	    playLabel[i].addListener(
			    new ClickListener([&, i]{
				    game.logicSystem->post(new StartRound(i == 0 ? ONE_DUCK : TWO_DUCKS));
			    })
	    );
        userInterface.addActor(&playLabel[i]);
    }

    maximumScore.setText("TOP SCORE = 12000");
    style.color = {0x15, 0xcb, 0x0b, 0xff};
    maximumScore.setStyle(&style);
    maximumScore.setWidth((float) GRAPHICS_WIDTH * 0.6f);
    maximumScore.setHeight(50);
    maximumScore.setX((float) GRAPHICS_WIDTH * 0.2f);
    maximumScore.setY((float) GRAPHICS_WIDTH * 0.3f + 150);

    copyright.setText("©2021 NINTENDO RIPOFF");
    style.color = {0xff, 0xff, 0xff, 0xff};
	copyright.setStyle(&style);
	copyright.setWidth((float) GRAPHICS_WIDTH * 0.6f);
	copyright.setHeight(50);
	copyright.setX((float) GRAPHICS_WIDTH * 0.2f);
	copyright.setY((float) GRAPHICS_WIDTH * 0.3f + 220);

	userInterface.addActor(&maximumScore);
	userInterface.addActor(&copyright);

    //userInterface.debug = true;
    Lib::input->setProcessor(&userInterface);
}


void MenuScreen::render(const float& dt) {
    SDL_SetRenderDrawColor(Lib::graphics->getRenderer(), 0, 0, 0, 255);
    SDL_RenderClear(Lib::graphics->getRenderer());

    logo->draw((int)((float)GRAPHICS_WIDTH * 0.25f) ,-100, (int)((float)GRAPHICS_WIDTH * 0.5f), (int)((float)GRAPHICS_WIDTH * 0.5f));

    userInterface.act(dt);
    userInterface.draw();
}


