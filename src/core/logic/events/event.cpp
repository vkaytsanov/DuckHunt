//
// Created by Viktor on 17.1.2021 г..
//

#include "include/event.h"


Event::Event(std::string& name) {
	this->type = Basic;
	this->name = name;
}

Event::Event(const std::string& name, const EventType type) {
	this->name = name;
	this->type = type;
}
