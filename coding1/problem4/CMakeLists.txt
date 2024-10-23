cmake_minimum_required(VERSION 3.29)
project(problem4)

set(CMAKE_CXX_STANDARD 14)

add_executable(problem4 main.cpp
        Singleton.h
        KeyChar.cpp
        KeyChar.h
        Input.cpp
        Input.h
        ProcessString.h)
