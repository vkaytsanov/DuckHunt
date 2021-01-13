//
// Created by Viktor on 12.1.2021 г..
//

#include <iostream>
#include "include/user_interface.h"
#include "../../include/lib.h"

void UserInterface::add(Actor& actor) {
    actor.setId(actors.size());
    actors.emplace_back(&actor);
}

void UserInterface::act(float dt) {
    // TODO
    if(Lib::input->isMouseLeftClick()) {
        Lib::app->log("UI", "Checking if hit something");
        for (Actor *actor : actors) {
            if (actor->isInMouseBounds(Lib::input->getCurrMousePosX(), Lib::input->getCurrMousePosY())) {
                Lib::app->log("UI", "Actor is clicked");
                if (actor->isVisible()) {
                    const std::vector<EventListener> &listeners = actor->getListeners();
                    for (const EventListener& listener : listeners) {
//                        Lib::app->log("UI", "Actor function updated");
                        listener.update();
                    }
                }
            }
        }
    }

    for(Actor* actor : actors){
        if(actor->isVisible()) actor->act(dt);
    }
}

void UserInterface::draw() {

    for(Actor* actor : actors){
        if(actor->isVisible()) actor->draw();
    }
    if(debug){
        SDL_SetRenderDrawColor(Lib::graphics->getRenderer(), 0xff, 0xff,0xff,0xff);
        for(Actor* actor : actors) {
            SDL_Rect rect = {(int)actor->getX(), (int)actor->getY(), (int)actor->getWidth(), (int)actor->getHeight()};
            SDL_RenderDrawRect(Lib::graphics->getRenderer(), &rect);

        }
    }
}
