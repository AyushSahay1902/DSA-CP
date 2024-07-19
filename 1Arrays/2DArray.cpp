#include<iostream>
#include<Array>
#include<vector>
using namespace std;

// bool isPresent(int arr[][4], int target, int row, int col){
//     for(int i=0; i<3; i++){
//         for(int j=0; j<4; j++){
//             if(arr[i][j] == target){
//                 return true;
//             }
//         }
//     }
//     return false;
// }

vector<int> SpiralPrint(vector<vector<int>>& matrix) {
    vector<int> ans;
    int row = matrix.size(), col = matrix[0].size();
    int count=0, total = row*col;
    int startingRow = 0, endingRow = row -1;
    int startingCol = 0, endingCol = col -1;
    while(count < total){
        for(int i = startingCol; count < total && i<=endingCol; i++){
            ans.push_back(matrix[startingRow][i]);
            count++;
        }
        startingRow++;
        //print ending col
        for(int i = startingRow; count < total && i<=endingRow; i++){
            ans.push_back(matrix[i][endingCol]);
            count++;
        }
        endingCol--;
        //print ending Row
        for(int i = endingCol; count < total && i>= startingCol; i--){
            ans.push_back(matrix[endingRow][i]);
            count++;
        }
        endingRow++;
        //print startingCol
        for(int i = endingRow; count < total && i<=startingRow; i--){
            ans.push_back(matrix[i][startingCol]);
            count++;
        }
        startingCol++;

    }
    return ans;
}

vector<int> WavePrint(vector<vector<int>> arr, int row, int col) {
    vector<int> ans;
    // col index odd -> bottom to top
    for (col = 0; col < 4; col++) {
        if (col % 2 == 1) {
            // odd
            for (int row = 2; row >= 0; row--) {
                ans.push_back(arr[row][col]);
            }
        } else {
            // even
            for (int row = 0; row < 3; row++) {
                ans.push_back(arr[row][col]);
            }
        }
    }
    return ans;
}
int 90DegreeRotate(int[][] matrix, int row, int col){
    int ans[][];
    for(int i=0; i<row; i++){
        for(int j=0 j<col; j++){
            ans[j][col-1-j] = matrix[i][j];
        }
    }
    //print the matrix
}
// static int RowSum(int arr[][4], int i){
//     int sum = 0;
//     for(int col =0; col<4; col++){
//         sum += arr[i][col];
//     }
//     return sum;
// }
// static int ColSum(int arr[][4], int j){
//     int sum = 0;
//     for(int row=0; row<3; row++){
//         sum += arr[row][j];
//     }
//     return sum;
// }

int main(){
    // cout<<"Enter the array:"<<endl;
    // int arr[3][4];
    // for(int i=0; i<3; i++){
    //     for(int j=0; j<4; j++){
    //         cin>>arr[i][j];
    //     }
    // }
    // //Search manually
    // cout<<"Enter the element to search"<<endl;
    // int target;
    // cin>> target;
    // if(isPresent(arr,target,3,4)){
    //     cout<<"Element Found!"<<endl;
    // }else{
    //     cout<<"Element not found!"<<endl;
    // }

    // //Row wise sum
    // for(int i=0; i<3; i++){
    //     cout<<"Sum of row"<<i<<"is:"<<RowSum(arr,i)<<endl;
    // }
    //Wave Print
    vector<vector<int>> arr = {{1, 2, 3, 4},
                                {5, 6, 7, 8},
                                {9, 10, 11, 12}};

    vector<int> result = SpiralPrint(arr);

    // Printing the result
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;


    //print
    // for(int i=0; i<3; i++){
    //     for(int j=0; j<4; j++){
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    return 0;

}