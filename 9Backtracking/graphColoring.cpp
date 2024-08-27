#include <bits/stdc++.h>
using namespace std;

bool isSafetoAssign(int i, int j, vector<vector<bool>>& graph, vector<int>& color, int N) {
    // Check if i can be assigned to j
    for (int k = 0; k < N; k++) {
        if (graph[i][k] && color[k] == j) return false;
    }
    return true;
}

bool fnc(vector<vector<bool>>& graph, vector<int>& color, int m, int N, int i) {
    if (i == N) return true;
    for (int j = 0; j < m; j++) {
        if (isSafetoAssign(i, j, graph, color, N)) {
            color[i] = j;
            if (fnc(graph, color, m, N, i + 1)) return true;
            color[i] = -1;
        }
    }
    return false;
}

bool gC(vector<vector<bool>>& graph, int m, int N) {
    vector<int> color(N, -1);
    // Colors from 0 to m
    return fnc(graph, color, m, N, 0);
}

int main() {
    int n = 4;
    int m = 3;
    int e = 5;

    vector<pair<int, int>> Edges = {{1, 2}, {2, 3}, {3, 4}, {4, 1}, {1, 3}};
    vector<vector<bool>> graph(n, vector<bool>(n, false));

    for (auto edge : Edges) {
        graph[edge.first - 1][edge.second - 1] = true;
        graph[edge.second - 1][edge.first - 1] = true;
    }

    bool res = gC(graph, m, n);
    if (res) {
        cout << "1" << endl;
    } else {
        cout << "0" << endl;
    }

    return 0;
}
