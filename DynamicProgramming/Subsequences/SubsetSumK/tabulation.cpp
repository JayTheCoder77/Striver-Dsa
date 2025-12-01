class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int k) {
        int n = arr.size();
        if(n == 0) return k == 0;
        vector<vector<bool>> dp(n , vector<bool>(k + 1 , false));
        
        // base case
        for(int i = 0 ; i < n ; i++) dp[i][0] = true;
        if (arr[0] <= k) dp[0][arr[0]] = true;
        
        // nested loops
        
        for(int i = 1 ; i < n ; i++){
            for(int j = 1 ; j <= k ; j++){
                // j = target loop
                bool notTake = dp[i-1][j];
                bool take = false;
                if(j >= arr[i]) take = dp[i-1][j-arr[i]];
                dp[i][j] = take || notTake;
            }
        }
        return dp[n-1][k];
    }
};

tc = o(n x k)
sc = o(n x k)