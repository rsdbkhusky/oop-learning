cmake_minimum_required(VERSION 3.29)
project(problem17)

set(CMAKE_CXX_STANDARD 17)

add_executable(problem17 main.cpp
        CallBackObject.h
        Server.h
        Server.cpp
        ClientA.h
        ClientB.h)
