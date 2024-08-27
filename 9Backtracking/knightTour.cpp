#include <bits/stdc++.h>
using namespace std;

#define N 8

bool isSafe(int x, int y, int sol[N][N]){
    return (x >=0 && x < N && y >= 0 && y < N && sol[x][y] == -1);
}

int solveKTUtil(int x, int y, int move, int sol[N][N], int xMove[8], int yMove[8]){
    int k, next_x, next_y;
    if(move == N*N){
        return 1;
    }

    for(k = 0; k < 8; k++){
        next_x  = x + xMove[k];
        next_y  = y + yMove[k];
        if(isSafe(next_x, next_y, sol)) {
            sol[next_x][next_y] = move;
            if(solveKTUtil(next_x, next_y, move+1, sol, xMove, yMove) == 1){
                return 1;
            }else{
                sol[next_x][next_y] = -1;
            }
        }
    }
    return 0;
}

void printSol(int sol[N][N])
{
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++)
            cout << " " << setw(2) << sol[x][y] << " ";
        cout << endl;
    }
}

int solveKT() {
    int sol[N][N];
    for(int x = 0; x < N; x++){
        for(int y = 0; y < N; y++){
            sol[x][y] = -1;
        }
    }

    int xMove[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
    int yMove[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

    sol[0][0] = 0;
    if(solveKTUtil(0, 0, 1, sol, xMove, yMove) == 0){
        cout <<  "Solution does not exist!" << endl;
        return 0;
    }
    else{
        printSol(sol);
        return 1;
    }
}



int main() {

    solveKT();
    
  return 0;

}