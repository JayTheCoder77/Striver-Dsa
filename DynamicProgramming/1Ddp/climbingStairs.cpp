class Solution {
public:
    int climbStairs(int n) {
        
        dp space optimization (best)
        if(n == 0 || n == 1) return 1;
        
        int prev = 1;
        int prev2 = 1;
        for(int i = 2 ; i <= n ; i++){
            int curi = prev + prev2;
            prev2 = prev;
            prev = curi;
        }
        return prev;
    }
    
};
---------------------------------------------------------
        find number of ways to reach 0 - n
        1 convert to indexes -> 2. do all possible stuffs on those indexes


        so basically this is fibonacci
        ----------------------------------
        1 recursion - brute
        if(n == 0 || n == 1) return 1;
        return climbStairs(n - 1) + climbStairs(n - 2);

        -----------------------------------
        dp - tabulation
        if(n == 0 || n == 1) return 1;

        vector<int> dp(n + 1);
        dp[0] = dp[1] = 1;

        for (int i = 2; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];

        -----------------------------------

        -----------------------------------
        dp memoization
        int dp(int n , unordered_map<int,int> &memo){
            if (n == 0 || n == 1) {
                return 1;
            }
            if(memo.find(n) == memo.end()) memo[n] = dp(n-1 , memo) + dp(n-2, memo);
            return memo[n];
        }
        int climbStairs(int n){
            // this is the main function
            unordered_map<int,int> memo;
            return dp(n , memo);
        }