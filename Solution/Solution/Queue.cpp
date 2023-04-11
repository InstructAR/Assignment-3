#include "queue.h"
#include <iostream>

using namespace std;

// Constructor
Queue::Queue() {
    front = nullptr;
    rear = nullptr;
    size = 0;
}

// Destructor
Queue::~Queue() {
    while (!isEmpty()) {
        dequeue();
    }
}

// Function to insert a new element at the rear of the queue
void Queue::enqueue(int x) {
    Node* temp = new Node;
    temp->data = x;
    temp->next = nullptr;
    if (isEmpty()) {
        front = rear = temp;
    }
    else {
        rear->next = temp;
        rear = temp;
    }
    size++;
}

// Function to remove the front element of the queue and return it
int Queue::dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty." << endl;
        return -1;
    }
    int x = front->data;
    Node* temp = front;
    front = front->next;
    delete temp;
    size--;
    if (isEmpty()) {
        rear = nullptr;
    }
    return x;
}

// Function to return the front element present in the queue without removing it
int Queue::peek() {
    if (isEmpty()) {
        cout << "Queue is empty." << endl;
        return -1;
    }
    return front->data;
}

// Function to check if the queue is empty
bool Queue::isEmpty() {
    return (front == nullptr && rear == nullptr);
}

// Function to return the total number of elements present in the queue
int Queue::getSize() {
    return size;
}
