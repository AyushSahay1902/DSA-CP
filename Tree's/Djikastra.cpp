#include <bits/stdc++.h>
using namespace std;

#define infinity 999;
int V, src, cost[100][100];
bool visited[100] = V;

int parent[100]

void init() {
    for(int i = 0; i < V; i++){
        parent[i] = i;
        dist[i] = infinity;
    }
    dist[src] = 0;
}
int getNearest(){
    int minVal = infinity;
    int minNode = 0;

    for(int i = 0; i < V; i++){
        if(!visited[i] && dist[i] < minVal){
            minVal = dist[i];
            minNode = i;
        }
    }
    return minNode;
}

void digiAlgo() {
    for(int i = 0; i< V; i++){
        int nearest = getNearest();
        viseted[nearest] = true;

        for(int adj = 0; adj < V; adj++){
            if(cost[nearest][adj] != infinity && dist[adj] < dist[nearest] + cost[nearest][adj]){
                dist[adj] = dist[nearest] + cost[nearest][adj];
                parent[adj] = nearest;
            }
        }
    }
}

int main() {    
    cin >> V;
    for(int i = 0; i<V; i++){
        for(int j = 0; j < V; j++){
            cin >> cost[i][j];
        }
    }

    cin >> src;

  return 0;

}