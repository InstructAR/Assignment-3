#include <iostream>
#include "InfixToPostFix.h"
#include "Queue.h"
#include <string>

using namespace std;

int main() {
    //infix to postfix example
    string infix;
    cout << "Enter an infix expression: ";
    getline(cin, infix);
    if (!isBalanced(infix)) {
        cout << "Invalid expression: unbalanced parentheses" << endl;
        return 0;
    }
    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl << endl;

    //Queue example
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