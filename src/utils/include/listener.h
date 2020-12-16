#pragma once
#include "application_interface.h"

/* Main class should extend this */
class Listener {
protected:
	ApplicationInterface* Lib;
public:
	virtual void create(ApplicationInterface* Lib) = 0;
	virtual void render() = 0;
	virtual void dispose() = 0;
};