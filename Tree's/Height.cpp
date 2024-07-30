#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    vector<Node*> child;
}

struct Node* createNode(int data){
    Node* newNode = new Node();
    newNode->data = data;
    return newNode;
}

void addChild(Node* node, int data){
    //first create a new Node
    Node* newNode = createNode(data);
    node->child.push_back(newNode);
    return newNode;
}

void Print(Node* root){
    
}


int main() {
    //root pointer
    Node* root;

    root = createNode(3);
    addChild(root, 2);
    addChild(root, 1);

    return 0;
}