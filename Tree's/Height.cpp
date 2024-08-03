#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

class BST {
    Node* root;
    queue<Node*> q;

public:
    BST() { root = nullptr; }

    void _insert(Node*& root, int data) {
        if (root == nullptr) {
            root = new Node();
            root->data = data;
            root->left = root->right = nullptr;
        } else {
            if (data < root->data) {
                _insert(root->left, data);
            } else {
                _insert(root->right, data);
            }
        }
    }

    void insert(int data) { _insert(root, data); }

    

    int height() {
        if (root == nullptr) return 0;

        int height = 0;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            height++;

            for (int i = 0; i < size; i++) {
                Node* node = q.front();
                q.pop();

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }

        return height;
    }
};

int main() {
    BST bt;
    bt.insert(10);
    bt.insert(5);
    bt.insert(15);
    bt.insert(3);
    bt.insert(7);
    bt.insert(12);
    bt.insert(18);

    cout << "Height of the tree: " << bt.height() << endl;
    return 0;
}

//Visual representation of the tree:
//          10
//         /  \
//        5    15
//       / \   / \
//      3   7 12 18
//Height of the tree: 3