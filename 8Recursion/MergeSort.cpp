#include <iostream>
using namespace std;

void Merge(int *arr, int s, int e){
    int mid = (s+e)/2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    int k = s;
    for(int i=0; i<len1; i++){
        first[i] = arr[k++];
    }
    
    int l = mid+1;
    for(int i=0; i<len1; i++){
        second[i] = arr[l++];
    }
    //Merge 2 sorted array
    int index1 = 0, index2 = 0;
    int mainArrayindex = s;

    while(index1 < len1 && index2 < len2){
        if(first[index1] < second[index2]){
            arr[mainArrayindex++] = first[index1++];
        }else{
            arr[mainArrayindex++] = second[index2++];
        }
    }
    while(index1 < len1){
        arr[mainArrayindex++] = first[index1++];
    }
    while(index2 < len2){
        arr[mainArrayindex++] = second[index2++];
    }
    delete []first;
    delete []first;
}

void MergeSort(int arr[], int s, int e){

    //base case
    if(s >= e){
        return;
    }   
    int mid = s + (e-s)/2; 
    //recursive sort
    MergeSort(arr, s, mid);
    MergeSort(arr, mid+1, e);
    Merge(arr, s, e);
}


int main(){
    int arr[5] = {4,5,3,7,9};
    int n = 5;
    MergeSort(arr, 0, n-1);

    for(int i=0; i<5; i++){
        cout << arr[i] << " ";
    }

    return 0;
}