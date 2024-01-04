#ifndef DATASTRUCTURES_CPP_ABSTRACTGRAPH_H
#define DATASTRUCTURES_CPP_ABSTRACTGRAPH_H


#include "../List/Graph/Edge.h"

class AbstractGraph {
protected:
    int vertexCount;
    virtual void depthFirstSearch(bool* visited, int fromNode) = 0;
    virtual void breadthFirstSearch(bool* visited, int startNode) = 0;
    virtual Edge* edgeList(int& edgeCount) = 0;
public:
    explicit AbstractGraph(int vertexCount);
};


#endif //DATASTRUCTURES_CPP_ABSTRACTGRAPH_H
