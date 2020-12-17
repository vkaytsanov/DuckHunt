#pragma once
#ifndef DUCKHUNT_GAME
#define DUCKHUNT_GAME

#include "../../utils/include/listener.h"
#include "game_state_manager.h"
#include "../graphics/include/graphics_system.h"
#include "../logic/include/logic_system.h"


class DuckHunt : public Listener {
public:
    LogicSystem logicSystem;
    GraphicsSystem graphicsSystem;
    GameStateManager gameStateManager;
    DuckHunt();
	// Inherited via Listener
	void create(ApplicationInterface* Lib) override;
	void render() override;
	void dispose() override;
};

#endif