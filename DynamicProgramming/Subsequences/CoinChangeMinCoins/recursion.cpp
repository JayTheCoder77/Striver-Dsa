class Solution {
public:
    // slight change in infinite supply version of 
    // pick and not pick we actually stay at the same index even if we decide to pick
    int f(int ind , vector<int>& coins, int amount){

        if(ind == 0){
            if(amount % coins[ind] == 0) return amount / coins[ind];
            else return 1e9;
        }
        
        int notTake = 0 + f(ind - 1 , coins , amount);
        int take = INT_MAX;
        if(coins[ind] <= amount) take = 1 + f(ind , coins , amount - coins[ind]);

        return min(take , notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int ans = f(coins.size() - 1 , coins , amount);
        return (ans >= 1e9) ? -1 : ans;
    }
};

tc = exponential
sc = o(target)
