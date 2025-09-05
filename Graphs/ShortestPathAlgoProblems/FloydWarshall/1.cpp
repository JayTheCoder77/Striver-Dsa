void floydWarshall(vector<vector<int>> &matrix) {
        int n = matrix.size();
        const int INF = 1e8;

        // convert -1 to INF
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(matrix[i][j] == -1) matrix[i][j] = INF;
                if(i == j) matrix[i][j] = 0;
            }
        }
        
        // main algo
        for(int k = 0 ; k < n ; k++){
            for(int i = 0 ; i < n ; i++){
                for(int j = 0 ; j < n ; j++){
                    if (matrix[i][k] != INF && matrix[k][j] != INF) {
                        matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                    }
                }
            }
        }
        
        // convert INF back to -1
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(matrix[i][j] == INF) matrix[i][j] = -1;
                if(i == j) matrix[i][j] = 0;
            }
}