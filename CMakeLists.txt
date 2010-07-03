project(trees)
cmake_minimum_required(VERSION 2.6)
set(SRC main.cpp)
set(INC node.hpp stack.hpp tree.hpp)
add_executable(trees ${SRC} ${INC})

