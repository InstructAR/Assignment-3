#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Function to check if a given character is an opening bracket
bool isOpeningBracket(char c) {
    return (c == '(' || c == '{' || c == '[');
}

// Function to check if a given character is a closing bracket
bool isClosingBracket(char c) {
    return (c == ')' || c == '}' || c == ']');
}

// Function to check if two brackets are matching
bool isMatchingBracket(char opening, char closing) {
    return ((opening == '(' && closing == ')') ||
        (opening == '{' && closing == '}') ||
        (opening == '[' && closing == ']'));
}

// Function to perform Balanced Parentheses Check
bool isBalanced(string exp) {
    stack<char> s;
    for (char c : exp) {
        if (isOpeningBracket(c)) {
            s.push(c);
        }
        else if (isClosingBracket(c)) {
            if (s.empty() || !isMatchingBracket(s.top(), c)) {
                return false;
            }
            s.pop();
        }
    }
    return s.empty();
}

// Function to get the precedence of an operator
int getPrecedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    }
    else if (op == '*' || op == '/' || op == '%') {
        return 2;
    }
    else {
        return 0;
    }
}

// Function to convert infix expression to postfix expression
string infixToPostfix(string exp) {
    stack<char> s;
    string postfix = "";
    for (char c : exp) {
        if (isalnum(c)) { // if character is a letter or digit, add it to the postfix expression
            postfix += c;
        }
        else if (isOpeningBracket(c)) {
            s.push(c);
        }
        else if (isClosingBracket(c)) {
            while (!s.empty() && !isOpeningBracket(s.top())) {
                postfix += s.top();
                s.pop();
            }
            if (!s.empty() && isOpeningBracket(s.top())) {
                s.pop();
            }
        }
        else { // if character is an operator
            while (!s.empty() && getPrecedence(s.top()) >= getPrecedence(c)) {
                postfix += s.top();
                s.pop();
            }
            s.push(c);
        }
    }
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }
    return postfix;
}