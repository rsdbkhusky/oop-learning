cmake_minimum_required(VERSION 3.29)
project(problem12)

set(CMAKE_CXX_STANDARD 17)

add_executable(problem12 main.cpp
        Fish.cpp
        Fish.h
        Octopus.cpp
        Octopus.h
        Whale.cpp
        Whale.h
        Turtle.cpp
        Turtle.h
        Cat.cpp
        Cat.h
        Shark.cpp
        Shark.h)
