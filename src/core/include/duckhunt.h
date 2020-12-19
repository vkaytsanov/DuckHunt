
#ifndef DUCKHUNT_GAME
#define DUCKHUNT_GAME

#include "../../utils/include/listener.h"
#include "../graphics/include/graphics_system.h"
#include "../logic/include/logic_system.h"
#include "../utils/include/application.h"
#include "game_utils.h"


class DuckHunt : public Listener, public GameUtils {
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