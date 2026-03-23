class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp (n + 1 , vector<int> (2 , 0));

        dp[n][1] = 0;

        for(int i = n - 1 ; i >= 0 ; i--){
            for(int buy = 0 ; buy <= 1 ; buy++){
                int profit = 0;
                if(buy){
                    // take / not take
                    dp[i][buy] = max(-prices[i] + dp[i + 1][0] , dp[i + 1][1]);    
                } 
                // deicde to sell / decide not to sell
                else dp[i][buy] = max(prices[i] + dp[i + 1][1] , dp[i + 1][0]);
            }
        }   
        return dp[0][1];
    }
};

tc = o(n x 2)
sc = o(n x 2)