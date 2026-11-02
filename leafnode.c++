#include <iostream>
using namespace std;

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

// Create Binary Tree
Node* createTree() {
    int value;

    cout << "Enter data (-1 for no node): ";
    cin >> value;

    if (value == -1)
        return nullptr;

    Node* root = new Node(value);

    cout << "Enter left child of " << value << endl;
    root->left = createTree();

    cout << "Enter right child of " << value << endl;
    root->right = createTree();

    return root;
}

// Preorder Traversal
// Root -> Left -> Right
void preorder(Node* root) {
    if (root == nullptr)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Postorder Traversal
// Left -> Right -> Root
void postorder(Node* root) {
    if (root == nullptr)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// Count Leaf Nodes
int countLeaf(Node* root) {
    if (root == nullptr)
        return 0;

    if (root->left == nullptr && root->right == nullptr)
        return 1;

    return countLeaf(root->left) + countLeaf(root->right);
}

// Count Internal Nodes
int countInternal(Node* root) {
    if (root == nullptr)
        return 0;

    if (root->left == nullptr && root->right == nullptr)
        return 0;

    return 1 + countInternal(root->left)
             + countInternal(root->right);
}

int main() {

    // Create Binary Tree
    Node* root = createTree();

    // Traversals
    cout << "\nPreorder Traversal: ";
    preorder(root);

    cout << "\nPostorder Traversal: ";
    postorder(root);

    // Count nodes
    cout << "\n\nNumber of Leaf Nodes: "
         << countLeaf(root);

    cout << "\nNumber of Internal Nodes: "
         << countInternal(root);

    return 0;
}