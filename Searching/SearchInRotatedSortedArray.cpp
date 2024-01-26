//Given will be rotated and sorted array. We have to find the target element.
//time complexity: O(logn)
//space complexity: O(1)

#include <iostream>
#include <vector>
using namespace std;

int searchInRotatedSortedArray(vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;
    int mid = left + (right - left) / 2;
    while (left <= right){
        if(arr[mid] == target){
            return mid;
        }
        else if(arr[left] <= arr[mid]){
            if(target >= arr[left] && target < arr[mid]){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        else{
            if(target > arr[mid] && target <= arr[right]){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        mid = left + (right - left) / 2;
    }
    return -1;
}
int main(){
    vector<int> arr = {4,5,6,7,0,1,2};
    int target = 0;
    cout << searchInRotatedSortedArray(arr, target);
    return 0;
}