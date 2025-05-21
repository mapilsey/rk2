#pragma once
#include "IWindow.h"

class Window : public IWindow {
public:
    void draw() const override;
};