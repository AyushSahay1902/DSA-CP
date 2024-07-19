// Sort the array using selection sort algorithm
// Time Complexity: O(n^2)
// Auxiliary Space: O(1)

#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) {
    for(int i=0; i<n-1; i++) {
    int min = i;
        for(int j=i+1; j<n; j++) {
            if(arr[j] < arr[min]) {
                min = j;
            }
        }
        swap(arr[i], arr[min]);   
    }
}

int main() {
    int arr[] = {5, 4, 3, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr, n);
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
//Use cases of selection sort: small array, array with small values.
//Selection sort is not a stable sort. Why? Because it swaps the elements even if they are equal.