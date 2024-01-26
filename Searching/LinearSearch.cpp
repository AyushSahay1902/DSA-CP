#include<iostream>
#include<stdio.h>
using namespace std;
int main() {
    int n, kay ;
    cin>>n;
    int a[n];
    cout<<"Enter the array elements: ";
    for(int i=0; i<n; i++) cin>>a[i];
    cout<<"Enter the key: ";
    cin>>kay;
    int i;
    for(i=0; i<n; i++){
        if(a[i]==kay){
            cout<<"Found at index "<<i<<endl;
            break;
        }
    }
    if(i==n) cout<<"Not found"<<endl;
    return 0;
}   