#include <iostream>
using namespace std;

// Definition of a Node in the binary tree
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BinaryTree {
private:
    Node* root;

    // Preorder traversal (Root -> Left -> Right)
    void preorderTraversal(Node* node) {
        if (node == nullptr) return;
        cout << node->data << " ";
        preorderTraversal(node->left);
        preorderTraversal(node->right);
    }

    // Inorder traversal (Left -> Root -> Right)
    void inorderTraversal(Node* node) {
        if (node == nullptr) return;
        inorderTraversal(node->left);
        cout << node->data << " ";
        inorderTraversal(node->right);
    }

    // Postorder traversal (Left -> Right -> Root)
    void postorderTraversal(Node* node) {
        if (node == nullptr) return;
        postorderTraversal(node->left);
        postorderTraversal(node->right);
        cout << node->data << " ";
    }

public:
    BinaryTree() { root = nullptr; }

    // Function to manually insert nodes (for testing purposes)
    void buildTree() {
        root = new Node(1);
        root->left = new Node(2);
        root->right = new Node(3);
        root->left->left = new Node(4);
        root->left->right = new Node(5);
        root->right->left = new Node(6);
        root->right->right = new Node(7);
    }

    // Public function to trigger Preorder traversal
    void preorder() {
        cout << "Preorder traversal: ";
        preorderTraversal(root);
        cout << endl;
    }

    // Public function to trigger Inorder traversal
    void inorder() {
        cout << "Inorder traversal: ";
        inorderTraversal(root);
        cout << endl;
    }

    // Public function to trigger Postorder traversal
    void postorder() {
        cout << "Postorder traversal: ";
        postorderTraversal(root);
        cout << endl;
    }
};

int main() {
    BinaryTree tree;
    tree.buildTree(); // Build a sample binary tree

    // Perform traversals
    tree.preorder();
    tree.inorder();
    tree.postorder();

    return 0;
}
