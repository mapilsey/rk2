#include "BorderDecorator.h"
#include <iostream>

BorderDecorator::BorderDecorator(std::unique_ptr<IWindow> window)
    : Decorator(std::move(window)) {}

void BorderDecorator::draw() const {
    Decorator::draw();
    std::cout << "\twith Border\n";
}