#include <iostream>
#include <vector>
#include <string>
using namespace std;

void solve(vector<int>& nums, int index, vector<vector<int>>& ans) {
    if (index >= nums.size()) {
        ans.push_back(nums);
        return;
    }

    for (int j = index; j < nums.size(); j++) {
        swap(nums[index], nums[j]);
        solve(nums, index + 1, ans);
        // backtracking
        swap(nums[index], nums[j]);
    }
}

vector<vector<int>> permutation(vector<int>& nums) {
    vector<vector<int>> ans;
    int index = 0;
    solve(nums, index, ans);
    return ans;
}

int main() {
    // Take input as a vector
    vector<int> nums = {1, 2, 3};
    
    vector<vector<int>> result = permutation(nums);

    // Print the permutations
    for (const auto& perm : result) {
        for (int num : perm) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
