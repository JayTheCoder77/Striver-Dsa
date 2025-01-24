#include <bits/stdc++.h>
vector<int> findPeakGrid(vector<vector<int>> &g){
    // Write your code here.    
    // multiple peak elements return any one
    int n = g.size();
    int m = g[0].size();
    int up = 0 , down = 0 , left = 0 , right = 0;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            //boundaries
            //up
            if(i > 0) up = g[i-1][j];
            else up = INT_MIN;

            // down
            if(i < n - 1) down = g[i+1][j];
            else down = INT_MIN;

            //left
            if(j > 0) left = g[i][j-1];
            else left = INT_MIN;

            // right
            if(j < m - 1) right = g[i][j+1];
            else right = INT_MIN;

            if(g[i][j] >= up && g[i][j] >= down &&
                g[i][j] >= left && g[i][j] >= right) return {i,j};

        }
    }
    return {-1,-1};
}

tc = o(n * m * 4) 4 -> checking up down left right