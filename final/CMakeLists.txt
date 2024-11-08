cmake_minimum_required(VERSION 3.29)
project(final)

set(CMAKE_CXX_STANDARD 14)

add_executable(final main.cpp
        src/Cell.cpp
        include/Cell.h
        src/Row.cpp
        include/Row.h
        src/Column.cpp
        include/Column.h
        src/Block.cpp
        include/Block.h
        src/Sudoku.cpp
        include/Sudoku.h
        src/Application.cpp
        include/Application.h
        src/Scene.cpp
        include/Scene.h)
