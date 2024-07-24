#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Tree class
class Tree {
private:
    Node* root;

public:
    Tree() : root(nullptr) {}

    // Create a new node with given data
    Node* createNode(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->left = nullptr;
        newNode->right = nullptr;
        return newNode;
    }

    // Insert a new node into the tree
    void insert(int data) {
        if (root == nullptr) {
            root = createNode(data);
        } else {
            queue<Node*> q;
            q.push(root);
            while (!q.empty()) {
                Node* temp = q.front();
                q.pop();
                if (temp->left == nullptr) {
                    temp->left = createNode(data);
                    break;
                } else {
                    q.push(temp->left);
                }
                if (temp->right == nullptr) {
                    temp->right = createNode(data);
                    break;
                } else {
                    q.push(temp->right);
                }
            }
        }
    }

    // Get the root of the tree
    Node* getRoot() {
        return root;
    }
};

// Calculate the height of a tree
int height(Node* node) {
    if (node == nullptr) {
        return 0;
    }

    int left = height(node->left);
    int right = height(node->right);

    int ans = max(left, right) + 1;
    return ans;
}

// Calculate the diameter of a tree
int diameter(Node* root) {
    // Base case
    if (root == nullptr) {
        return 0;
    }

    int op1 = diameter(root->left);
    int op2 = diameter(root->right);
    int op3 = height(root->left) + height(root->right) + 1;

    return max(max(op1, op2), op3);
}

pair<int, int> diameterFast(Node* root){
    //base case
    if(root  == nullptr){
        pair<int, int> p;
        p.first = 0;
        p.second = 0;
        return p;
    }

    pair<int, int> left = diameterFast(root->left);
    pair<int, int> right = diameterFast(root->right);

    pair<int, int> ans;
    ans.first = max(left.first, right.first) + 1;
    ans.second = max(max(left.second, right.second), left.first + right.first + 1);

    return ans;
}

int main() {
    Tree tree;
    tree.insert(2);
    tree.insert(8);
    tree.insert(4);
    tree.insert(1);
    tree.insert(6);
    tree.insert(3);

    Node* root = tree.getRoot();
    int dia = diameter(root);
    cout << "Diameter of the tree: " << dia << endl;
    int diaFast = diameterFast(root).second;
    cout << "Diameter of the tree: " << dia << endl;

    return 0;
}