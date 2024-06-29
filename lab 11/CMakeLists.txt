# CMake minimum version required
cmake_minimum_required(VERSION 3.16)
# the name of the project
project(sort)
# C++ minimum version required
# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 14)
# add an executable target
add_executable(sort_main sort.cpp)#
