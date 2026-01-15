class Solution {
public:
    // slight change in infinite supply version of 
    // pick and not pick we actually stay at the same index even if we decide to pick
    int f(int ind , vector<int>& coins, int amount , vector<vector<int>> &dp){

        if(ind == 0){
            if(amount % coins[ind] == 0) return amount / coins[ind];
            else return 1e9;
        }
        
        if(dp[ind][amount] != -1) return dp[ind][amount];

        int notTake = 0 + f(ind - 1 , coins , amount , dp);
        int take = INT_MAX;
        if(coins[ind] <= amount) take = 1 + f(ind , coins , amount - coins[ind] , dp);

        return dp[ind][amount] = min(take , notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp (coins.size() , vector<int> (amount + 1 , -1));
        int ans = f(coins.size() - 1 , coins , amount , dp);
        return (ans >= 1e9) ? -1 : ans;
    }
};

tc = o(n * target)
sc = o(n * target) + o(target)