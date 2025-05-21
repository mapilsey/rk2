cmake_minimum_required(VERSION 3.10)
project(DecoratorPattern)

# Настройка стандарта C++
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Общие настройки для всех библиотек
set(COMMON_INCLUDES ${CMAKE_CURRENT_SOURCE_DIR})

# 1. Библиотека IWindow (интерфейс, заголовочный только)
add_library(IWindow INTERFACE)
target_include_directories(IWindow INTERFACE ${COMMON_INCLUDES})
target_sources(IWindow INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/IWindow.h)

# 2. Библиотека Window
add_library(Window STATIC Window.cpp Window.h)
target_link_libraries(Window PUBLIC IWindow)
target_include_directories(Window PUBLIC ${COMMON_INCLUDES})

# 3. Библиотека FancyWindow
add_library(FancyWindow STATIC FancyWindow.cpp FancyWindow.h)
target_link_libraries(FancyWindow PUBLIC Window)
target_include_directories(FancyWindow PUBLIC ${COMMON_INCLUDES})

# 4. Библиотека Decorator
add_library(Decorator STATIC Decorator.cpp Decorator.h)
target_link_libraries(Decorator PUBLIC IWindow)
target_include_directories(Decorator PUBLIC ${COMMON_INCLUDES})

# 5. Библиотека BorderDecorator
add_library(BorderDecorator STATIC BorderDecorator.cpp BorderDecorator.h)
target_link_libraries(BorderDecorator PUBLIC Decorator)
target_include_directories(BorderDecorator PUBLIC ${COMMON_INCLUDES})

# 6. Библиотека ScrollBarDecorator
add_library(ScrollBarDecorator STATIC ScrollBarDecorator.cpp ScrollBarDecorator.h)
target_link_libraries(ScrollBarDecorator PUBLIC Decorator)
target_include_directories(ScrollBarDecorator PUBLIC ${COMMON_INCLUDES})

# Исполняемый файл
add_executable(test_main main.cpp)
target_link_libraries(test_main
    Window
    FancyWindow
    Decorator
    BorderDecorator
    ScrollBarDecorator
)

# tests
add_executable(test_Window test_Window.cpp)
target_link_libraries(test_Window
    Window
)

add_executable(test_FancyWindow test_FancyWindow.cpp)
target_link_libraries(test_FancyWindow
    FancyWindow
)

add_executable(test_BorderDecorator test_BorderDecorator.cpp)
target_link_libraries(test_BorderDecorator
    Window
    BorderDecorator
)

add_executable(test_ScrollBarDecorator test_ScrollBarDecorator.cpp)
target_link_libraries(test_ScrollBarDecorator
    Window
    ScrollBarDecorator
)