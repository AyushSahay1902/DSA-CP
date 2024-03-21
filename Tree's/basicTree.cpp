#include <iostream>
using namespace std;

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

class BinaryTree {
private:
    Node* buildTree() {
        int data;
        cout << "Enter the data: " << endl;
        cin >> data;

        if (data == -1) {
            return NULL;
        }

        Node* root = new Node(data);

        cout << "Enter the data for inserting in left of "<<data<< endl;
        root->left = buildTree();

        cout << "Enter the data for inserting in right of" <<data<< endl;
        root->right = buildTree();

        return root;
    }

public:
    Node* root;

    BinaryTree() {
        root = NULL;
    }

    void createTree() {
        root = buildTree();
    }
    void levelOrderTraversal(){}
};

int main() {
    BinaryTree bt;
    bt.createTree();
    // Add more functionality here, e.g., traversals, operations on the tree, etc.
    return 0;
}