cmake_minimum_required(VERSION 3.29)
project(problem10)

set(CMAKE_CXX_STANDARD 17)

add_executable(problem10 main.cpp
        Matrix.cpp
        Matrix.h
        IItem.cpp
        IItem.h
        Item.cpp
        Item.h
        Int.cpp
        Int.h)
