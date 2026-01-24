class Solution {
  public:
    int f(int ind , int len , vector<int> &price , vector<vector<int>> &dp){
    	// base
    	if(ind == 0){
    		return len * price[0];
    	}
    
        if(dp[ind][len] != -1) return dp[ind][len];
    
    	int notTake = f(ind - 1, len , price , dp);
    	int take = INT_MIN;
    	int rodLen = ind + 1;
    	if(rodLen <= len) take = price[ind] + f(ind , len - rodLen , price , dp);
    
    	return dp[ind][len] = max(take , notTake);
    }
    int cutRod(vector<int> &price) {
        int n = price.size();
        vector<vector<int>> dp(n , vector<int>  (n+1 , -1));
    	return f(n-1 , n , price , dp);
    }
};


tc = o(n * n)
sc = o(n * n) + o(n)