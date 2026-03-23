class Solution {
public:
    int f(int i , int buy , vector<int>& prices , vector<vector<int>> &dp){
        // base 
        // 1 - buy 
        // 0 - cannot buy
        int n = prices.size();
        if(i == n){
            return 0;
        }
        if(dp[i][buy] != -1) return dp[i][buy];
        if(buy){
            // take / not take
            return dp[i][buy] = max(-prices[i] + f(i + 1 , 0 , prices , dp) , f(i + 1 , 1 , prices , dp));    
        } 
        // deicde to sell / decide not to sell
        return dp[i][buy] = max(prices[i] + f(i + 1 , 1 , prices , dp) , f(i + 1 , 0 , prices , dp));
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp (n , vector<int> (2 , -1));
        return f(0 , 1 , prices , dp);
    }
};

tc = o(n x 2)
sc = o(n x 2) + o(n)