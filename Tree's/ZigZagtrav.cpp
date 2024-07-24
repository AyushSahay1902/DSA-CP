#include <iostream>
#include <stack>
using namespace std;

class Node{
    public:
    int data;
    Node* left, *right;

    Node(int data){
        this->data = data;
        left = right = NULL;
    }
};

Node* buildTree(){
    int data;
    cin >> data;

    if(data == -1){
        return nullptr;
    }

    Node* root = new Node(data);

    cout << "Enter left child of " << data << ": ";
    root->left = buildTree();

    cout << "Enter right child of " << data << ": ";
    root->right = buildTree();

    return root;
}

void zigZagTraversal(Node* root){
    if(root == nullptr){
        return;
    }
    stack<Node*> currLevel, nextLevel;

    currLevel.push(root);

    bool leftToRight = true;
    while(!currLevel.empty()){
        Node* temp = currLevel.top();
        currLevel.pop();

        if(temp){
            cout << temp->data << " ";

            if(leftToRight){
                if(temp->left){
                    nextLevel.push(temp->left);
                }
                if(temp->right){
                    nextLevel.push(temp->right);
                }
            }else{
                if(temp->right){
                    nextLevel.push(temp->right);
                }
                if(temp->left){
                    nextLevel.push(temp->left);
                }
            }
        }
        if (currLevel.empty()) {
            leftToRight = !leftToRight;
            swap(currLevel, nextLevel);
        }
    }

    cout << endl;
}

int main() {
    Node* root = buildTree();

    cout << "Zigzag traversal: ";
    zigZagTraversal(root);
    
    return 0;
}