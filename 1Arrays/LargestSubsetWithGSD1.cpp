#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int trailingZeros(int n){
    
    int cnt = 0;
    while(n/5 > 0){
        cnt += (n/5);
        n /= 5;
    }
    return cnt;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
        
    int ans = trailingZeros(n);
    cout << ans;
    return 0;
}
