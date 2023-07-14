cmake_minimum_required(VERSION 3.24)
project(DA1)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(DA1
        src/main.cpp
        src/utils.cpp
        src/utils.h src/newGraph.cpp src/newGraph.h src/vertexEdge.cpp src/vertexEdge.h src/algorithms.cpp src/algorithms.h)
