class Solution {
  public:
    bool equalPartition(vector<int>& arr) {
        int sum = 0 , n = arr.size();
        for(int i = 0 ; i < n ; i++) sum += arr[i];
        if(sum % 2 != 0) return false;
        int k = sum / 2;
        vector<vector<bool>> dp(n , vector<bool> (k + 1 , false));
        
        for(int i = 0 ; i < n ; i++) dp[i][0] = true;
        if (arr[0] <= k) dp[0][arr[0]] = true;
        
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