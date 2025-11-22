#include <bits/stdc++.h> 
int f(int i , int j , vector<vector<int>>& triangle, int n , vector<vector<int>> &dp){
	if(i == n-1) return triangle[n-1][j];
	if(dp[i][j] !=  -1) return dp[i][j];
	int down = 0  , downright = 0;

	down = triangle[i][j] + f(i+1 , j , triangle , n , dp);
	downright = triangle[i][j] + f(i+1 , j+1 , triangle , n , dp);

	return dp[i][j] = min(down , downright);

}
int minimumPathSum(vector<vector<int>>& triangle, int n){
	vector<vector<int>> dp(n , vector<int>(n , -1));
	return f(0 , 0 ,triangle, n , dp);
}

tc = o(n * n)
sc = o(n * n) + o(n)