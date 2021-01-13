//
// Created by Viktor on 12.1.2021 г..
//

#include "include/label.h"
#include "../../include/lib.h"

Label::Label(const std::string &text) : Label(text, {}){}

Label::Label(const LabelStyle& style) : Label("", style){}

Label::Label(const std::string &text, const LabelStyle& style) {
    this->m_text = text;
    setStyle(style);
}

const std::string &Label::getText() const {
    return m_text;
}

void Label::setText(const std::string &text) {
    this->m_text = text;
}

void Label::draw() {
    SDL_Rect drawingRect{(int) x, (int) y, (int) width, (int) height};
    SDL_RenderCopy(Lib::graphics->getRenderer(), m_texture, nullptr, &drawingRect);
}

void Label::setStyle(const LabelStyle &style) {
    this->m_style = style;

    SDL_Surface* textSurface = TTF_RenderText_Blended(style.font, m_text.c_str(), style.color);
    m_texture = SDL_CreateTextureFromSurface(Lib::graphics->getRenderer(), textSurface);
    SDL_FreeSurface(textSurface);
}

Label::~Label() {
    SDL_DestroyTexture(m_texture);
}


