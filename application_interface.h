#pragma once
#include "graphics.h"

class ApplicationInterface {
public:
	virtual Graphics* getGraphics() = 0;
	virtual void log(const char* tag, const char* message) = 0;
	virtual void error(const char* tag, const char* message) = 0;
};