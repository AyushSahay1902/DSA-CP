/*
1. AVL trees- height balanced binary search trees (h<=1)
            - O(logn) for all operations
            - rotations
            - Good for lookups not for insertion and deletions 
            - Red black trees are used in stl
2. Red black trees- self balancing binary search trees
            - Time complexity is O(logn) for all operations
            - Height is calculated by black nodes
            - 5 properties
            - Used in stl
3. Ternary search trees- used for dictionary operations
            - Time complexity is O(logn) for all operations
            - 3 children
            - Used in spell checkers

*/



#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

class BinaryTree {
    Node* root;
    queue<Node*> q; // Queue to store nodes

public:
    BinaryTree() { root = nullptr; }

    // Function to create a new node
    Node* createNode(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->left = newNode->right = nullptr;
        return newNode;
    }

    // Function to insert a node into the binary tree
    void insert(int data) {
        Node* newNode = createNode(data);

        if (root == nullptr) {
            root = newNode;
        } else {
            q.push(root);

            while (!q.empty()) {
                Node* temp = q.front();
                q.pop();

                if (temp->left == nullptr) {
                    temp->left = newNode;
                    break;
                } else {
                    q.push(temp->left);
                }

                if (temp->right == nullptr) {
                    temp->right = newNode;
                    break;
                } else {
                    q.push(temp->right);
                }
            }
        }
    }

    // Function to perform level order traversal
    void levelOrderTraversal() {
        if (root == nullptr) return;

        q.push(root);

        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();
            cout << temp->data << " ";

            if (temp->left != nullptr) q.push(temp->left);
            if (temp->right != nullptr) q.push(temp->right);
        }
    }
};



int main() {
    BinaryTree bt;

    bt.insert(1);
    bt.insert(2);
    bt.insert(3);
    bt.insert(4);
    bt.insert(5);

    cout << "Level Order Traversal: ";
    bt.levelOrderTraversal();

    return 0;
}
// Linked List Implementation
struct Node {
    int data;
    Node* left;
    Node* right;
    Node* next; // Pointer for linked list
};
class BinaryTree {
    Node* root;
    Node* head; // Head of the linked list

public:
    BinaryTree() { root = nullptr; head = nullptr; }

    // Function to create a new node
    Node* createNode(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->left = newNode->right = nullptr;
        newNode->next = nullptr;
        return newNode;
    }

    // Function to insert a node into the binary tree
    void insert(int data) {
        Node* newNode = createNode(data);

        if (root == nullptr) {
            root = newNode;
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;

            // Insert newNode as left or right child of temp
            if (temp->left == nullptr) {
                temp->left = newNode;
            } else {
                temp->right = newNode;
            }
        }
    }

    // Function to perform in-order traversal
    void inOrderTraversal(Node* node) {
        if (node == nullptr) return;

        inOrderTraversal(node->left);
        cout << node->data << " ";
        inOrderTraversal(node->right);
    }

    // Function to perform level order traversal
    void levelOrderTraversal() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};
//Stack implementation
class BinaryTree {
    Node* root;
    stack<Node*> s; // Stack to store nodes

public:
    BinaryTree() { root = nullptr; }

    // Function to create a new node
    Node* createNode(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->left = newNode->right = nullptr;
        return newNode;
    }

    // Function to insert a node into the binary tree
    void insert(int data) {
        Node* newNode = createNode(data);

        if (root == nullptr) {
            root = newNode;
        } else {
            Node* temp = root;

            while (true) {
                if (data < temp->data) {
                    if (temp->left == nullptr) {
                        temp->left = newNode;
                        break;
                    }
                    s.push(temp);
                    temp = temp->left;
                } else {
                    if (temp->right == nullptr) {
                        temp->right = newNode;
                        break;
                    }
                    s.push(temp);
                    temp = temp->right;
                }
            }

            // Pop nodes from stack
            while (!s.empty()) {
                s.pop();
            }
        }
    }

    // Function to perform in-order traversal
    void inOrderTraversal(Node* node) {
        if (node == nullptr) return;

        inOrderTraversal(node->left);
        cout << node->data << " ";
        inOrderTraversal(node->right);
    }

    // Function to perform pre-order traversal
    void preOrderTraversal(Node* node) {
        if (node == nullptr) return;

        cout << node->data << " ";
        preOrderTraversal(node->left);
        preOrderTraversal(node->right);
    }
};

/*

In competitive programming, the choice between stack, queue, and linked list implementation depends on the specific problem and constraints. However, here's a general guideline:
Stack: Use when you need to implement recursive algorithms iteratively, or when you need to reverse the order of elements (e.g., evaluating postfix expressions).
Queue: Use when you need to implement BFS (Breadth-First Search) or when you need to process elements in the order they were added (FIFO).
Linked List: Use when you need to implement dynamic memory allocation, or when you need to frequently insert/remove elements at arbitrary positions.
For implementing BST (Binary Search Tree) in competitive programming, a balanced BST like AVL Tree or Red-Black Tree is preferred. Here are some STL methods to implement BST in lesser lines of code:
set (or multiset): Use when you need a basic BST with automatic balancing.
insert(): O(log n)
erase(): O(log n)
find(): O(log n)
map (or multimap): Use when you need a BST with key-value pairs.
insert(): O(log n)
erase(): O(log n)
find(): O(log n)
unordered_set (or unordered_multiset): Use when you need a hash-based BST with fast lookups.
insert(): O(1) on average
erase(): O(1) on average
find(): O(1) on average
Note that these STL containers do not provide direct access to the tree structure, but they provide efficient operations for insertion, deletion, and search.
If you need more control over the BST implementation, consider using a self-balancing BST like AVL Tree or Red-Black Tree. These trees ensure O(log n) time complexity for search, insert, and delete operations.
*/