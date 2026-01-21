// check for changing params - here ind and wt are changing

class Solution {
  public:
    int f(int ind , int wt , vector<int> &weight, vector<int> &value , vector<vector<int>> &dp){
    
    	// if starting from n-1 write base case for 0 and vice versa
    	if(ind == 0){
    		if(weight[0] <= wt) return value[0];
    		else return 0;
    	}
        if(dp[ind][wt] != -1) return dp[ind][wt];
    	int notTake = 0 + f(ind - 1 , wt , weight , value , dp);
    	int take = INT_MIN;
    	if(weight[ind] <= wt) take = value[ind] + f(ind - 1 , wt - weight[ind] , weight , value , dp);
    	return dp[ind][wt] = max(take , notTake);
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = wt.size();
        vector<vector<int>> dp(n , vector<int> (W + 1 , -1));
	    return f(n-1 , W , wt , val , dp);
    }
};

tc = o(n * wt)
sc = o(n * wt) + o(n)