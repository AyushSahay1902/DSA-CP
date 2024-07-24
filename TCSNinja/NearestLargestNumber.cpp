/*
Nearest larger number
Problem Statement:-
Compute the nearest larger number by interchanging its digits updated.Given 2 numbers a and b find the smallest number greater than b by interchanging the digits of a and if not possible print -1.
Input
2 numbers a and b, separated by space.
Output
A single number greater than b.If not possible, print -1
Constraints
1 <= a,b <= 10000000
Sample Input
459
500
Sample Output
549
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    
    int a, b;
    cin >> a >> b;
    string str = to_string(a);
    sort(str.begin(), str.end());
    do {
        int num = stoi(str);
        if (num > b) {
            cout << num << endl;
            return 0;
        }
    } while (next_permutation(str.begin(), str.end()));
    cout << -1 << endl;


    return 0;
}