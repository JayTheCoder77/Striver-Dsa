class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // floyd warshall - 1. create adj matrix
        vector<vector<int>> matrix (n , vector<int>(n , 1e9));
        for(auto &e : edges){
            int u = e[0] , v = e[1] , wt = e[2];
            matrix[u][v] = wt;
            matrix[v][u] = wt;
        }

        // main
        for(int i = 0 ; i < n ; i++) matrix[i][i] = 0;

        for(int k = 0 ; k <= n - 1 ; k++){
            for(int i = 0 ; i < n ; i++){
                for(int j = 0 ; j < n ; j++){
                    if(matrix[i][k] == 1e9 || matrix[k][j] == 1e9) continue;
                    matrix[i][j] = min(matrix[i][j] , matrix[i][k] + matrix[k][j]);
                }
            }
        }

        // finding the city
        int cntCity = n;
        int cityNo = -1;

        for(int city = 0 ; city < n ; city++){
            int cnt = 0;
            for(int adjCity = 0 ; adjCity < n ; adjCity++){
                if(matrix[city][adjCity] <= distanceThreshold) cnt++;
            }
            if(cnt <= cntCity){
                cntCity = cnt;
                cityNo = city;
            }
        }
        return cityNo;
    }
};