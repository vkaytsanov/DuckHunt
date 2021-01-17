//
// Created by Viktor on 12.1.2021 г..
//

#ifndef LABEL_H
#define LABEL_H


#include <string>
#include "actor.h"
#include "label_style.h"

class Label : public Actor{
private:
    std::string m_text;
    const LabelStyle* m_style;
    SDL_Texture* m_texture;
public:
    Label() = default;
    Label(const std::string& text, const LabelStyle* style);
    Label(const LabelStyle* style);
    Label(const std::string& text);
    ~Label();
    const std::string &getText() const;
    void setText(const std::string &text);
    void setStyle(const LabelStyle* style);
    void updateText();
    void draw() override;
};


#endif //LABEL_H
