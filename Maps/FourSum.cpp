#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> FourSum(vector<int> nums, int target){
    vector<vector<int>> res;
    if(nums.empty()){
        return res;
    }
    int n = nums.size();
    sort(nums.begin(), nums.end());
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            int target_2 = target - nums[i] - nums[j];
            int front = j+1;
            int back = n-1;
            while(front < back){
                int two_sum = nums[front] + nums[back];
                if(two_sum < target_2){
                    front++;
                }else if(two_sum > target_2){
                    back--;
                }else{
                    vector<int> quadruplet(4, 0);
                    quadruplet[0] = nums[i];
                    quadruplet[1] = nums[j];
                    quadruplet[2] = nums[front];
                    quadruplet[3] = nums[back];
                    res.push_back(quadruplet);

                    while(front < back && nums[front] == quadruplet[2]) ++front;
                    while(front > back && nums[back] == quadruplet[3]) --back;
                }
            }
            while(j +1 < n && nums[j+1] == nums[j]) ++j;

        }
        while(i+1 < n && nums[i+1] == nums[i]) ++i;
    }

}


int main() {
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;
    vector<vector<int>> res = FourSum(nums, target);
    for(auto i: res){
        for(auto j: i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}