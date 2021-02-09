
#ifndef DUCKHUNT_GAME
#define DUCKHUNT_GAME

#include "../../lib/include/listener.h"

#include "../lib/include/application.h"
#include "game_utils.h"


class DuckHunt : public Listener, public Gamelib {
public:
    DuckHunt() = default;
    ~DuckHunt() override;
	// Inherited via Listener
	void create() override;
	void render() override;
    void pause() override;
    void resume() override;
    void resize(const int width, const int height) override;
};



#endif