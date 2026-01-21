class Solution {
  public:
    int knapSack(vector<int>& profit, vector<int>& weight, int w) {
        int n = weight.size();
        vector<vector<int>> dp(n , vector<int> (w + 1 , -1));
        
        for(int i = 0 ; i <= w ; i++){
            dp[0][i] = (i / weight[0]) * profit[0]; 
        }
        
        for(int i = 1 ; i < n ; i++){
            for(int j = 0 ; j <= w ; j++){
                int notTake = dp[i - 1][j];
                int take = -1e9;
                if(weight[i] <= j) take = profit[i] + dp[i][j - weight[i]];
                dp[i][j] = max(take , notTake);
            }
        }
        return dp[n-1][w];
    }
};


tc = o(n * wt)
sc = o(n * wt)