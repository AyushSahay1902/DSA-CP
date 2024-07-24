#include <iostream>
#include <vector>
using namespace std;

int Maxfilled(const vector<vector<int>>& spaces) {
    int max_filled = 0;
    for (int i = 0; i < spaces.size(); i++) {
        int ones = 0;
        for (int j = 0; j < spaces[i].size(); j++) {
            if (spaces[i][j] == 1) {
                ones++;
            }
        }
        if (ones > max_filled) {
            max_filled = ones;
        }
    }
    return max_filled;
}

int main() {
    int row, col;
    cin >> row;
    cin >> col;

    vector<vector<int>> spaces(row, vector<int>(col));

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> spaces[i][j];
        }
    }

    cout << Maxfilled(spaces) << endl;

    return 0;
}
