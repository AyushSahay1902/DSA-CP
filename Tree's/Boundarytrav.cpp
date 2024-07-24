#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

Node* insertNode(vector<int>& nums, int& index) {
    if (index >= nums.size() || nums[index] == -1) {
        index++;
        return NULL;
    }
    Node* newNode = new Node(nums[index]);
    index++;
    newNode->left = insertNode(nums, index);
    newNode->right = insertNode(nums, index);
    return newNode;
}

void traverseRight(Node* root, vector<int>& ans){
    if(root == nullptr || (root->left == nullptr && root->right == nullptr)){
        return;
    }
    if(root->right){
        traverseRight(root->right, ans);
    }else{
        traverseRight(root->left, ans);
    }
    ans.push_back(root->data);
}

void traverseleft(Node* root, vector<int>& ans){
    if(root == nullptr || (root->left == nullptr && root->right == nullptr)){
        return;
    }
    
    ans.push_back(root->data);
    if(root->left){
        traverseleft(root->left, ans);
    }else{
        traverseleft(root->right, ans);
    }
}

void traverseLeaf(Node* root, vector<int>& ans){
    if(root == nullptr){
        return;
    }
    if(root->left == nullptr && root->right == nullptr){
        ans.push_back(root->data);
        return;
    }
    traverseLeaf(root->left, ans);
    traverseLeaf(root->right, ans);
}

vector<int> boundaryTraversal(Node* root){
    vector<int> ans;
    if(root == nullptr){
        return ans;
    }

    ans.push_back(root->data);
    //traverse left boundary
    traverseleft(root->left, ans);
    //traverse leaf nodes
    traverseLeaf(root->left, ans);
    traverseLeaf(root->right, ans);
    //traverse right part
    traverseRight(root->right, ans);
    return ans;
}

int main() {
    int t;
    cin >> t;
    while(t--){
        vector<int> nums;
    int num;
    while (cin >> num && num != 0) {
        nums.push_back(num);
    }

    int index = 0;
    Node* root = insertNode(nums, index);

    //boundary traversal
    cout << "Boundary traversal: ";
    vector<int> result = boundaryTraversal(root);
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;
    }

    return 0;
}

/*
vector<int> verticalOrder(Node *root)
    {
        map<int,vector<int>> mp;
        queue<pair<Node*,int>> q;
        vector<int> ans;
        if(!root)
        return ans;
        
        q.push(make_pair(root,0));
        while(!q.empty())
        {
            pair<Node*,int> p = q.front();
            q.pop();
            
            Node *curr = p.first;
            int hd = p.second;
            
            mp[hd].push_back(curr->data);
            
            if(curr->left)
            q.push(make_pair(curr->left,hd-1));
            if(curr->right)
            q.push(make_pair(curr->right,hd+1));
        }
         for(auto it: mp)
        {
            for(auto i : it.second)
            {
                ans.push_back(i);
            }
        }
        return ans;
}
*/