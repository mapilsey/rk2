#include "core/Window.h"  // Исправленный путь
#include "decorators/ScrollBarDecorator.h"  // Исправленный путь
#include <gtest/gtest.h>
#include <memory>

TEST(ScrollBarDecoratorTest, DrawTest) {
    std::unique_ptr<IWindow> window = std::make_unique<Window>();
    std::unique_ptr<IWindow> scroll_window = std::make_unique<ScrollBarDecorator>(std::move(window));
    scroll_window->draw();
    SUCCEED();
}
