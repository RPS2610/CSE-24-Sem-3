#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

bool search(Node* root, int key) {
    if (root == NULL)
        return false;

    if (root->data == key)
        return true;

    if (key < root->data)
        return search(root->left, key);

    return search(root->right, key);
}

int findMin(Node* root) {
    if (root == NULL)
        return -1;

    while (root->left != NULL)
        root = root->left;

    return root->data;
}

int findMax(Node* root) {
    if (root == NULL)
        return -1;

    while (root->right != NULL)
        root = root->right;

    return root->data;
}

Node* deleteNode(Node* root, int key) {
    if (root == NULL)
        return NULL;

    if (key < root->data)
        root->left = deleteNode(root->left, key);

    else if (key > root->data)
        root->right = deleteNode(root->right, key);

    else {
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = root->right;

        while (temp->left != NULL)
            temp = temp->left;

        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

int main() {
    Node* root = NULL;
    int choice, value;

    do {
        cout << "\n\n--- BST OPERATIONS ---";
        cout << "\n1. Insertion";
        cout << "\n2. Searching";
        cout << "\n3. Find Minimum";
        cout << "\n4. Find Maximum";
        cout << "\n5. Deletion";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                root = insert(root, value);
                cout << "Value inserted successfully!";
                break;

            case 2:
                cout << "Enter value to search: ";
                cin >> value;

                if (search(root, value))
                    cout << "Value found!";
                else
                    cout << "Value not found!";
                break;

            case 3:
                if (root == NULL)
                    cout << "Tree is empty!";
                else
                    cout << "Minimum value: " << findMin(root);
                break;

            case 4:
                if (root == NULL)
                    cout << "Tree is empty!";
                else
                    cout << "Maximum value: " << findMax(root);
                break;

            case 5:
                cout << "Enter value to delete: ";
                cin >> value;

                if (search(root, value)) {
                    root = deleteNode(root, value);
                    cout << "Value deleted successfully!";
                }
                else {
                    cout << "Value not found!";
                }
                break;

            default:
                cout << "Invalid choice!";
        }

    } while (true);

    return 0;
}