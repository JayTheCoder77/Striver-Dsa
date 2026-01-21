#include <bits/stdc++.h> 
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<int> prev (maxWeight + 1, 0) , cur (maxWeight + 1, 0);
	for(int w = weight[0]; w <= maxWeight; w++){
		prev[w] = value[0];
	}

	for(int i = 1 ; i < n ; i++){
		for(int j = 0 ; j <= maxWeight ; j++){
			int notTake = prev[j];
			int take = INT_MIN;
			if(weight[i] <= j) take = value[i] + prev[j - weight[i]];
			cur[j] = max(take , notTake);
		}
		prev = cur;
	}
	return prev[maxWeight];
}