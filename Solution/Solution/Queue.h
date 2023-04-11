#ifndef QUEUE_H
#define QUEUE_H

struct Node {
    int data;
    Node* next;
};

class Queue {
private:
    Node* front;
    Node* rear;
    int size;

public:
    Queue();
    ~Queue();
    void enqueue(int x);
    int dequeue();
    int peek();
    bool isEmpty();
    int getSize();
};

#endif
