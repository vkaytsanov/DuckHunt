//
// Created by Viktor on 17.1.2021 г..
//

#ifndef EVENT_H
#define EVENT_H


#include <string>

enum EventType{
	Basic,
	ShotFiredType,
	StartRoundType

};

class Event {
public:
	EventType type;
	std::string name;
	Event() = default;
	explicit Event(std::string& name);
	Event(const std::string& name, const EventType type);
};


#endif //EVENT_H
