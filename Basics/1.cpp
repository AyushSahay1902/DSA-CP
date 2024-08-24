// #include <iostream>
// #include <string>
// #include <cstdint>
// using namespace std;

// int main() {
//     //pointers - point to a specific location
//     //references = &
//     //format specifirer
//     /*
//                 Integers 1 byte = 8 bits
//     short int - 16 bits
//     int - 32 bits
//     long int - 64 bits
//     long long int -  64 bits
//     signed int - normal
//     unsigned int - uint_16
//     Hext code - 0x16 -22
//     Binary 0b0001221 = bunary
//     //linkers - 
//     //Qualifiers -  
    
    
//     */
//     int *mypointer;
//     int score = 200;
//     int *myp = &score;



//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

void dfs(int island, vector<int> adj[], bool visited){
    visited[island] = true;
    for(int neighbour : adj[island]){
        if(!visited[neighbour]){
            dfs(neighbour, adj, visited);
        }
    }
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        int island, boat_tours;
        cin >> island >> boat_tours;
        
        vector<int> adj[island + 1];
        bool visited[island + 1];
        memset(visited, false, sizeof(visited));

        for(int i = 0; i < boat_tours; i++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        int count = 0;

        for(int i = 0; i <= island; i++){
            if(!visited[i]){
                dfs(i, adj, visited);
                count++;
            }
        }

        cout << count << endl;
    }
}