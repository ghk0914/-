#include <iostream>
#define MAX_SIZE 100 // Define the maximum capacity of the queue

using namespace std;

class Queue {
private:
    int arr[MAX_SIZE]; // Array to store queue elements
    int front;         // Index pointing to the front of the queue
    int rear;          // Index pointing to the rear of the queue

public:
    // Constructor to initialize the queue
    Queue() {
        front = -1;
        rear = -1;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return (front == -1 && rear == -1);
    }

    // Check if the queue is full
    bool isFull() {
        return (rear + 1) % MAX_SIZE == front;
    }

    // Enqueue an element into the queue
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue overflow! Cannot enqueue element " << value << "." << endl;
        } else {
            if (isEmpty()) {
                front = rear = 0;
            } else {
                rear = (rear + 1) % MAX_SIZE;
            }
            arr[rear] = value;
            cout << "Enqueued " << value << " into the queue." << endl;
        }
    }

    // Dequeue an element from the queue
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue underflow! Cannot dequeue an element from an empty queue." << endl;
        } else {
            cout << "Dequeued " << arr[front] << " from the queue." << endl;
            if (front == rear) {
                front = rear = -1; // Reset the queue
            } else {
                front = (front + 1) % MAX_SIZE;
            }
        }
    }

    // Peek at the front element of the queue
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty! Cannot perform peek operation." << endl;
            return -1;
        } else {
            return arr[front];
        }
    }
};

int main() {
    Queue q; // Create a queue object

    // Test operations
    cout << "Is the queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element of the queue: " << q.peek() << endl;

    q.dequeue();
    cout << "Front element of the queue: " << q.peek() << endl;

    q.dequeue();
    q.dequeue();
    cout << "Is the queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl;

    q.dequeue(); // Test queue underflow condition

    q.enqueue(40);
    q.enqueue(50);
    cout << "Front element of the queue: " << q.peek() << endl;

    return 0;
}
