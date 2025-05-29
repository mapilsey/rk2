#include "Decorator.h"

Decorator::Decorator(std::unique_ptr<IWindow> window)
    : _window{std::move(window)} {}

void Decorator::draw() const {
    _window->draw();
}