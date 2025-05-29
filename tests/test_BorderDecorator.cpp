#include "core/Window.h"  // Исправленный путь
#include "decorators/BorderDecorator.h"  // Исправленный путь
#include <gtest/gtest.h>
#include <memory>

TEST(BorderDecoratorTest, DrawTest) {
    std::unique_ptr<IWindow> window = std::make_unique<Window>();
    std::unique_ptr<IWindow> bordered_window = std::make_unique<BorderDecorator>(std::move(window));
    bordered_window->draw();
    SUCCEED();
}
