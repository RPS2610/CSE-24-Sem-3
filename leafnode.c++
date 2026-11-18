#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct Node {
    int info;
    Node* left;
    Node* right;
};

int leafnode_count(Node* p) {
    if (p == NULL)
        return 0;

    if (p->left == NULL && p->right == NULL)
        return 1;

    return leafnode_count(p->left) + leafnode_count(p->right);
}

int internalnode_count(Node* p) {
    if (p == NULL || (p->left == NULL && p->right == NULL))
        return 0;

    return 1 + internalnode_count(p->left) + internalnode_count(p->right);
}

Node* create() {
    int x;
    cin >> x;

    if (x == -1)
        return NULL;

    Node* newNode = new Node();

    newNode->info = x;
    newNode->left = create();
    newNode->right = create();

    return newNode;
}

int totalcount(Node* p) {
    if (p == NULL)
        return 0;

    return 1 + totalcount(p->left) + totalcount(p->right);
}

int leftchild(Node* p) {
    if (p == NULL)
        return 0;

    int count = 0;

    if ((p->left == NULL && p->right != NULL) ||
        (p->left != NULL && p->right == NULL))
        count = 1;

    return count + leftchild(p->left) + leftchild(p->right);
}

int twochild(Node* p) {
    if (p == NULL)
        return 0;

    int count = 0;

    if (p->left != NULL && p->right != NULL)
        count = 1;

    return count + twochild(p->left) + twochild(p->right);
}

int height(Node* p) {
    if (p == NULL)
        return -1;

    return 1 + max(height(p->left), height(p->right));
}

int sum(Node* p) {
    if (p == NULL)
        return 0;

    return p->info + sum(p->left) + sum(p->right);
}

int depth(Node* p) {
    if (p == NULL)
        return -1;

    return 1 + max(depth(p->left), depth(p->right));
}

// Preorder: Root - Left - Right
void preord(Node* root) {
    if (root == NULL)
        return;

    cout << root->info << " ";
    preord(root->left);
    preord(root->right);
}

// Inorder: Left - Root - Right
void inord(Node* root) {
    if (root == NULL)
        return;

    inord(root->left);
    cout << root->info << " ";
    inord(root->right);
}

// Postorder: Left - Right - Root
void postord(Node* root) {
    if (root == NULL)
        return;

    postord(root->left);
    postord(root->right);
    cout << root->info << " ";
}

// Level Order Traversal
void levelorder(Node* root) {
    if (root == NULL)
        return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        cout << temp->info << " ";

        if (temp->left != NULL)
            q.push(temp->left);

        if (temp->right != NULL)
            q.push(temp->right);
    }
}

// Left View
void leftview(Node* root) {
    if (root == NULL)
        return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int n = q.size();

        for (int i = 0; i < n; i++) {
            Node* temp = q.front();
            q.pop();

            if (i == 0)
                cout << temp->info << " ";

            if (temp->left != NULL)
                q.push(temp->left);

            if (temp->right != NULL)
                q.push(temp->right);
        }
    }
}

// Right View
void rightview(Node* root) {
    if (root == NULL)
        return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int n = q.size();

        for (int i = 0; i < n; i++) {
            Node* temp = q.front();
            q.pop();

            if (i == n - 1)
                cout << temp->info << " ";

            if (temp->left != NULL)
                q.push(temp->left);

            if (temp->right != NULL)
                q.push(temp->right);
        }
    }
}

int main() {
    Node* root = NULL;

    cout << "Enter tree elements (-1 for NULL): ";
    root = create();

    cout << "\nNumber of leaf nodes: ";
    cout << leafnode_count(root) << endl;

    cout << "Number of internal nodes: ";
    cout << internalnode_count(root) << endl;

    cout << "Total number of nodes: ";
    cout << totalcount(root) << endl;

    cout << "Number of nodes having one child: ";
    cout << leftchild(root) << endl;

    cout << "Number of nodes having two children: ";
    cout << twochild(root) << endl;

    cout << "Height of BT: " << height(root) << endl;

    cout << "Sum of all node values: " << sum(root) << endl;

    cout << "Depth of BT: " << depth(root) << endl;

    cout << "Preorder: ";
    preord(root);

    cout << "\nInorder: ";
    inord(root);

    cout << "\nPostorder: ";
    postord(root);

    cout << "\nLevel Order: ";
    levelorder(root);

    cout << "\nLeft View: ";
    leftview(root);

    cout << "\nRight View: ";
    rightview(root);

    return 0;
}