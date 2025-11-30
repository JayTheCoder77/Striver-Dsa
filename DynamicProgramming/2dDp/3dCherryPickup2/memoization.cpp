#include <bits/stdc++.h> 
int f(int i , int j1 , int j2 , vector<vector<int>> &grid , vector<vector<vector<int>>> &dp){
    int r = grid.size() , c = grid[0].size();
    int maxi = -1e8;
    if(j1 < 0 || j1 > c-1 || j2 < 0 || j2 > c-1) return -1e8;
    if(i == r -1 ){
        if(j1 == j2) return grid[i][j1];
        else return grid[i][j1] + grid[i][j2];
    }
    if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
    int dj[] = {-1 , 0 , 1};
    for(int dj1 = -1 ; dj1 <= 1 ; dj1++){
        for(int dj2 = -1 ; dj2 <= 1 ; dj2++){
            if(j1 == j2) maxi = max(maxi , grid[i][j1] + f(i+1 , j1 + dj1 , j2 + dj2 , grid , dp));
            else maxi = max(maxi , grid[i][j1] + grid[i][j2] + f(i+1 , j1 + dj1 , j2 + dj2 , grid , dp));
        }
    }
    return dp[i][j1][j2] = maxi;
}
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    // r x c x c = 3d - dp 
    vector<vector<vector<int>>> dp(r , vector<vector<int>> (c , vector<int> (c , -1)));
    return f(0,0,c-1,grid,dp);
}

tc = o(r x c x c) * 9
sc = o(r x c x c) + o(r)