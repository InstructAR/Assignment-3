#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Function to check if a character is an operator
bool isOperator(char c);

// Function to get operator precedence
int getPrecedence(char op);

// Function to convert infix expression to postfix expression
string infixToPostfix(string infix);

// Function to check if the parentheses in an expression are balanced
bool isBalanced(string expression);