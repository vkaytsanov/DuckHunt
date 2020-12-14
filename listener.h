#pragma once
#include "application_interface.h"

/* Main class should extend this */
class Listener {
protected:
	ApplicationInterface* app;
public:
	virtual void create(ApplicationInterface* app) = 0;
	virtual void render() = 0;
	virtual void dispose() = 0;
};