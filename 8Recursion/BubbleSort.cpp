#include <iostream>
using namespace std;

void SortArray(int arr[], int n){

    if( n <= 1) return ;

    SortArray(arr, n-1);

    int last = arr[n-1];
    int j = n-2;
    while(j >= 0 && arr[j] > last)
    {
        arr[j+1] = arr[j];
        j--;
    }
    arr[j+1] = last;
    
}


int main(){
    int arr[5] = {4,5,3,7,9};

    SortArray(arr, 5);

    for(int i=0; i<5; i++){
        cout << arr[i] << " ";
    }

    return 0;
}