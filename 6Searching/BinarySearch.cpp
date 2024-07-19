// Binary search algorithm implementation work on monotonous sequence.
// Time complexity: O(logn)
// Space complexity: O(1)

#include<iostream>
using namespace std;

int main(){
    int n, key;
    cin>>n;
    int a[n];
    cout<<"Enter the array elements: ";
    for(int i=0; i<n; i++) cin>>a[i];
    cout<<"Enter the key: ";
    cin>>key;
    int s=0, e=n-1, mid;
    while(s<=e){
        mid = (s+e)/2;
        if(a[mid]==key){
            cout<<"Found at index "<<mid<<endl;
            break;
        }
        else if(a[mid]>key) e = mid-1;
        else s = mid+1;
    }
    if(s>e) cout<<"Not found"<<endl;
    return 0;
}