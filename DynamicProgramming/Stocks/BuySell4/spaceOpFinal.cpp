// recursion 

class Solution {
public:
    int f(int ind , int tranNo , vector<int>& prices , int n , int k ){
        if(ind == n || tranNo == 2 * k) return 0;

        if(tranNo % 2 == 0) // buy
        {
            return max(-prices[ind] + f(ind + 1 , tranNo + 1 , prices , n , k) , f(ind + 1 , tranNo , prices , n , k));
        }
        return max(prices[ind] + f(ind + 1 , tranNo + 1 , prices , n , k) , f(ind + 1 , tranNo , prices , n , k));
    }
    int maxProfit(int k, vector<int>& prices) { 
        return f(0 , 0 , prices , prices.size() , k);
    }
};


// memoization

class Solution {
public:
    int f(int ind , int tranNo , vector<int>& prices , int n , int k , vector<vector<int>> &dp){
        if(ind == n || tranNo == 2 * k) return 0;
        if(dp[ind][tranNo] != -1) return dp[ind][tranNo];
        if(tranNo % 2 == 0) // buy
        {
            return max(-prices[ind] + f(ind + 1 , tranNo + 1 , prices , n , k , dp) , f(ind + 1 , tranNo , prices , n , k , dp));
        }
        return max(prices[ind] + f(ind + 1 , tranNo + 1 , prices , n , k , dp) , f(ind + 1 , tranNo , prices , n , k , dp));
    }
    int maxProfit(int k, vector<int>& prices) { 
        vector<vector<int>> dp (prices.size() , vector<int> (2 * k , -1));
        return f(0 , 0 , prices , prices.size() , k , dp);
    }
};

// tabulation

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) { 
        int n = prices.size();
        vector<vector<int>> dp (n + 1 , vector<int> (2 * k + 1 , 0));

        for(int ind = n-1 ; ind >= 0 ; ind--){
           for(int tranNo = 2*k-1 ; tranNo >= 0 ; tranNo--){
                if(tranNo % 2 == 0) // buy
                {
                    dp[ind][tranNo] =  max(-prices[ind] + dp[ind + 1][tranNo + 1] , dp[ind + 1][tranNo]);
                }
                else dp[ind][tranNo] = max(prices[ind] + dp[ind + 1][tranNo + 1] ,  dp[ind + 1][tranNo]);
            } 
        }
        return dp[0][0];
    }
};

// space optimized

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) { 
        int n = prices.size();
        vector<int> after (2 * k + 1 , 0);
        vector<int> cur (2 * k + 1 , 0);

        for(int ind = n-1 ; ind >= 0 ; ind--){
           for(int tranNo = 2*k-1 ; tranNo >= 0 ; tranNo--){
                if(tranNo % 2 == 0) // buy
                {
                    cur[tranNo] =  max(-prices[ind] + after[tranNo + 1] , after[tranNo]);
                }
                else cur[tranNo] = max(prices[ind] + after[tranNo + 1] ,  after[tranNo]);
            } 
            after = cur;
        }
        return after[0];
    }
};