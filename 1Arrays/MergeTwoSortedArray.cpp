#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices, int n) {
    //using Dynamic Programming
    vector<vector<int>> dp(n, vector<int>(2));

    dp[0][0] = -prices[0];
    dp[0][1] = 0;
    for(int i = 0; i < n; i++){
        dp[i][0] = max(dp[i-1][0],  -prices[i]);
        dp[i][1] = max(dp[i-1][1], dp[i-1][0] + prices[i]);
    }
    return max(dp[n-1][0], dp[n-1][1]);
}

int main() {

    vector<int> prices{7,1,5,3,6,4};
    int n = prices.size();
    cout << maxProfit(prices, n) << endl;

  return 0;

}