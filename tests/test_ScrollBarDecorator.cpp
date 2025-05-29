#include "Window.h"
#include "ScrollBarDecorator.h"
#include <memory>

int main() {
    std::unique_ptr<IWindow> window = std::make_unique<Window>();
    std::unique_ptr<IWindow> scroll_window = std::make_unique<ScrollBarDecorator>(std::move(window));
    scroll_window->draw();
    return 0;
}