cmake_minimum_required(VERSION 3.23)
project(graph-puzzle-game-YarkinDalgan)

set(CMAKE_CXX_STANDARD 17)

add_library(graph-puzzle-game-YarkinDalgan src/General/AbstractGraph.h src/General/AbstractGraph.cpp src/List/Graph/Edge.h
        src/List/Graph/Edge.cpp src/List/Graph/EdgeList.h src/List/Graph/EdgeList.cpp src/List/Graph/Graph.h src/List/Graph/Graph.cpp
        src/List/Node.h src/List/Node.cpp src/List/Queue.h src/List/Queue.cpp)

add_executable(Main Main.cpp src/General/AbstractGraph.h src/General/AbstractGraph.cpp src/List/Graph/Edge.h
        src/List/Graph/Edge.cpp src/List/Graph/EdgeList.h src/List/Graph/EdgeList.cpp src/List/Graph/Graph.h src/List/Graph/Graph.cpp
        src/List/Node.h src/List/Node.cpp src/List/Queue.h src/List/Queue.cpp)
