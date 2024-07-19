#include <iostream>

using namespace std;

void towerOfHanaoi(int n, string src, string help, string des){
    //base case
    if(n == 1){
        cout << "transfered disk: " << n <<" from " << src << " to " << des << endl;
        return;
    }    

    towerOfHanaoi(n-1, src, des, help);
    cout << "transfered disk: " << n <<" from " << src << " to " << des << endl;

    towerOfHanaoi(n-1, help, src, des);
}

int main() {
    int n = 3;
    towerOfHanaoi(n, "s", "h", "d");

    return 0;
}