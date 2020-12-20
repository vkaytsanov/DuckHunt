
#ifndef DUCKHUNT_GAME
#define DUCKHUNT_GAME

#include "../../lib/include/listener.h"
#include "../graphics/include/graphics_system.h"
#include "../logic/include/logic_system.h"
#include "../lib/include/application.h"
#include "game_utils.h"


class DuckHunt : public Listener, public Gamelib {
public:
    LogicSystem* logicSystem;
    GraphicsSystem* graphicsSystem;
    DuckHunt() = default;
    ~DuckHunt() override;
	// Inherited via Listener
	void create() override;
	void render() override;
};

#endif