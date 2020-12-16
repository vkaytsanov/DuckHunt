#pragma once
#include "utils/include/listener.h"

class DuckHunt : public Listener {
	// Inherited via Listener
	void create(ApplicationInterface* Lib) override;
	void render() override;
	void dispose() override;
};