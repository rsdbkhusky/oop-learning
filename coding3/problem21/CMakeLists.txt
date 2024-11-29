cmake_minimum_required(VERSION 3.29)
project(problem21)

set(CMAKE_CXX_STANDARD 17)

add_executable(problem21 main.cpp
        Bank.cpp
        Bank.h
        Enterprise.cpp
        Enterprise.h
        CodeBlockB.cpp
        CodeBlockB.h)
