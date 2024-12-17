#include <iostream>
#include <stack>
#include <string>
#include <cctype> 
using namespace std;

// Function to get precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Function to convert infix to postfix expression
string infixToPostfix(const string& infix) {
    stack<char> operators; // Stack to store operators
    string postfix = "";   // Resulting postfix expression

    for (char ch : infix) {
        // If character is an operand (number or letter), append it to postfix
        if (isalnum(ch)) {
            postfix += ch;
        }
        // If character is a left parenthesis, push it to the stack
        else if (ch == '(') {
            operators.push(ch);
        }
        // If character is a right parenthesis
        else if (ch == ')') {
            while (!operators.empty() && operators.top() != '(') {
                postfix += operators.top();
                operators.pop();
            }
            operators.pop(); // Remove the '(' from the stack
        }
        // If character is an operator
        else {
            while (!operators.empty() && precedence(operators.top()) >= precedence(ch)) {
                postfix += operators.top();
                operators.pop();
            }
            operators.push(ch);
        }
    }

    // Pop all the remaining operators from the stack
    while (!operators.empty()) {
        postfix += operators.top();
        operators.pop();
    }

    return postfix;
}

int main() {
    string infixExpression;
    cout << "Enter an infix expression: ";
    cin >> infixExpression;
    string postfixExpression = infixToPostfix(infixExpression);
    cout << "Postfix expression: " << postfixExpression << endl;
    return 0;
}
