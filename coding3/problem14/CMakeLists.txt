cmake_minimum_required(VERSION 3.29)
project(problem14)

set(CMAKE_CXX_STANDARD 17)

add_executable(problem14 main.cpp
        Copier.cpp
        Copier.h
        Reader.cpp
        Reader.h
        ReaderKeyboard.cpp
        ReaderKeyboard.h
        Writer.cpp
        Writer.h
        WriterPrinter.cpp
        WriterPrinter.h)
