#include "Window.h"
#include "FancyWindow.h"
#include "BorderDecorator.h"
#include "ScrollBarDecorator.h"
#include <memory>

int main() {
    // decorate a basic Window
    std::unique_ptr<IWindow> decorated_window =
        std::make_unique<BorderDecorator>(std::make_unique<BorderDecorator>(
            std::make_unique<ScrollBarDecorator>(std::make_unique<Window>())));
    decorated_window->draw();

    // decorate a FancyWindow
    std::unique_ptr<IWindow> decorated_fancy_window =
        std::make_unique<BorderDecorator>(std::make_unique<BorderDecorator>(
            std::make_unique<ScrollBarDecorator>(
                std::make_unique<FancyWindow>())));
    decorated_fancy_window->draw();

    // a basically decorated window
    std::unique_ptr<IWindow> basic_decorated_window =
        std::make_unique<Decorator>(std::make_unique<Window>());
    basic_decorated_window->draw();

    return 0;
}