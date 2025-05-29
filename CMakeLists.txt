cmake_minimum_required(VERSION 3.15)
project(DecoratorPattern)

# Настройка стандарта C++
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Включаем тестирование
include(CTest)
enable_testing()

# Пути к исходным файлам
set(SRC_CORE 
    src/core/Window.cpp 
    src/core/Window.h 
    src/core/IWindow.h
)

set(SRC_WINDOWS 
    src/windows/FancyWindow.cpp 
    src/windows/FancyWindow.h
)

set(SRC_DECORATORS 
    src/decorators/Decorator.cpp 
    src/decorators/Decorator.h
    src/decorators/BorderDecorator.cpp 
    src/decorators/BorderDecorator.h
    src/decorators/ScrollBarDecorator.cpp 
    src/decorators/ScrollBarDecorator.h
)

# 1. Библиотека IWindow (интерфейс)
add_library(IWindow INTERFACE)
target_include_directories(IWindow INTERFACE
    src/core
)

# 2. Библиотека Window
add_library(Window STATIC ${SRC_CORE})
target_link_libraries(Window PUBLIC IWindow)
target_include_directories(Window PUBLIC
    src/core
)

# 3. Библиотека FancyWindow
add_library(FancyWindow STATIC ${SRC_WINDOWS})
target_link_libraries(FancyWindow PUBLIC Window)
target_include_directories(FancyWindow PUBLIC
    src/windows
    src/core
)

# 4. Библиотека Decorator
add_library(Decorator STATIC ${SRC_DECORATORS})
target_link_libraries(Decorator PUBLIC IWindow)
target_include_directories(Decorator PUBLIC
    src/decorators
    src/core
)

# 5. Библиотека BorderDecorator
add_library(BorderDecorator STATIC 
    src/decorators/BorderDecorator.cpp 
    src/decorators/BorderDecorator.h
)
target_link_libraries(BorderDecorator PUBLIC Decorator)
target_include_directories(BorderDecorator PUBLIC
    src/decorators
)

# 6. Библиотека ScrollBarDecorator
add_library(ScrollBarDecorator STATIC 
    src/decorators/ScrollBarDecorator.cpp 
    src/decorators/ScrollBarDecorator.h
)
target_link_libraries(ScrollBarDecorator PUBLIC Decorator)
target_include_directories(ScrollBarDecorator PUBLIC
    src/decorators
)

# Основное приложение
add_executable(decorator_app app/main.cpp)
target_link_libraries(decorator_app
    Window
    FancyWindow
    Decorator
    BorderDecorator
    ScrollBarDecorator
)

# Подключаем тесты
add_subdirectory(tests)
