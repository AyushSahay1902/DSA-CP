//Array is sorted and rotated. We have to find the pivot element.
//Pivot element is the element which is greater than its next element.
//Input: 5 6 7 8 9 10 1 2 3
//Output: 10
#include <iostream>
#include <vector>
using namespace std;

int findPivotElement(vector<int>& arr) {
    int left = 0;
    int right = arr.size() - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] > arr[mid + 1]) left = mid + 1;
        else right = mid;
    }
    return arr[right];
}

int main() {
    vector<int> arr = {5, 6, 7, 8, 9, 10, 1, 2, 3};
    int pivot = findPivotElement(arr);
    cout << "Pivot element is: " << pivot << endl;

    return 0;
}