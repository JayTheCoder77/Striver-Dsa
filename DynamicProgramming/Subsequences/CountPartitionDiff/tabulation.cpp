// s1 - s2 = D  where s1 >= s2
// but s1 = total - s2
// total - s2 - s2 = d
// s2 = ( total - d ) / 2
// boiled down to count subsets with this formula instead of s1 - s2 = d
// now just apply the concept of count subsets with sum = k

#include <bits/stdc++.h> 
int perfectSum(vector<int>& arr, int k) {
    	int n = arr.size();
    	vector<vector<int>> dp (n , vector<int> (k + 1 , 0));
        const int MOD = 1e9 + 7;
    	// base case for index 0
        if (arr[0] == 0) {
            dp[0][0] = 2;
        } else {
            dp[0][0] = 1;
            if (arr[0] <= k)
                dp[0][arr[0]] = 1;
        }
    
    	for(int i = 1 ; i < n ; i++){ // ind
    		for(int j = 0 ; j <= k ; j++){ // sum
    			// not pick
    			int notPick = dp[i - 1][j];
    			// pick
    			int pick = 0;
    			if(arr[i] <= j) pick = dp[i - 1][j - arr[i]];
    
    			dp[i][j] = (notPick + pick) % MOD;
    		}
    	}
    
    	return dp[n-1][k];
    }

int countPartitions(int n, int d, vector<int> &arr) {
	int totSum = 0;
    for(auto &it : arr) totSum += it;
    if((totSum - d) < 0 || ((totSum - d) % 2) != 0) return false;
    return perfectSum(arr , (totSum - d) / 2);
}




