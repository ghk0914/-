#include <iostream>
using namespace std;

// Definition of a Node
struct Node {
    int data;       // Data part
    Node* next;     // Pointer to the next node

    // Constructor to initialize a new node
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;     // Pointer to the head of the list

public:
    // Constructor to initialize an empty list
    LinkedList() {
        head = nullptr;
    }

    // Insert a new node at the end of the list
    void insertNode(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            cout << "Inserted " << value << " as the first node." << endl;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        cout << "Inserted " << value << " into the list." << endl;
    }

    // Delete a node by value
    void deleteNode(int value) {
        if (head == nullptr) {
            cout << "The list is empty. Cannot delete " << value << "." << endl;
            return;
        }

        // If the node to be deleted is the head node
        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Deleted node with value " << value << " from the list." << endl;
            return;
        }

        // Search for the node to delete
        Node* temp = head;
        Node* prev = nullptr;
        while (temp != nullptr && temp->data != value) {
            prev = temp;
            temp = temp->next;
        }

        // If the node was not found
        if (temp == nullptr) {
            cout << "Node with value " << value << " not found in the list." << endl;
            return;
        }

        // Unlink the node and delete it
        prev->next = temp->next;
        delete temp;
        cout << "Deleted node with value " << value << " from the list." << endl;
    }

    // Display the entire linked list
    void displayList() {
        if (head == nullptr) {
            cout << "The list is empty." << endl;
            return;
        }

        Node* temp = head;
        cout << "Linked List: ";
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    LinkedList list;

    // Test insertion
    list.insertNode(10);
    list.insertNode(20);
    list.insertNode(30);
    list.displayList();

    // Test deletion
    list.deleteNode(20);
    list.displayList();

    list.deleteNode(10);
    list.displayList();

    list.deleteNode(30);
    list.displayList();

    // Test deleting from an empty list
    list.deleteNode(40);

    return 0;
}
