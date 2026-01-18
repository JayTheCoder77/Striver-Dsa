class Solution {
public:
    int f(int ind , int amount, vector<int>& coins , vector<vector<int>> &dp){
        // base
        if(ind == 0){
            return (amount % coins[0] == 0) ? 1 : 0;
        }
        if (dp[ind][amount] != -1) return dp[ind][amount];
        int notPick = f(ind - 1 , amount , coins , dp);
        int pick = 0;
        if(coins[ind] <= amount) pick = f(ind , amount - coins[ind] , coins , dp);
        
        return dp[ind][amount] = notPick + pick;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp (coins.size() , vector<int> (amount + 1 , -1));
        return f(coins.size() - 1 , amount , coins , dp);
    }
};

tc = o(n * target)
sc = o(n * target) + o(target)