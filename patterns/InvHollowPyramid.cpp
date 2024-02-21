#include<iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the no of rows: ";
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<i; j++){
            cout << " ";
        }
        for(int j = n; j>=i; j--){
            if(i==1|| j==i || j==n){
                cout << "* ";
            }else{
                cout << "  ";
            }
        }
        cout << endl;
    }
}