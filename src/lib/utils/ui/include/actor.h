//
// Created by Viktor on 12.1.2021 г..
//

#ifndef ACTOR_H
#define ACTOR_H


#include <vector>
#include "event_listener.h"

class Actor {
protected:
    std::vector<EventListener> listeners;
    int ID;
    float x;
    float y;
    float width;
    float height;
    bool visible = true;
public:
    Actor() = default;
    explicit Actor(int ID);
    const std::vector<EventListener> &getListeners() const;
    float getX() const;
    float getY() const;
    float getWidth() const;
    float getHeight() const;
    void setX(float x);
    void setY(float y);
    void act(float dt);

    virtual void draw(){}
    int getId() const;
    void setListeners(const std::vector<EventListener> &listeners);
    void addListener(const EventListener& e);
    void setId(int id);
    void setWidth(float width);
    void setHeight(float height);
    bool isVisible() const;
    void setVisible(bool visible);
    bool isInMouseBounds(const float& mouseX, const float& mouseY);
};


#endif //ACTOR_H
