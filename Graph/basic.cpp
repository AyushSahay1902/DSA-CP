// #include <bits/stdc++.h>
// using namespace std;


// class Graph {

//     public:
//     unordered_map<int, list<int>> adj;
//     void addEdge(int u, int v, bool direction){
//         adj[u].push_back(v);
//         if(!direction){
//             adj[v].push_back(u);
//         }
//     }

//     void printAdj() {
//         for(auto it : adj){
//             cout << it.first << "->";
//             for(int j : it.second){
//                 cout << j << ", ";
//             }
//             cout << endl;
//         }
//     }
// };

// int main() {
//     int n, m;
//     cout << "Enter the no. of edges: "<<endl;
//     cin >> n;

//     cout << "Enter the n0. of vertex> " << endl;
//     cin >> m;

//     Graph g;

//     for(int i = 0; i<m; i++){
//         int u, v;
//         cin >> u >> v;
//         g.addEdge(u, v, false);
//     }

//     g.printAdj();


//  return 0;   
// }

#include <bits/stdc++.h>
using namespace std;

class Graph{
    public: 

    vector<vector<int>> adj;
    int numVert;

    Graph(int vertices){
        numVert = vertices;
        adj.resize(numVert, vector<int>(vertices, 0));
    }

    //Add an edge
    void addEdge(int u, int v, bool direction){
        // adj.[u].push_back(v);
        adj[u][v] = 1;
        if(!direction){
            adj[v][u] = 1;
        }
    }

    void printAdj(){
        for(int i = 0; i<numVert; i++){
            for(int j = 0; j < numVert; j++){
                cout <<adj[i][j] << " ";
            }
        }
    }
};

int main() {

    int n, m;
    cout << "Enter the no. of edges: " << endl;
    cin >> n;

    cout << "Enter the no. of vertices: " << endl;
    cin >> m;

    Graph g;
    for(int i = 0; i<n; i++){
        int u, v;
        cout << "Enter (u, v): " << " ";
        cin >> u >> v;
        g.addEdge(u, v, false);
    }

    printAdj();
    
}return 0