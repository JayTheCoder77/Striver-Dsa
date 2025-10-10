class Solution {
  public:
    int minCost(vector<int>& height) {
        int n = height.size();
        vector<int> dp(n+1 , -1);
        dp[0] = 0;
        int left = 0 , right = INT_MAX;
        for(int i = 1 ; i < n ; i++){
            left = dp[i-1] + abs(height[i] - height[i-1]);
            if(i > 1) right = dp[i-2] + abs(height[i] - height[i-2]);
            
            dp[i] = min(left , right);
        }
        return dp[n-1];
    }
};