cmake_minimum_required(VERSION 3.13)
project(project)

set(CMAKE_CXX_STANDARD 14)

add_executable(project main.cpp Translator.cpp Translator.h Command.h openServerCommand.cpp openServerCommand.h connectCommand.cpp connectCommand.h varCommand.cpp varCommand.h)