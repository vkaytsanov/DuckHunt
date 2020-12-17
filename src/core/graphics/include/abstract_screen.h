//
// Created by Viktor on 17.12.2020 г..
//

#ifndef DUCKHUNT_ABSTRACT_SCREEN_H
#define DUCKHUNT_ABSTRACT_SCREEN_H


class AbstractScreen {
public:
    AbstractScreen() = default;
    virtual ~AbstractScreen() = default;
    virtual void render(const float& dt) = 0;

};


#endif //DUCKHUNT_ABSTRACT_SCREEN_H
