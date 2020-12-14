#pragma once

class Logger {
public:
	void log(const char* tag, const char* message);
	void debug(const char* tag, const char* message);
	void error(const char* tag, const char* message);
};