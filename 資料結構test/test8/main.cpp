#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to check if brackets are balanced
bool areBracketsBalanced(const string& expr) {
    stack<char> s; // Stack to store opening brackets

    // Traverse the expression
    for (char ch : expr) {
        if (ch == '(' || ch == '{' || ch == '[') {
            // Push opening brackets onto the stack
            s.push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            // If the stack is empty, there is no matching opening bracket
            if (s.empty()) {
                return false;
            }

            // Check if the current closing bracket matches the top of the stack
            char top = s.top();
            if ((ch == ')' && top == '(') ||
                (ch == '}' && top == '{') ||
                (ch == ']' && top == '[')) {
                s.pop(); // Pop the matched opening bracket
            } else {
                return false; // Mismatched brackets
            }
        }
    }

    // If the stack is empty, all brackets are matched
    return s.empty();
}

int main() {
    string expression;
    cout << "Enter an expression to check for balanced brackets: ";
    cin >> expression;

    if (areBracketsBalanced(expression)) {
        cout << "The brackets are balanced." << endl;
    } else {
        cout << "The brackets are NOT balanced." << endl;
    }

    return 0;
}
