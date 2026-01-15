class Solution {
public:
    // slight change in infinite supply version of 
    // pick and not pick we actually stay at the same index even if we decide to pick
    int coinChange(vector<int>& coins, int amount) {
        vector<int> prev (amount + 1 , 0) , cur (amount + 1 , 0);
        for(int j = 0 ; j < amount + 1 ; j++){
            if(j % coins[0] == 0) prev[j] = j / coins[0];
            else prev[j] = 1e9;
        }
        for(int i = 1 ; i < coins.size() ; i++){    
            for(int j = 0 ; j < amount + 1 ; j++){
                int notTake = 0 + prev[j];
                int take = INT_MAX;
                if(coins[i] <= j) take = 1 + cur[j - coins[i]]; 
                cur[j] = min(take , notTake);
            }
            prev = cur;
        }
        int ans = prev[amount];
        if(ans >= 1e9) return -1;
        return ans;
    }
};