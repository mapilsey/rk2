find_package(GTest REQUIRED)
include(GoogleTest)

# Добавляем корневую директорию исходников для всех тестов
include_directories(${CMAKE_SOURCE_DIR}/src)

# Тест для Window
add_executable(test_Window test_Window.cpp)
target_link_libraries(test_Window
    Window
    GTest::gtest_main
)
gtest_discover_tests(test_Window)

# Тест для FancyWindow
add_executable(test_FancyWindow test_FancyWindow.cpp)
target_link_libraries(test_FancyWindow
    FancyWindow
    Window  # Добавляем зависимость
    GTest::gtest_main
)
gtest_discover_tests(test_FancyWindow)

# Тест для BorderDecorator
add_executable(test_BorderDecorator test_BorderDecorator.cpp)
target_link_libraries(test_BorderDecorator
    Window
    BorderDecorator
    Decorator
    GTest::gtest_main
)
gtest_discover_tests(test_BorderDecorator)

# Тест для ScrollBarDecorator
add_executable(test_ScrollBarDecorator test_ScrollBarDecorator.cpp)
target_link_libraries(test_ScrollBarDecorator
    Window
    ScrollBarDecorator
    Decorator
    GTest::gtest_main
)
gtest_discover_tests(test_ScrollBarDecorator)
