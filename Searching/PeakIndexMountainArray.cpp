//Find the peak index in a mountain array.
//Given an array that is definitely a mountain, return any i such that 
//arr[0] < arr[1] < ... arr[i-1] < arr[i] > arr[i+1] > ... > arr[arr.length - 1].

#include <iostream>
#include <vector>
using namespace std;

int peakIndexMountainArray(vector<int>& arr) {
    int left = 0; 
    int right = arr.size() - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] < arr[mid + 1]) left = mid + 1;
        else right = mid;
    }
    return left;
}


int main() {
    vector<int> arr = {3, 4, 5, 1};
    cout << peakIndexMountainArray(arr) << endl;
    return 0;
}