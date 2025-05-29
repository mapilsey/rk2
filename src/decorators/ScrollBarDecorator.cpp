#include "ScrollBarDecorator.h"
#include <iostream>

ScrollBarDecorator::ScrollBarDecorator(std::unique_ptr<IWindow> window)
    : Decorator(std::move(window)) {}

void ScrollBarDecorator::draw() const {
    Decorator::draw();
    std::cout << "\twith ScrollBar\n";
}