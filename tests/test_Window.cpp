#include "core/Window.h"  // Исправленный путь
#include <gtest/gtest.h>

TEST(WindowTest, DrawTest) {
    Window window;
    window.draw();
    SUCCEED();
}
