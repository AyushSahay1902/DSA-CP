//The line concept
// 2 Approaches : - Recursion and Level Order Traversal
#include <iostream>
#include <map>// not unordered_map
#include <queue>
using namespace std;


class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};


vector<int> topView(Node* root) {
    vector<int> ans;
    if(root == NULL) return ans;
    map<int, int> m;
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    while(!q.empty()){
        Node* temp = q.front().first;
        int h = q.front().second;
        q.pop();
        if(m.find(h) == m.end()) m[h] = temp->data;
        if(temp->left) q.push({temp->left, h-1});
        if(temp->right) q.push({temp->right, h+1});
    }
    for(auto x: m) ans.push_back(x.second);
    return ans;
}




int main() {
    // your code goes here
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->right->right = new Node(7);

    //Top View
    vector<int> result = topView(root);
    for(auto x: result) cout<<x<<" ";
    return 0;
}