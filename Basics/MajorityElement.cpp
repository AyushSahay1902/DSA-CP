#include<iostream>
using namespace std;
#include<vector>

//using a hashmap in cpp it will take O(n logn)
//More Voting Algorithm - cnt = 0, ele = 0,
// 7,7,2,3,6,7,7,2,3,5,7,7,5
// 1, 2, 1, 0, 1, 0, 1, 0, 1, 0, 1, 2, 1 - Majority is 7
class Solution{
    public:
    int MajorityElement(vector<int> &nums){
        int count = 0;
        int currEle = 0;

        for(int num: nums){
            if(count == 0){
                currEle = num;
            }
            if(num == currEle) count += 1;
            else count -= 1;
        }
        return currEle;
    }
};
int main(){
    vector<int> nums = {7,7,2,3,6,7,7,2,3,5,7,7,5};
    Solution sol;
    cout<<"Majority Element is: "<<sol.MajorityElement(nums);
    return 0;
}
