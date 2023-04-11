#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Function to check if a given character is an opening bracket
bool isOpeningBracket(char c);

// Function to check if a given character is a closing bracket
bool isClosingBracket(char c);

// Function to check if two brackets are matching
bool isMatchingBracket(char opening, char closing);

// Function to perform Balanced Parentheses Check
bool isBalanced(string exp);

// Function to get the precedence of an operator
int getPrecedence(char op);

// Function to convert infix expression to postfix expression
string infixToPostfix(string exp);