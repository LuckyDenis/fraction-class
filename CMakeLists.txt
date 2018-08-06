cmake_minimum_required(VERSION 3.10)
project(fraction_class)

set(CMAKE_CXX_STANDARD 11)

add_executable(fraction_class main.cpp fraction/fraction.h fraction/fraction.cpp)