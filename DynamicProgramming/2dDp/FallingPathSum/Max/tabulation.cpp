#include <bits/stdc++.h> 

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size() , m = matrix[0].size();
    vector<vector<int>> dp(n , vector<int>(m , 0));
    for(int j = 0 ; j < m ; j++) dp[0][j] = matrix[0][j];
    for(int i = 1 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            int s = -1e8 , ld = -1e8 , rd = -1e8;
            s = matrix[i][j] + dp[i-1][j];
            if(j > 0) ld = matrix[i][j] + dp[i-1][j-1];
            if(j < m-1) rd = matrix[i][j] + dp[i-1][j+1];
            dp[i][j] = max(s , max(ld , rd));
        }
    }
    int maxi = dp[n-1][0];  
    for(int j = 1 ; j < m ; j++) maxi = max(maxi , dp[n-1][j]);
    return maxi;
}

tc = o(n x m) + o(m)
sc = o(n x m)