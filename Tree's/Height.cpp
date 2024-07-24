#include <iostream>
using namespace std;

class Node{
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this -> data = data;
        this->left = NULL;
        this->right = NULL;
    }
}

int height(struct Node* node){
    //base case
    if(node == NULL){
        return 0;
    }
    int left = height(node -> left);
    int right = height(node -> right);

    int ans = max(left, right) + 1;
    return ans;
}

int main() {
    int d;
    cin >> d;
    Node root = new Node(d);

    
}