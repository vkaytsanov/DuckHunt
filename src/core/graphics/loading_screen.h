//
// Created by Viktor on 17.12.2020 г..
//

#ifndef DUCKHUNT_LOADING_SCREEN_H
#define DUCKHUNT_LOADING_SCREEN_H


#include "include/abstract_screen.h"

class LoadingScreen : public AbstractScreen{
public:
    LoadingScreen();
    void render() override;
};


#endif //DUCKHUNT_LOADING_SCREEN_H
