#include <bits/stdc++.h> 
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// right - left
	vector<int> prev (maxWeight + 1, 0);
	for(int w = weight[0]; w <= maxWeight; w++){
		prev[w] = value[0];
	}

	for(int i = 1 ; i < n ; i++){
		for(int j = maxWeight ; j >= 0 ; j--){
			int notTake = prev[j];
			int take = INT_MIN;
			if(weight[i] <= j) take = value[i] + prev[j - weight[i]];
			prev[j] = max(take , notTake);
		}	
	}
	return prev[maxWeight];
}