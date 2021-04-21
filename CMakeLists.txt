cmake_minimum_required(VERSION 3.17)
project(chess)

set(CMAKE_CXX_STANDARD 17)

add_executable(chess main.cpp Figure.cpp Figure.hpp)