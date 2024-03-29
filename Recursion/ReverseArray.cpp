#include<iostream>
#include<array>
#include<algorithm> 

using namespace std; // Add this line to use cin

void fibonacci(int n, int a, int b){
    if(n == 0) return;
    cout<< a<< " ";
    fibonacci(n-1, b, a+b);
}

bool palindrome(string s, int start,  int end){
    if(start >= end) return true;
    if(s[start] != s[end]) return false;
    return palindrome(s, start+1, end-1);
}

void reverse(int i, int arr[], int n){
    if(i >= n/2) return;
    swap(arr[i], arr[n-i-1]);
    reverse(i+1, arr, n); 
}

int main(){
    int n;
    cin>> n;
    int arr[n];
    for(int i=0; i<n; i++) cin>> arr[i];
    reverse(0, arr, n);
    for(int i=0; i<n; i++) cout<< arr[i]<< " ";
    fibonacci(10, 0, 1);
    cout<<endl;
    return 0;
}