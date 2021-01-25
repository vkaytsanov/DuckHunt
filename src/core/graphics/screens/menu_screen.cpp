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
    pointer = game.dataSystem->assets.getSprite("pointer");

	auto* greenStyle = new LabelStyle("pixel-emulator.ttf", 24);
	greenStyle->color = {0x15, 0xcb, 0x0b, 0xff};
    LabelStyle style("pixel-emulator.ttf", {0xff, 0xa2, 0x38}, 20);
    std::string gameModes[2] = {"GAME A   1 DUCK",
                                "GAME B   2 DUCKS"};

    for(int i = 0; i < 2; i++) {
        playLabel[i].setText(gameModes[i]);
        playLabel[i].setStyle(&style);
        const float width = (float) GRAPHICS_WIDTH * 0.6f + 40.f * (float) i;
        const float height = 50.f;
        playLabel[i].setSize(width, height);
        playLabel[i].setPosition((float) GRAPHICS_WIDTH * 0.2f, (float) GRAPHICS_WIDTH * 0.3f + height * (float) i);
	    playLabel[i].addListener(
			    new ClickListener([&, i]{
				    Lib::input->setProcessor(nullptr);
				    game.logicSystem->post(new StartRound(i == 0 ? ONE_DUCK : TWO_DUCKS));
			    })
	    );
        userInterface.addActor(&playLabel[i]);
    }

    maximumScore.setText("TOP SCORE = " + std::to_string(game.dataSystem->userData.getHighScore()));
    maximumScore.setStyle(greenStyle);
    maximumScore.setSize((float) GRAPHICS_WIDTH * 0.6f, 50);
    maximumScore.setPosition((float) GRAPHICS_WIDTH * 0.2f, (float) GRAPHICS_WIDTH * 0.3f + 150);

    copyright.setText("©2021 NINTENDO RIPOFF");
    style.color = {0xff, 0xff, 0xff, 0xff};
	copyright.setStyle(&style);
	copyright.setSize((float) GRAPHICS_WIDTH * 0.6f, 50);
	copyright.setPosition((float) GRAPHICS_WIDTH * 0.2f, (float) GRAPHICS_WIDTH * 0.3f + 220);

	userInterface.addActor(&maximumScore);
	userInterface.addActor(&copyright);

	auto* inputListener = new InputListener();
	inputListener->keyDown = [&](const int key){
		if(key == SDLK_UP || key == SDLK_w) {
			currentlySelected = std::abs((currentlySelected - 1) % 2);
		}
		else if(key == SDLK_DOWN || key == SDLK_s) {
			currentlySelected = (currentlySelected + 1) % 2;
		}
		// 13 is for Enter
		else if(key == 13){
			Lib::input->setProcessor(nullptr);
			game.logicSystem->post(new StartRound(currentlySelected == 0 ? ONE_DUCK : TWO_DUCKS));
		}
	};

	userInterface.addListener(inputListener);

    Lib::input->setProcessor(&userInterface);
}


void MenuScreen::render(const float& dt) {
    SDL_SetRenderDrawColor(Lib::graphics->getRenderer(), 0, 0, 0, 255);
    SDL_RenderClear(Lib::graphics->getRenderer());

    logo->draw((int)((float)GRAPHICS_WIDTH * 0.25f) ,-100, (int)((float)GRAPHICS_WIDTH * 0.5f), (int)((float)GRAPHICS_WIDTH * 0.5f));
	pointer->draw((int) playLabel[currentlySelected].getX() - 80, (int) playLabel[currentlySelected].getY() + 13, 40, 30);

    userInterface.act(dt);
    userInterface.draw();
}


