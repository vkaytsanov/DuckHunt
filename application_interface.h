#pragma once
#include "graphics.h"
#include "input.h"

class ApplicationInterface {
public:
	Graphics* graphics;
	Input* input;
	virtual void log(const char* tag, const char* message) = 0;
	virtual void error(const char* tag, const char* message) = 0;
};