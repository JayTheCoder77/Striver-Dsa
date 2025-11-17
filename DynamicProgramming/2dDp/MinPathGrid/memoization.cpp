#include <bits/stdc++.h> 
int f(vector<vector<int>> &dp , vector<vector<int>> &grid , int i , int j){
    if(i == 0 && j == 0) return grid[0][0];
    if(i < 0 || j < 0) return 1e9;
    if(dp[i][j] != -1) return dp[i][j];

    int up = grid[i][j] + f(dp , grid , i-1 , j);
    int left = grid[i][j] + f(dp , grid , i , j-1);
    return dp[i][j] = min(up,left);
}
int minSumPath(vector<vector<int>> &grid) {
    int n = grid.size() , m = grid[0].size();
    vector<vector<int>> dp(n , vector<int>(m , -1));
    return f(dp , grid , n-1 , m-1);
}