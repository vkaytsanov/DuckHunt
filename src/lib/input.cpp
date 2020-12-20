#include "include/input.h"
#include <iostream>
#include <exception>

void Input::update() {
    // TODO need optimization here
    std::memcpy(lastFrameKeys, currFrameKeys, sizeof currFrameKeys);
    std::memset(currFrameKeys, false, sizeof currFrameKeys);
    while (SDL_PollEvent(&e) != 0) {
        //User requests quit
        if (e.type == SDL_QUIT) {
            quit = true;
        }
        //User presses a key
        else if (e.type == SDL_KEYDOWN) {
            try {
                if (e.key.keysym.sym > 122)
                    throw std::exception("key is not registered");
                currFrameKeys[e.key.keysym.sym] = true;
                std::cerr << e.key.keysym.sym << " is pressed\n";
            }
            catch (std::exception& e) {
                std::cout << e.what() << std::endl;
            }
        }
    }
}

bool Input::shouldQuit() const {
    return quit;
}

bool Input::isKeyPressed(const char key) {
    return currFrameKeys[key - '0'] || lastFrameKeys[key - '0'];
}

bool Input::isKeyJustPressed(const char key){
    return currFrameKeys[key - '0'];
}
