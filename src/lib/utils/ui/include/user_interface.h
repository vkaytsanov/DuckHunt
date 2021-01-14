//
// Created by Viktor on 12.1.2021 г..
//

#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H


#include <vector>
#include "actor.h"
#include "../../include/input_processor.h"

class UserInterface : public InputProcessor{
private:
    // TODO Use KD/BVH Tree
    // Using pointers so we can use runtime polymorphism
    std::vector<Actor*> actors;
public:
    ~UserInterface();
    bool debug;
    void addActor(Actor* actor);
    void act(float dt);
    void draw();
    void keyDown(SDL_Event &e, int key) override;
    void touchDown(SDL_Event &e, float x, float y) override;
    void touchUp(SDL_Event &e, float x, float y) override;
    void keyUp(SDL_Event &e, int key) override;
};


#endif //USER_INTERFACE_H
