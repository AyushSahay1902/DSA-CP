#include<iostream>
using namespace std;

int main() {
    int n = 4;
    for(int i=1; i<=n; i++){
        cout << " ";
        for(int j=1; j<i; j++){
            cout << " ";
        }
        for(int j=n; j>=i; j--){
            if(j==n || j==i || i==1){
                cout << "* ";
            }else{
                cout << "  ";
            }
        }
        cout << endl;
    }
    for(int i=1; i<=n-1; i++){
        for(int j=n-1; j>i; j--){
            cout << " ";
        }
        for(int j=1; j<=i+1; j++){
            if(j==1 || i==n-1 || j==i+1){
                cout << " *";
            }else{
                cout << "  ";
            }
        }
        cout << endl;
    }
}