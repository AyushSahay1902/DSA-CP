// Quick sort algorithm
// Time Complexity: O(nlogn)
// Auxiliary Space: O(1)

#include <iostream>
using namespace std;

int partition(int arr[], int l, int r) {
    int pivot = arr[r];
    int i = l-1;
    for(int j=l; j<r; j++) {
        if(arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[r]);
    return i+1;
}

void quicksort(int arr[], int l, int r) {
    if(l<r) {
        int pi = partition(arr, l, r);
        quicksort(arr, l, pi-1);
        quicksort(arr, pi+1, r);
    }
}

int main() {
    int arr[] = {5, 4, 3, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    quicksort(arr, 0, n-1);
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}

// Use cases of quick sort: large array, array with large values.
// Quick sort is not a stable sort. Why? Because it swaps the elements even if they are equal.
// Quick sort is not adaptive. Why? Because it takes O(n^2) time when the array is sorted in reverse order.