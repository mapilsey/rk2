#pragma once
#include "Decorator.h"

class BorderDecorator : public Decorator {
public:
    explicit BorderDecorator(std::unique_ptr<IWindow> window);
    void draw() const override;
};