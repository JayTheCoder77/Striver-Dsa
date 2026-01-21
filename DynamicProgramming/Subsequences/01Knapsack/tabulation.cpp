#include <bits/stdc++.h> 
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>> dp (n , vector<int> (maxWeight + 1, 0));
	for(int w = weight[0]; w <= maxWeight; w++){
		dp[0][w] = value[0];
	}

	for(int i = 1 ; i < n ; i++){
		for(int j = 0 ; j <= maxWeight ; j++){
			int notTake = dp[i - 1][j];
			int take = INT_MIN;
			if(weight[i] <= j) take = value[i] + dp[i - 1][j - weight[i]];
			dp[i][j] = max(take , notTake);
		}
	}
	return dp[n-1][maxWeight];
}

