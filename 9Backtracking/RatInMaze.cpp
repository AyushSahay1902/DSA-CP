#include<iostream>
using namespace std;

bool isSafe(int **arr, int x, int y, int n) {
    // Check if x and y are within bounds and the cell is not blocked (1)
    return (x >= 0 && y >= 0 && x < n && y < n && arr[x][y] == 0);
}

bool ratInMaze(int **arr, int x, int y, int n, int **solArr) {
    // Base condition
    if (x == n - 1 && y == n - 1) {
        solArr[x][y] = 1;
        return true;
    }

    if (isSafe(arr, x, y, n)) {
        solArr[x][y] = 1;

        // Move down
        if (ratInMaze(arr, x + 1, y, n, solArr)) {
            return true;
        }

        // Move right
        if (ratInMaze(arr, x, y + 1, n, solArr)) {
            return true;
        }

        // Backtrack
        solArr[x][y] = 0;
        return false;
    }
    return false;
}


int main() {
    int n;
    cin >> n;

    int** arr = new int*[n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[n];
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    int** solArr = new int*[n];
    for (int i = 0; i < n; i++) {
        solArr[i] = new int[n];
        for (int j = 0; j < n; j++) {
            solArr[i][j] = 0;
        }
    }

    if (ratInMaze(arr, 0, 0, n, solArr)) {
        cout << "Solution exists:" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << solArr[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "No solution exists." << endl;
    }

    // Deallocate memory
    for (int i = 0; i < n; i++) {
        delete[] arr[i];
        delete[] solArr[i];
    }
    delete[] arr;
    delete[] solArr;

    return 0;
}
// 1 0 1 0 1
// 1 1 1 1 1
// 0 1 0 1 0
// 1 0 0 1 1
// 1 1 1 0 1