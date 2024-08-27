#include <bits/stdc++.h>
using namespace std;

void fnc(int n, int open, int close, vector<string> &res, string str) {
    if(str.size() == 2*n) {
        res.push_back(str);
        return;
    }

    if(open < n) {
        fnc(n, open+1, close, res, str+"(");
    }
    if(close < open) {
        fnc(n, open, close+1, res, str+")");
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> res;

    fnc(n, 0, 0, res, "");
    return res;
}

int main() {
    
        int n = 3;
        vector<string> res = generateParenthesis(n);
        for(auto x: res) {
            cout << x << endl;
        }


  return 0;

}