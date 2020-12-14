#include "configuration.h"

Configuration::Configuration() {}

Configuration::Configuration(const char* title){
	this->title = title;
}

Configuration::Configuration(const char* title, const int width, const int height){
	this->title = title;
	this->width = width;
	this->height = height;
}

Configuration::Configuration(const int width, const int height){
	this->title = "";
	this->width = width;
	this->height = height;
}



