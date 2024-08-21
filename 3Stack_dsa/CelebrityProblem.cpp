#include <bits/stdc++.h>
using namespace std;

// This function returns true if a knows b
bool knows(vector<vector<int>> &mat, int a, int b) {
    return mat[a][b] == 1;
}

int Celebrity(vector<vector<int>> &mat, int n) {
    stack<int> s;

    // Step 1: Push all the persons into the stack
    for(int i = 0; i < n; i++) {
        s.push(i);
    }

    // Step 2: Get two persons and compare them
    while(s.size() > 1) {
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();

        // If a knows b, then a can't be a celebrity, but b might be
        if(knows(mat, a, b)) {
            s.push(b);
        } else {
            // If a doesn't know b, then b can't be a celebrity, but a might be
            s.push(a);
        }
    }

    // Step 3: Single candidate left in the stack, check if it is a celebrity
    int c = s.top();
    s.pop();

    // Step 4: Check if the candidate is actually a celebrity
    for(int i = 0; i < n; i++) {
        // A celebrity does not know anyone, but everyone knows the celebrity
        if(i != c && (knows(mat, c, i) || !knows(mat, i, c))) {
            return -1;
        }
    }
    return c;
}

int main() {
    vector<vector<int>> mat = {
        {0, 1, 0},
        {0, 0, 0},
        {0, 1, 0}
    };

    int n = mat.size();
    int result = Celebrity(mat, n);

    if(result == -1) {
        cout << "There is no celebrity." << endl;
    } else {
        cout << "Celebrity is person " << result << endl;
    }

    return 0;
}
