class Solution {
public:
    int f(int i , int buy , vector<int>& prices , vector<vector<vector<int>>> &dp , int cap){
        // base 
        // 1 - buy 
        // 0 - cannot buy
        int n = prices.size();
        if(cap == 0) return 0;
        if(i == n){
            return 0;
        }
        if(dp[i][buy][cap] != -1) return dp[i][buy][cap];
        if(buy){
            // take / not take
            return dp[i][buy][cap] = max(-prices[i] + f(i + 1 , 0 , prices , dp , cap) , f(i + 1 , 1 , prices , dp , cap));    
        } 
        // deicde to sell / decide not to sell
        return dp[i][buy][cap] = max(prices[i] + f(i + 1 , 1 , prices , dp , cap-1) , f(i + 1 , 0 , prices , dp , cap));
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp (n , vector<vector<int>> (2 , vector<int> (3 ,-1)) );
        return f(0 , 1 , prices ,dp , 2);
    }
};

tc = o(n x 2 x 3)
sc = o(n x 2 x 3) + o(n)