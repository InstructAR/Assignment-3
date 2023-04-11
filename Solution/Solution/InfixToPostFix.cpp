#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Function to check if a character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%');
}

// Function to get operator precedence
int getPrecedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/' || op == '%')
        return 2;
    return 0;
}

// Function to convert infix expression to postfix expression
string infixToPostfix(string infix) {
    string postfix;
    stack<char> s;
    for (char c : infix) {
        if (isalnum(c)) {
            postfix += c;
        }
        else if (isOperator(c)) {
            while (!s.empty() && s.top() != '(' && getPrecedence(s.top()) >= getPrecedence(c)) {
                postfix += s.top();
                s.pop();
            }
            s.push(c);
        }
        else if (c == '(') {
            s.push(c);
        }
        else if (c == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            if (!s.empty() && s.top() == '(') {
                s.pop();
            }
            else {
                return "Invalid expression: unbalanced parentheses";
            }
        }
    }
    while (!s.empty()) {
        if (s.top() == '(' || s.top() == ')') {
            return "Invalid expression: unbalanced parentheses";
        }
        postfix += s.top();
        s.pop();
    }
    return postfix;
}

// Function to check if the parentheses in an expression are balanced
bool isBalanced(string expression) {
    stack<char> s;
    for (char c : expression) {
        if (c == '(' || c == '{' || c == '[') {
            s.push(c);
        }
        else if (c == ')' || c == '}' || c == ']') {
            if (s.empty()) {
                return false;
            }
            char top = s.top();
            s.pop();
            if ((c == ')' && top != '(') || (c == '}' && top != '{') || (c == ']' && top != '[')) {
                return false;
            }
        }
    }
    return s.empty();
}