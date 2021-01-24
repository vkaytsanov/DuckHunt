//
// Created by Viktor on 23.1.2021 г..
//

#include "include/window.h"

Window::Window(){

}

void Window::draw() {
	background->draw(getX(), getY(), getWidth(), getHeight());
}
