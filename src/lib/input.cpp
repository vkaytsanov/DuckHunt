#include "include/input.h"
#include <iostream>
#include <exception>
#include "include/lib.h"


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
        else if(e.type == SDL_WINDOWEVENT){
            switch(e.window.event){
                case SDL_WINDOWEVENT_SHOWN:
                    Lib::graphics->setBackground(false);
                    SDL_Log("Window %d shown", e.window.windowID);
                    break;
                case SDL_WINDOWEVENT_HIDDEN:
                    Lib::graphics->setBackground(true);
                    SDL_Log("Window %d hidden", e.window.windowID);
                    break;
                case SDL_WINDOWEVENT_RESIZED:
                    Lib::graphics->setWidth(e.window.data1);
                    Lib::graphics->setHeight(e.window.data2);
                    SDL_Log("Window %d resized to %dx%d",
                            e.window.windowID, e.window.data1,
                            e.window.data2);
                    break;
                case SDL_WINDOWEVENT_MINIMIZED:
                    Lib::graphics->setVisible(false);
                    SDL_Log("Window %d minimized", e.window.windowID);
                    break;
                case SDL_WINDOWEVENT_RESTORED:
                    Lib::graphics->setVisible(true);
                    SDL_Log("Window %d restored", e.window.windowID);
                    break;
//                case SDL_WINDOWEVENT_SIZE_CHANGED:
//                    Lib::graphics->setWidth(e.window.data1);
//                    Lib::graphics->setHeight(e.window.data2);
//                    SDL_Log("Window %d size changed to %dx%d",
//                            e.window.windowID, e.window.data1,
//                            e.window.data2);
//                    break;
//                case SDL_WINDOWEVENT_MAXIMIZED:
//                    SDL_Log("Window %d maximized", e.window.windowID);
//                    break;
//                case SDL_WINDOWEVENT_ENTER:
//                    SDL_Log("Mouse entered window %d",
//                            e.window.windowID);
//                    break;
//                case SDL_WINDOWEVENT_LEAVE:
//                    SDL_Log("Mouse left window %d", e.window.windowID);
//                    break;
//                case SDL_WINDOWEVENT_FOCUS_GAINED:
//                    SDL_Log("Window %d gained keyboard focus",
//                            e.window.windowID);
//                    break;
//                case SDL_WINDOWEVENT_FOCUS_LOST:
//                    SDL_Log("Window %d lost keyboard focus",
//                            e.window.windowID);
//                    break;
//                case SDL_WINDOWEVENT_CLOSE:
//                    SDL_Log("Window %d closed", e.window.windowID);
//                    break;
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
