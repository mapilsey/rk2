#include "Window.h"
#include "BorderDecorator.h"
#include <memory>

int main() {
    std::unique_ptr<IWindow> window = std::make_unique<Window>();
    std::unique_ptr<IWindow> bordered_window = std::make_unique<BorderDecorator>(std::move(window));
    bordered_window->draw();
    return 0;
}