#pragma once
#include "IWindow.h"
#include <memory>

class Decorator : public IWindow {
protected:
    std::unique_ptr<IWindow> _window;
public:
    explicit Decorator(std::unique_ptr<IWindow> window);
    void draw() const override;
};