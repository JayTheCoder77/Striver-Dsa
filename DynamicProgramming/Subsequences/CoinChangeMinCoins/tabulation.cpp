class Solution {
public:
    // slight change in infinite supply version of 
    // pick and not pick we actually stay at the same index even if we decide to pick
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp (coins.size() , vector<int> (amount + 1 , 0));
        for(int j = 0 ; j < amount + 1 ; j++){
            if(j % coins[0] == 0) dp[0][j] = j / coins[0];
            else dp[0][j] = 1e9;
        }
        for(int i = 1 ; i < coins.size() ; i++){    
            for(int j = 0 ; j < amount + 1 ; j++){
                int notTake = 0 + dp[i - 1][j];
                int take = INT_MAX;
                if(coins[i] <= j) take = 1 + dp[i][j - coins[i]]; 
                dp[i][j] = min(take , notTake);
            }
        }
        int ans = dp[coins.size() - 1][amount];
        if(ans >= 1e9) return -1;
        return ans;
    }
};