#ifndef DATASTRUCTURES_CPP_QUEUE_H
#define DATASTRUCTURES_CPP_QUEUE_H

#include "Node.h"

namespace list {

    class Queue {
    private:
        Node* first;
        Node* last;
    public:
        Queue();
        ~Queue();
        bool isEmpty();
        Node* dequeue();
        void enqueue(Node* newNode);
    };

}
#endif //DATASTRUCTURES_CPP_QUEUE_H
