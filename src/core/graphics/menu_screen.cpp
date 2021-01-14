//
// Created by Viktor on 17.12.2020 г..
//

#include "include/menu_screen.h"
#include "include/graphics_system.h"
#include "../../lib/include/lib.h"
#include "../../lib/utils/ui/include/click_listener.h"


MenuScreen::MenuScreen(Gamelib& game) : game(game), playLabel(){
    logo = game.dataSystem->assets.getSprite("logo");
    LabelStyle style("arial.ttf", 20);
    std::string gameModes[2] = {"GAME A      1 DUCK",
                                "GAME B      2 DUCKS"};


    playLabel->addListener(
            new ClickListener([&]{
                Lib::app->log("Lambda", "I'm in lambda");
                game.gameStateManager->changeState(Playing);
            })
    );
    for(int i = 0; i < 2; i++) {
        playLabel[i].setText(gameModes[i]);
        style.color = {0xCC, 0x55, 0x00};
        playLabel[i].setStyle(style);
        playLabel[i].setX((float) GRAPHICS_WIDTH * 0.2f);
        playLabel[i].setY((float) GRAPHICS_WIDTH * 0.4f + 60 * i);
        playLabel[i].setWidth((float) GRAPHICS_WIDTH * 0.6f + 40 * i);
        playLabel[i].setHeight((float) 60);

        userInterface.addActor(&playLabel[i]);
    }

    userInterface.debug = true;
    Lib::input->setProcessor(&userInterface);
}


void MenuScreen::render(const float& dt) {
    SDL_SetRenderDrawColor(Lib::graphics->getRenderer(), 0, 0, 0, 255);
    SDL_RenderClear(Lib::graphics->getRenderer());

    logo->draw(GRAPHICS_WIDTH * 0.2f,-100, GRAPHICS_WIDTH * 0.6f, GRAPHICS_WIDTH * 0.6f);

    userInterface.act(dt);
    userInterface.draw();
}


