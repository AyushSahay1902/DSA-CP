#include<iostream>
using namespace std;

int main() {
    int n = 5;
    for(int i=1; i<=n; i++){
        for(int j=n-1; j>=i; j--){
            cout << " ";
        }
        int count = 1;
        for(int j=1; j<=i; j++){
            cout << count << " ";
            count = count * (i-j)/ j;
        }
        cout << endl;
    }
}