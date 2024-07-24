/*
Find the Nth term
You need to find the Nth term in a mixed series where the odd terms form one geometric series and the even terms
form another geometric series.
the series 1, 1, 2, 3, 4, 9, 8, 27, 16, 81, 32, 243, 64, 729, 128, 2187, ...

*/

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int N;
    cin >> N;

    if(N < 0 || N > 30) {
        return 0;
    }

    if(N % 2 == 0){
        //even
        cout << pow(3, N/2 - 1);
    }else{
        //odd
        cout << pow(2, N/2);
    }

    return 0;

}