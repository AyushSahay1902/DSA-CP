#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
//visited array

vector<int> g[N];

vector<vector<int>, list<int>> DFS(int V, iint E, vector<vector<int>> &edges){
    //prepare adjlist
    unordered_map<int, list<int>> adj;
    for(int i = 0; i<edges.size(); i++){
        int u = ed;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for(int i  = 0; i < 9; i++){
        int v1, v2;
        cin >> v1 >> v2;

        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
}

/*
class Solution {
private:
    int findMax(int number){
        int maxDigit = INT_MIN;
        while(number > 0){
            maxDigit = max(maxDigit, number % 10);
            number /= 10;
        }
        return maxDigit;
    }
    
public:
    int maxSum(vector<int>& nums) {
        // Intution
        // The idea in here is really very simple. We will find the maximum digit of a number and then add it to the map
        unordered_map<int, vector<int>> mp;
        for(auto &num : nums){
            int digit = findMax(num);
            if(mp.find(digit) == mp.end()){
                mp[digit] = {num};
            }
            else{
                mp[digit].push_back(num);
            }
        }
        int answer = -1;
        for(auto itr = mp.begin(); itr != mp.end(); itr++){
            vector<int> curr = itr->second;
            sort(curr.begin(), curr.end());
            if(curr.size() == 1) continue;
            answer = max(answer, curr[curr.size() - 1] + curr[curr.size() - 2]);
        }
        return answer;
    }
};
*/