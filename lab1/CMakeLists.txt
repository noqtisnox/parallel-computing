cmake_minimum_required(VERSION 4.1)
project(lab1)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab1 main.cpp
        include/gauss_consecutive.hpp
        include/gauss_parallel.hpp
        src/gauss_consecutive.cpp
        src/gauss_parallel.cpp
        include/matrix_utils.hpp
        src/matrix_utils.cpp)
