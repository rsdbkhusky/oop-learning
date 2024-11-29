cmake_minimum_required(VERSION 3.29)
project(problem20)

set(CMAKE_CXX_STANDARD 17)

add_executable(problem20 main.cpp
        VideoPlayer.cpp
        VideoPlayer.h
        System.cpp
        System.h
        StandardVideoStream.cpp
        StandardVideoStream.h
        RMVB_Player.cpp
        RMVB_Player.h
        WinOS.cpp
        WinOS.h)
