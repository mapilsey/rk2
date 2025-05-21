#pragma once

struct IWindow {
    virtual void draw() const = 0;
    virtual ~IWindow() = default;
};