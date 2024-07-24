#include <iostream>
#include <vector>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

Node* buildTree(Node* root){
    int data;
    cin >> data;

    //bass case
    if(data == -1){
        return nullptr;
    }

    root = new Node(data);

    root->left = buildTree(root->left);
    root->right = buildTree(root->right);

    return root;
}

pair<bool, int> isSumtree(Node* root){
    if(root == nullptr){
        return {true, 0};
    }

    if(root->left == nullptr && root->right == nullptr){
        return {true, root->data};
    }

    pair<bool, int> left = isSumtree(root->left);
    pair<bool, int> right = isSumtree(root->right);

    bool isLeftSumTree = left.first;
    bool isRightSumTree = right.first;

    if(isLeftSumTree && isRightSumTree && root->data == left.second + right.second){
        return {true, 2*root->data};
    }else{
        return {false, 0};
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> nodes(n);

    for(int i = 0; i < n; i++){
        cin >> nodes[i];
    }

    Node* root = buildTree(root);

    pair<bool, int> ans = isSumtree(root);

    cout << ans.second << endl;

    if(ans.first){
        cout << "Yes";
    
    }else{
        cout << "No";
    }

    return 0;

}
//1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1