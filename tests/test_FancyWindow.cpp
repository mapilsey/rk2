#include "windows/FancyWindow.h"  // Исправленный путь
#include <gtest/gtest.h>

TEST(FancyWindowTest, DrawTest) {
    FancyWindow window;
    window.draw();
    SUCCEED();
}
