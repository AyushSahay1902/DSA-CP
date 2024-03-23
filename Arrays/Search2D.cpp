#include<iostream>
#include<vector>
#include<algorithm> // for reverse
using namespace std;

// Transpose the matrix and then reverse
void rotateMatrix(vector<vector<int>>& mat) {
    int n = mat.size();
    // Transpose
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            swap(mat[i][j], mat[j][i]);
        }
    }
    // Reverse every row
    for(int i = 0; i < n; i++) {
        reverse(mat[i].begin(), mat[i].end());
    }
}

int main() {
    vector<vector<int>> arr = {{1, 2, 3, 4},
                                {5, 6, 7, 8},
                                {9, 10, 11, 12}};

    rotateMatrix(arr);

    // Printing the result
    for(int i = 0; i < arr.size(); i++) {
        for(int j = 0; j < arr[i].size(); j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
