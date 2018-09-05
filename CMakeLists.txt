cmake_minimum_required(VERSION 3.10)
project(STR_2017)

set(CMAKE_CXX_STANDARD 11)

include_directories(src)
include_directories($ENV{SFML_INCLUDE_PATH})
link_directories($ENV{SFML_LIB_PATH})

add_executable(STR_2017
        src/cameramanager.cpp
        include/cameramanager.h
        src/drawableobject.cpp
        include/drawableobject.h
        src/drawerobject.cpp
        include/drawerobject.h
        src/gameboard.cpp
        include/gameboard.h
        src/gameguitop.cpp
        include/gameguitop.h
        src/gamestate.cpp
        include/gamestate.h
        src/inputmanager.cpp
        include/inputmanager.h
        src/main.cpp
        src/robot.cpp
        include/robot.h
        src/stdafx.cpp
        include/stdafx.h
        src/tile.cpp
        include/tile.h
        src/spritemanager.cpp
        include/spritemanager.h)

target_link_libraries(STR_2017 sfml-graphics-d sfml-window-d sfml-system-d)