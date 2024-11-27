cmake_minimum_required(VERSION 3.29)
project(problem9)

set(CMAKE_CXX_STANDARD 17)

add_executable(problem9 main.cpp
        Monster.cpp
        Monster.h
        Cat.cpp
        Cat.h
        Dog.cpp
        Dog.h)
