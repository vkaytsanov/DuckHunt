#include <iostream>
#include "logger.h"

#define RESETTEXT  "\x1B[0m" // Set all colors back to normal.
#define FORERED  "\x1B[31m" // Red

#define RED(x) FORERED


void Logger::log(const char* tag, const char* message) {
	std::cout << "[" << tag << "] " << message << std::endl;
}

void Logger::debug(const char* tag, const char* message) {
	std::cout << "[" << tag << "] " << message << std::endl;
}

void Logger::error(const char* tag, const char* message) {
	std::cout << RED("[") << RED(tag)<< RED("] ") << RED(message) << std::endl;
	std::cout << RESETTEXT;
}
