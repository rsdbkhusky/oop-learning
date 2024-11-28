cmake_minimum_required(VERSION 3.29)
project(problem11)

set(CMAKE_CXX_STANDARD 17)

add_executable(problem11 main.cpp
        Employee.cpp
        Employee.h
        Stuff.cpp
        Stuff.h
        Manager.cpp
        Manager.h
        Department.cpp
        Department.h)
