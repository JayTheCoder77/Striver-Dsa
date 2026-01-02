class Solution {
  public:
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
};