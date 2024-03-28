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

bool Search2DMatrix(vector<vector<int>>& mat, int target){
    int row = mat.size();
    int col = mat[0].size();

    int start = 0;
    int end = row*col -1;

    int mid = start + (end - start)/2;
    while(start <= end){
        int ele = mat[mid/col][mid%col];
        if(ele == target){
            return 1;
        }else if(ele < target){
            start = mid+1;
        }else{
            end = mid-1;
        }
        mid = start + (end - start)/2;
    }
}

int main() {
    vector<vector<int>> arr = {{1, 2, 3, 4},
                                {5, 6, 7, 8},
                                {9, 10, 11, 12}};

    if(Search2DMatrix(arr, 11)){
        cout<<"Element Found!"<<endl;
    }else{
        cout<<"Element Not Found!"<<endl;
    }
    
    // Printing the result
    // for(int i = 0; i < arr.size(); i++) {
    //     for(int j = 0; j < arr[i].size(); j++) {
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}
