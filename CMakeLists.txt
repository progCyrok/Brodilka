cmake_minimum_required(VERSION 3.27)
project(opengl_game)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp
        my_keyboard.h)

add_executable(your_executable_name ${SOURCE_FILES})

# Путь к библиотекам SFML
set(SFML_DIR "/opt/homebrew/Cellar/sfml/2.6.1/include/SFML/")

# Найти компоненты SFML
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

# Цель вашего проекта должна подключать используемые компоненты SFML
target_link_libraries(your_executable_name PRIVATE sfml-graphics sfml-audio)

