#ifndef DATASTRUCTURES_CPP_GRAPH_H
#define DATASTRUCTURES_CPP_GRAPH_H


#include "EdgeList.h"
#include "../../General/AbstractGraph.h"
#include <vector>
#include <iostream>

namespace list {

    class Graph : public AbstractGraph{
    private:
        EdgeList *edges;
    public:
        explicit Graph(int vertexCount);
        ~Graph();
        void addEdge(int from, int to);
        void addEdge(int from, int to, int weight);
        void wordLadderBFS(const std::vector<std::string>& words, int startNodeIndex, int endNodeIndex);

    protected:
        void depthFirstSearch(bool* visited, int fromNode) override;
        void breadthFirstSearch(bool* visited, int startNode) override;
        Edge* edgeList(int& edgeCount) override;
    };

}
#endif //DATASTRUCTURES_CPP_GRAPH_H
