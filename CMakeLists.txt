cmake_minimum_required(VERSION 3.25)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled main.cpp
        graph.h
        prim.h
        priorityQueue.h
        binomial_heap.h
        fibonacci_heap.h
)
