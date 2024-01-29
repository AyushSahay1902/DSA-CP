// Mergesort implementation
// Time Complexity: O(nlogn)
// Auxiliary Space: O(n)

#include<iostream>
using namespace std;


void Merge(int arr[], int l, int mid, int r) {
    int n1 = mid-l+1;
    int n2 = r-mid;
    int a[n1];
    int b[n2];
    for(int i=0; i<n1; i++) {
        a[i] = arr[l+i];
    }
    for(int i=0; i<n2; i++) {
        b[i] = arr[mid+1+i];
    }
    int i=0, j=0, k=l;
    while(i<n1 && j<n2) {
        if(a[i] < b[j]) {
            arr[k] = a[i];
            i++;
            k++;
        }
        else {
            arr[k] = b[j];
            j++;
            k++;
        }
    }
    while(i<n1) {
        arr[k] = a[i];
        i++;
        k++;
    }
    while(j<n2) {
        arr[k] = b[j];
        j++;
        k++;
    }
}

void Mergesort(int arr[], int l, int r) {
    int mid = (l+r)/2 ;
    if(l<r){
        Mergesort(arr, l, mid);
        Mergesort(arr, mid+1, r);
        Merge(arr, l, mid, r);
    }
}

int main() {
    int arr[] = {5, 4, 3, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    Mergesort(arr, 0, n-1);
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
// Use cases of merge sort: large array, array with large values.
// Merge sort is a stable sort. Why? Because it swaps the elements only if they are not equal.
// Merge sort is not adaptive. Why? Because it takes O(nlogn) time even if the array is already sorted.
// Merge sort is not in-place. Why? Because it takes O(n) auxiliary space.
// Merge sort is a divide and conquer algorithm. Why? Because it divides the array into two halves and then merges them.
// Merge sort is recursive. Why? Because it calls itself recursively.
