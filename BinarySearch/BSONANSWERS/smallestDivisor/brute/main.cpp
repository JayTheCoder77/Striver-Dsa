#include <bits/stdc++.h>
int smallestDivisor(vector<int>& arr, int limit)
{
	// Write your code here.
	int n = arr.size();
	int maxI = INT_MIN;
	for(int i = 0 ; i < n ; i++){ 	// o(n)
		maxI = max(maxI,arr[i]);
	}
	for(int i = 1 ; i <= maxI ; i++){
		int total = 0;	// o(n * maxI)
		for(int j = 0 ;j < n ; j++){
			total += ceil((double)arr[j] / i);
		}
		if(total <= limit) return i;
	}
	return -1;
}

// o(n) + o(n * maxI)