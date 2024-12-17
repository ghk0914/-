#include <iostream>
using namespace std;

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

int getDepth(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    int leftDepth = getDepth(root->left);
    int rightDepth = getDepth(root->right);
    return max(leftDepth, rightDepth) + 1;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);

    int depth = getDepth(root);
    cout << "The depth of the binary tree is: " << depth << endl;

    return 0;
}
