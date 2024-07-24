#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

int height(Node* root) {
    if (root == NULL) {
        return 0;
    }
    return max(height(root->left), height(root->right)) + 1;
}

// Function to check if the tree is balanced
bool isbalanced(Node* root) {
    // base case
    if (root == NULL) {
        return true;
    }

    bool left = isbalanced(root->left);
    bool right = isbalanced(root->right);

    bool ans = abs(height(root->left) - height(root->right)) <= 1;
    if (ans && right && left) {
        return true;
    }
    return false;
}

bool isIdentical(Node* r1, Node* r2){
    if(r1 == NULL && r2 == NULL){
        return true;
    }
    if(r1 == NULL || r2 == NULL){
        return false;
    }
    bool isLeftIdentical = isIdentical(r1->left, r2->left);
    bool isRightIdentical = isIdentical(r1->right, r2->right);

    return r1->data == r2->data && isLeftIdentical && isRightIdentical;
}

// Function to build a binary tree
Node* buildTree(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int main() {
    Node* root = buildTree(1);
    root->left = buildTree(2);
    root->right = buildTree(3);
    root->left->left = buildTree(4);
    root->left->right = buildTree(5);
    root->right->left = buildTree(6);
    root->right->right = buildTree(7);
    root->right->right->right = buildTree(8);

    cout << isbalanced(root) << endl;

    return 0;
}