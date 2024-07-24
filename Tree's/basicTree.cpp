#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize the node
    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

// Function to build the tree recursively
Node* buildTree(Node* root) {
    cout << "Enter the data for node (enter -1 for NULL):" << endl;
    int data;
    cin >> data;

    // If the input data is -1, return NULL
    if (data == -1) {
        return NULL;
    }

    // Create a new node with the input data
    root = new Node(data);

    // Recursively build the left subtree
    cout << "Enter the data for the left node of " << data << ":" << endl;
    root->left = buildTree(root->left);

    // Recursively build the right subtree
    cout << "Enter the data for the right node of " << data << ":" << endl;
    root->right = buildTree(root->right);

    return root;
}

// Function to perform level order traversal using a queue
void levelOrderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        if (current == NULL) {
            cout << endl;
            if (!q.empty()) {
                q.push(NULL);
            }
        } else {
            cout << current->data << " ";

            if (current->left != NULL) {
                q.push(current->left);
            }

            if (current->right != NULL) {
                q.push(current->right);
            }
        }
    }
}

// Inorder traversal
void inorder(Node* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Preorder traversal
void preOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

// Postorder traversal
void postOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int main() {
    Node* root = NULL;
    root = buildTree(root);

    cout << "Level Order Traversal:" << endl;
    levelOrderTraversal(root);

    cout << "Inorder Traversal:" << endl;
    inorder(root);
    cout << endl;

    cout << "Preorder Traversal:" << endl;
    preOrder(root);
    cout << endl;

    cout << "Postorder Traversal:" << endl;
    postOrder(root);
    cout << endl;

    return 0;
}
//1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1