#pragma once
#include "listener.h"

class DuckHunt : public Listener {
	// Inherited via Listener
	virtual void create(ApplicationInterface* app) override;
	virtual void render() override;
	virtual void dispose() override;
};