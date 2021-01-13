//
// Created by Viktor on 12.1.2021 г..
//

#ifndef EVENT_LISTENER_H
#define EVENT_LISTENER_H
#include <functional>

class EventListener {
public:
    std::function<void()> update;
};


#endif //EVENT_LISTENER_H
