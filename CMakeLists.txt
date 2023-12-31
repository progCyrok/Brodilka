cmake_minimum_required(VERSION 3.27)
project(opengl_game)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES launch.cpp
        my_keyboard.h)

add_executable(Start ${SOURCE_FILES})

set(SFML_DIR "/opt/homebrew/Cellar/sfml/2.6.1/include/SFML/")

find_package(OpenGL REQUIRED)
find_package(SFML 2.5 COMPONENTS graphics audio window system REQUIRED)

include_directories(${OPENGL_INCLUDE_DIRS} ${SFML_INCLUDE_DIRS})
include_directories(/opt/homebrew/Cellar/mesa/23.3.2/include)
link_directories(/opt/homebrew/Cellar/mesa/23.3.2/lib/ )


target_link_libraries(Start PRIVATE sfml-graphics sfml-audio ${OPENGL_gl_LIBRARY} ${OPENGL_LIBRARIES})

