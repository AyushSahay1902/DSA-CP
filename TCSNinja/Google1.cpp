// #include <iostream>
// #include <string>

// using namespace std;

// int firstOccurrence(const string& A, const string& B) {
//     int n = A.length();
//     int m = B.length();

//     // Return -1 if B is longer than A
//     if (m > n) {
//         return -1;
//     }

//     for (int i = 0; i <= n - m; i++) {
//         int diff = 0;
//         for (int j = 0; j < m; j++) {
//             if (A[i + j] != B[j]) {
//                 diff++;
//             }
//             if (diff > 1) {
//                 break;
//             }
//         }
//         if (diff <= 1) {
//             return i;  // Return 0-based index
//         }
//     }

//     return -1;
// }

// int main() {
//     int T;
//     cin >> T;
//     for (int i = 0; i < T; i++) {
//         string A, B;
//         cin >> A >> B;
//         int result = firstOccurrence(A, B);
//         cout << result << endl;
//     }

//     return 0;
// }


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long solve(int N, int K, vector<int>& A) {
    vector<long long> prefixOR(N + 1, 0);
    
    // Calculate prefix OR array
    for (int i = 0; i < N; ++i) {
        prefixOR[i + 1] = prefixOR[i] | A[i];
    }
    
    long long maxF = 0;
    
    // Calculate F(B) for all possible subsequences
    for (int i = K - 1; i < N; ++i) {
        for (int j = i; j < N; ++j) {
            long long orPart = prefixOR[j + 1] ^ prefixOR[i - K + 1];
            long long xorPart = A[i] ^ A[j];
            maxF = max(maxF, orPart + xorPart);
        }
    }
    
    return maxF;
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int N, K;
        cin >> N >> K;
        
        vector<int> A(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }
        
        cout << solve(N, K, A) << endl;
    }
    
    return 0;
}