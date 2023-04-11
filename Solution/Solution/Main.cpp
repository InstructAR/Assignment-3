#include <iostream>
#include "InfixToPostFix.h"
#include "Queue.h"
using namespace std;

int main() {
    string exp;
    cout << "Enter an infix expression: ";
    getline(cin, exp);
    if (!isBalanced(exp)) {
        cout << "The expression is invalid." << endl;
    }
    else {
        string postfix = infixToPostfix(exp);
        cout << "Postfix expression: " << postfix << endl;
    }
    
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout << "Front element: " << q.peek() << endl;
    cout << "Dequeued element: " << q.dequeue() << endl;
    cout << "Front element: " << q.peek() << endl;
    cout << "Queue size: " << q.getSize() << endl;
    return 0;

}