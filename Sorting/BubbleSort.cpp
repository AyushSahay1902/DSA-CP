// Bubblesort algorithm
// Time Complexity: O(n^2)
// Auxiliary Space: O(1)

#include <iostream>
using namespace std;

void Bubblesort(int arr[], int n) {
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-1-i; j++) {
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

int main() {
    int arr[] = {5, 4, 3, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    Bubblesort(arr, n);
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
// Use cases of bubble sort: small array, array with small values. 
// Bubble sort is a stable sort. Why? Because it swaps the elements only if they are not equal.
// Bubble sort is adaptive. Why? Because it takes O(n) time when the array is already sorted.
// Bubble sort is not adaptive. Why? Because it takes O(n^2) time when the array is sorted in reverse order.