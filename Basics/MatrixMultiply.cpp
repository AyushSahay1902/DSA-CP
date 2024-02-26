//Write a program to find the strongly connected components in a digraph.

#include <iostream>

using namespace std;

int m[100][100];
int s[100][100];

// Function to find the minimum number of scalar multiplications
void matrixChainOrder(int p[], int n) {
    for (int i = 1; i <= n; i++) {
        m[i][i] = 0;
    }

    for (int l = 2; l <= n; l++) {
        for (int i = 1; i <= n - l + 1; i++) {
            int j = i + l - 1;
            int m[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}

// Function to print the optimal parentheses
void printOptimalParens(int s[][100], int i, int j) {
    if (i == j) {
        cout << "A";
    } else {
        cout << "(";
        printOptimalParens(s, i, s[i][j]);
        cout << ")";
        printOptimalParens(s, s[i][j] + 1, j);
    }
}

int main() {
    int p[] = {4, 10, 3, 5};
    int n = sizeof(p) / sizeof(p[0]) - 1;

    matrixChainOrder(p, n);

    cout << "Minimum number of scalar multiplications: " << m[1][n] << endl;
    cout << "Optimal parentheses: ";
    printOptimalParens(s, 1, n);

    return 0;
}
