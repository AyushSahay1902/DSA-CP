#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin >> n >> m;
    int a[4] [3];
    for(int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin>> a[i][j];

        }
    }
    for(int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cout<<  a[i][j] << " ";
            
        }
        cout << endl;
    }

     
}
    

