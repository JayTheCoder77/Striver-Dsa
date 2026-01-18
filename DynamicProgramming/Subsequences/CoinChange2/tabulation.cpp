class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<long long>> dp (coins.size() , vector<long long> (amount + 1 , 0));

        for(int i = 0 ; i <= amount ; i++){
            if(i % coins[0] == 0) dp[0][i] = 1;
        }

        for(int i = 1 ; i < coins.size() ; i++){    
            for(int j = 0 ; j <= amount ; j++){
                long long notPick = dp[i - 1][j];
                long long pick = 0;
                if(coins[i] <= j) pick = dp[i][j - coins[i]];
                dp[i][j] = pick + notPick;
            }
        }

        return dp[coins.size() - 1][amount];
    }
};