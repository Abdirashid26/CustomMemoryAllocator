cmake_minimum_required(VERSION 3.30)
project(CustomMemoryAllocator)

set(CMAKE_CXX_STANDARD 20)

add_executable(CustomMemoryAllocator main.cpp
        include/CustomAllocator.h)
