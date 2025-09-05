gfg

class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
        int n = dist.size();
        for(int k = 0 ; k < n ; k++){
            for(int i = 0 ; i < n ; i++){
                for(int j = 0 ; j < n ; j++){
                    if(dist[i][k] != 1e8 && dist[k][j] != 1e8){
                        dist[i][j] = min(dist[i][j] , dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
    }
};


coding ninjas

int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    // adj matrix
    const int INF = 1e9;
    vector<vector<int>> matrix(n+1, vector<int>(n+1 , 1e9));
    for (int i = 0; i <= n; i++) matrix[i][i] = 0;
    for (auto &e : edges) {
        int u = e[0], v = e[1], wt = e[2];
        matrix[u][v] = wt;
    }

    // floyd warshall

    for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if (matrix[i][k] != INF && matrix[k][j] != INF) {
                        matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                    }
                }
            }
    }
    return (matrix[src][dest] == INF ? 1e9 : matrix[src][dest]);;
}

tc = o(N^3)

djikstra doesnt work on negative cycles

sc = o(N^2) matrix in place