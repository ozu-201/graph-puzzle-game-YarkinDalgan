#include "Graph.h"
#include "../Queue.h"

namespace list {

    Graph::Graph(int _vertexCount) : AbstractGraph(_vertexCount){
        edges = new EdgeList[vertexCount];
        for (int i = 0; i < vertexCount; i++) {
            edges[i] = EdgeList();
        }
    }

    void Graph::addEdge(int from, int to) {
        Edge* edge = new Edge(from, to, 1);
        edges[from].insert(edge);
    }

    void Graph::addEdge(int from, int to, int weight) {
        Edge* edge = new Edge(from, to, weight);
        edges[from].insert(edge);
    }

    Graph::~Graph() {
        delete[] edges;
    }

    void Graph::depthFirstSearch(bool *visited, int fromNode) {
        Edge* edge;
        int toNode;
        edge = edges[fromNode].getHead();
        while (edge != nullptr){
            toNode = edge->getTo();
            if (!visited[toNode]){
                visited[toNode] = true;
                depthFirstSearch(visited, toNode);
            }
            edge = edge->getNext();
        }
    }

    void Graph::breadthFirstSearch(bool *visited, int startNode) {
        Edge* edge;
        int fromNode, toNode;
        Queue queue = Queue();
        queue.enqueue(new Node(startNode));
        while (!queue.isEmpty()){
            fromNode = queue.dequeue()->getData();
            edge = edges[fromNode].getHead();
            while (edge != nullptr) {
                toNode = edge->getTo();
                if (!visited[toNode]){
                    visited[toNode] = true;
                    queue.enqueue(new Node(toNode));
                }
                edge = edge->getNext();
            }
        }
    }

    Edge *Graph::edgeList(int& edgeCount) {
        Edge* list;
        edgeCount = 0;
        for (int i = 0; i < vertexCount; i++){
            Edge* edge = edges[i].getHead();
            while (edge != nullptr){
                edgeCount++;
                edge = edge->getNext();
            }
        }
        list = new Edge[edgeCount];
        int index = 0;
        for (int i = 0; i < vertexCount; i++){
            Edge* edge = edges[i].getHead();
            while (edge != nullptr){
                list[index] = Edge(edge->getFrom(), edge->getTo(), edge->getWeight());
                index++;
                edge = edge->getNext();
            }
        }
        return list;
    }


    void Graph::wordLadderBFS(const vector<string>& words, int startNodeIndex, int endNodeIndex) {
        int vertexCount = static_cast<int>(words.size());
        vector<bool> visited(vertexCount, false);
        list::Queue queue;

        queue.enqueue(new Node(startNodeIndex));
        visited[startNodeIndex] = true;
        vector<int> previous(vertexCount, -1);

        while (!queue.isEmpty()) {
            Node* currentNode = queue.dequeue();
            int currentNodeIndex = currentNode->getData();
            delete currentNode;

            //cout << currentNodeIndex << " " << words[currentNodeIndex] << endl;
            if (currentNodeIndex == endNodeIndex) {
                cout << "shortest path: " << endl;
                vector<int> shortestPath;
                int nodeIndex = endNodeIndex;
                while (nodeIndex != -1) {
                    shortestPath.push_back(nodeIndex);
                    nodeIndex = previous[nodeIndex];
                }

                vector<int> reversedVector(shortestPath.size());

                for (size_t i = 0; i < shortestPath.size(); ++i) {
                    reversedVector[i] = shortestPath[shortestPath.size() - 1 - i];
                }

                for (size_t i = 0; i < reversedVector.size(); ++i) {
                    if (i == reversedVector.size() - 1)
                        cout << words[reversedVector[i]];
                    else
                        cout << words[reversedVector[i]] << " -> ";
                }
                cout << endl;
                return;
            }

            Edge* edge = edges[currentNodeIndex].getHead();
            while (edge != nullptr) {
                int neighbor = edge->getTo();
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    queue.enqueue(new Node(neighbor));
                    previous[neighbor] = currentNodeIndex;
                }
                edge = edge->getNext();
            }
        }
        cout << "The target node could not be reached." << endl;
    }

}