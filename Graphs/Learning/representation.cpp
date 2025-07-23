// input of a graph

#include <bits/stdc++.h>
using namespace std;

// n = nodes  , m = edges
// adjacency matrix  , list
// matrix - sc = o(n x n)
// list - sc = o(2 * edges)  in case of directed graph - sc - o(E)


// adj matrix
int main(){
    int n , m;
    cin >> n >> m;
    int adj[n+1][m+1];
    for(int i = 0 ; i < m ; i++){
        int u , v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;

        // for weighted graph - matrix
        adj[u][v] = wt;
        adj[v][u] = wt;
    } 
    return 0;
}

// adj list
int main(){
    int n , m;
    cin >> n >> m;
    vector <int> adj[n+1]; // not a 1d vector look at this line carefully
    // alternative of above is  vector<vector<int>> adj;
    for(int i = 0 ; i < m ; i++){
        int u , v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);

        // for weighted graph store pairs
    }
    return 0;
}


