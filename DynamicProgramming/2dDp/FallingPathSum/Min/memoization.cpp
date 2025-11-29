#include <bits/stdc++.h> 
int f(vector<vector<int>> &dp , vector<vector<int>> &matrix , int i , int j , int n){
    if(j < 0 || j >= n) return 1e8;
    if(i == 0) return matrix[0][j];
    if(dp[i][j] != -1) return dp[i][j];
    int s = matrix[i][j] + f(dp , matrix , i-1 , j , n);
    int ld = matrix[i][j] + f(dp , matrix , i-1 , j-1 , n);
    int rd = matrix[i][j] + f(dp , matrix , i-1 , j+1 , n);

    return dp[i][j] = min(s , min(ld , rd));
}
int minFallingPathSum(vector<vector<int>> &matrix, int n) {
    int mini = 1e8;
    vector<vector<int>> dp(n , vector<int>(n , -1));
    for(int j = 0 ; j < n ; j++){
        mini = min(mini ,  f(dp , matrix , n-1 , j , n));
    }
    return mini;
}