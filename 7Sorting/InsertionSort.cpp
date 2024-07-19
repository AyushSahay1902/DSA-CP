// Insertion Sort 
// Time Complexity: O(n^2)
// Auxiliary Space: O(1)

#include <iostream>
using namespace std;

void insertionsort(int arr[], int n){
    for(int i=1; i<n; i++){
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key; 
    }
}

int main() {
    int arr[] = {5, 4, 3, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    insertionsort(arr, n);
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
// Use cases of insertion sort: small array, array with small values.
// Insertion sort is a stable sort. Why? Because it swaps the elements only if they are not equal.
// Insertion sort is adaptive. Why? Because it takes O(n) time when the array is already sorted.