cmake_minimum_required(VERSION 3.0)
project(snake)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_FLAGS "$ENV{CXXFLAGS} -O0 -ggdb -std=c++11 -Wall -Wno-deprecated -Werror -Wno-unused-function")

include_directories(.)
include_directories(../zcserver-log/src)
include_directories(../zoe/yaml-cpp/include)
include_directories(../zoe/boost_1_76_0)

find_library(zcserver zcserver ../zcserver-log/lib)

set(LIB
    sfml-audio
    sfml-graphics
    sfml-system
    sfml-window
    pthread
    ${zcserver}
    yaml-cpp
)

set(LIB_SRC
    src/Fruit.cpp
    src/Game.cpp
    src/GameOverScreen.cpp
    src/GameScreen.cpp
    src/MenuScreen.cpp
    src/Screen.cpp
    src/Snake.cpp
    src/SnakeNode.cpp
    src/Barrier.cpp
    src/Brick.cpp
    src/DifficultyScreen.cpp
    src/Button.cpp
)

add_library(snake ${LIB_SRC})

add_executable(game src/main.cpp)
add_dependencies(game snake)
target_link_libraries(game snake ${LIB})

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
