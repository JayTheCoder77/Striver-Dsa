int cutRod(vector<int> &price, int n)
{
	// index , rodLength
	vector<vector<int>> dp(n , vector<int>  (n+1 , 0));
	for(int i = 0 ; i <= n ; i++){
		dp[0][i] = price[0] * i;
	}

	for(int i = 1 ; i < n ; i++){
		for(int j = 0 ; j <= n ; j++){
			int notTake = dp[i - 1][j];
			int take = INT_MIN;
			int rodLen = i + 1;
			if(rodLen <= j) take = price[i] + dp[i][j - rodLen];
			dp[i][j] = max(take , notTake);
		}
	}

	return dp[n-1][n];
}