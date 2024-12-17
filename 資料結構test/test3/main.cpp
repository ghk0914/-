#include <iostream>
#define MAX_SIZE 100 // Define the maximum capacity of the stack

using namespace std;

class Stack {
private:
    int arr[MAX_SIZE]; // Array to store stack elements
    int top;           // Index pointing to the top of the stack

public:
    // Constructor to initialize the stack
    Stack() {
        top = -1; // Initially, the stack is empty
    }

    // Check if the stack is empty
    int empty() {
        return (top == -1) ? 1 : 0; // If top == -1, return 1 (empty); otherwise return 0
    }

    // Push an element into the stack
    void push(int value) {
        if (top == MAX_SIZE - 1) { // Stack overflow condition
            cout << "Stack overflow! Cannot push element " << value << " into the stack." << endl;
        } else {
            arr[++top] = value; // Add element to the stack and update top
            cout << "Pushed " << value << " into the stack." << endl;
        }
    }

    // Pop an element from the top of the stack
    void pop() {
        if (empty()) {
            cout << "Stack underflow! Stack is empty, cannot pop an element." << endl;
        } else {
            cout << "Popped " << arr[top] << " from the stack." << endl;
            top--; // Remove element and update top
        }
    }

    // Peek at the top element of the stack
    int peek() {
        if (empty()) {
            cout << "Stack is empty! Cannot perform peek operation." << endl;
            return -1; // Return -1 to indicate no element
        } else {
            return arr[top]; // Return the top element
        }
    }
};

int main() {
    Stack s; // Create a stack object

    // Test operations
    cout << "Is the stack empty? " << s.empty() << endl; // 1: empty, 0: not empty

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element of the stack: " << s.peek() << endl;

    s.pop();
    cout << "Top element of the stack: " << s.peek() << endl;

    s.pop();
    s.pop();
    cout << "Is the stack empty? " << s.empty() << endl;

    s.pop(); // Test stack underflow condition

    return 0;
}
