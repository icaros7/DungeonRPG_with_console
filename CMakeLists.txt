cmake_minimum_required(VERSION 3.20)
project(Dungeon)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(Dungeon
        include/Board.h
        include/Enemy.h
        include/Hero.h
        include/Sprite.h
        include/Trap.h
        include/Treasure.h
        source/Board.cpp
        source/Enemy.cpp
        source/Hero.cpp
        source/Sprite.cpp
        main.cpp)
