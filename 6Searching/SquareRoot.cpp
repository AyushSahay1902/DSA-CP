//Find the square root of a number using binary search.
//time complexity: O(logn)
//space complexity: O(1)

#include <iostream>
using namespace std;

long long int squareRoot(int n) {
    int left = 0;
    int right = n;
    long long int mid = left + (right - left) / 2;
    while (left <= right){
        if(mid * mid == n){
            return mid;
        }
        else if(mid * mid < n){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
        mid = left + (right - left) / 2;
    }
    //return mid;
}
int main(){
    int n = 25;
    cout << squareRoot(n);
    return 0;
}
