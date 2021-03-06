//
// Created by Viktor on 17.12.2020 г..
//
#ifndef DUCKHUNT_GRAPHICS_SYSTEM_H
#define DUCKHUNT_GRAPHICS_SYSTEM_H


#include <unordered_map>
#include "../screens/include/menu_screen.h"
#include "../screens/include/abstract_screen.h"
#include "../../../lib/utils/include/universal_viewport.h"
#include "fonts.h"

extern int GRAPHICS_WIDTH;
extern int GRAPHICS_HEIGHT;
extern float WORLD_WIDTH;
extern float WORLD_HEIGHT;


class Gamelib;
class HudRenderer;

class GraphicsSystem {
private:
    UniversalViewport viewport;
    AbstractScreen* screens[3];
    Fonts* fonts;
    Gamelib* game;
public:
    explicit GraphicsSystem(Gamelib* game);
    ~GraphicsSystem();
    void render(const float dt);
    void resizeViewport(const int width, const int height);
    void start(int state);
    HudRenderer& getHudRenderer();
    AbstractScreen* getScreen(int state);
};


#endif //DUCKHUNT_GRAPHICS_SYSTEM_H
