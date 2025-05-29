#pragma once
#include "Decorator.h"

class ScrollBarDecorator : public Decorator {
public:
    explicit ScrollBarDecorator(std::unique_ptr<IWindow> window);
    void draw() const override;
};